//
//  meshSchema.cpp
//  GraphicsEngine
//
//  Created by Jonathan Graham on 10/27/18.
//  Copyright © 2018 Jonathan Graham. All rights reserved.
//

#include "meshSchema.hpp"

#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usdImaging/usdImaging/gprimAdapter.h>

#include <glm/gtc/type_ptr.hpp>

using namespace pxr;

namespace coral
{
    
MeshSchema::MeshSchema( const Item &i_item )
    : m_mesh( i_item.getInternalPrim() )
{}

MeshPolygons MeshSchema::getPolygons() const
{
    const UsdGeomMesh &mesh = m_mesh;

    if ( !mesh )
    {
        return MeshPolygons();
    }
    
    VtVec3fArray pointData;
    VtVec3fArray normalData;
    VtVec4fArray colorData;
    VtIntArray faceVertexCounts;
    VtIntArray faceVertexIndices;
    
    UsdAttribute vertCountAttr = mesh.GetFaceVertexCountsAttr();
    UsdAttribute vertIndicesAttr = mesh.GetFaceVertexIndicesAttr();
    
    vertCountAttr.Get( &faceVertexCounts );
    vertIndicesAttr.Get( &faceVertexIndices );
    
    mesh.GetPointsAttr().Get( &pointData );

    if ( mesh.GetNormalsAttr().HasAuthoredValue() )
    {
        mesh.GetNormalsAttr().Get( &normalData );
    }

    std::vector< vec3f > points;
    points.reserve( pointData.size() / 3 );
    
    for ( const GfVec3f &point : pointData )
    {
        points.push_back( vec3f( point[0], point[ 1 ], point[ 2 ] ) );
    }
    
    std::vector< size_t > numFaceVertices;
    numFaceVertices.reserve( faceVertexCounts.size() );
    
    for ( int faceVertices : faceVertexCounts )
    {
        numFaceVertices.push_back( static_cast< size_t >( faceVertices ) );
    }
    
    std::vector< size_t > faceIndices;
    faceIndices.reserve( faceVertexIndices.size() );

    for ( int faceIndex : faceVertexIndices )
    {
        faceIndices.push_back( static_cast< size_t >( faceIndex ) );
    }
    
    VtValue colorAsVt;
    std::vector< vec4f > colors;

    if ( UsdImagingGprimAdapter::GetColor( mesh.GetPrim(), UsdTimeCode::Default(), nullptr, &colorAsVt ) )
    {
        const VtVec3fArray &colorData = colorAsVt.Get< VtVec3fArray >();
        
        for ( const GfVec3f &color : colorData )
        {
            colors.push_back( vec4f( color[0], color[ 1 ], color[ 2 ], 1.0 ) );
        }
    }
     
    MeshPolygons polygons;
    polygons.points = points;
    polygons.colors = colors;
    polygons.faceVertexCounts = numFaceVertices;
    polygons.faceVertexIndices = faceIndices;
    
    return polygons;
}
    
mat4f MeshSchema::getWorldMatrix() const
{
    const GfMatrix4d localToWorld = m_mesh.ComputeLocalToWorldTransform( UsdTimeCode::Default() );
    const double* values = localToWorld.GetArray();
    
    return glm::make_mat4( values );
}

void setPolygons( const MeshPolygons &i_polygons )
{
    if ( i_polygons.points.empty() )
    {
        return;
    }
    
    SdfLayerRefPtr layer = SdfLayer::CreateAnonymous( ".usda" );
    UsdStageRefPtr stage = UsdStage::Open( layer );
    
    GfRange3f extent;
    VtVec3fArray vertices;
    for ( const vec3f &vertex : i_polygons.points )
    {
        GfVec3f point( vertex.x, vertex.y, vertex.z );
        vertices.push_back( point );
        extent.UnionWith( point );
    }
    
    VtVec3fArray extentArray( 2 );
    extentArray[ 0 ] = extent.GetMin();
    extentArray[ 1 ] = extent.GetMax();

    VtVec3fArray normals;
    for ( const vec3f &normal : i_polygons.normals )
    {
        normals.push_back( GfVec3f( normal.x, normal.y, normal.z ) );
    }

    VtIntArray faceVertexCounts;
    for ( size_t faceVertexCount : i_polygons.faceVertexCounts )
    {
        faceVertexCounts.push_back( static_cast< int >( faceVertexCount ) );
    }

    VtIntArray faceVertexIndices;
    for ( size_t faceVertexIndex : i_polygons.faceVertexIndices )
    {
        faceVertexIndices.push_back( static_cast< int >( faceVertexIndex ) );
    }

    // Create a mesh for the group.
    const std::string name = !i_polygons.name.empty() ? i_polygons.name : "mesh01";
    const std::string path = "/" + name;
    
    UsdGeomMesh mesh = UsdGeomMesh::Define( stage, SdfPath( path ) );
    
    mesh.GetPointsAttr().Set( vertices );

    if ( !normals.empty() )
    {
        mesh.GetNormalsAttr().Set( normals );
    }

    mesh.GetFaceVertexCountsAttr().Set( faceVertexCounts );
    mesh.GetFaceVertexIndicesAttr().Set(faceVertexIndices );

    // Set extent.
    mesh.GetExtentAttr().Set( extentArray);
}
    
} // namespace coral
