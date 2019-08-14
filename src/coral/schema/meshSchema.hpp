//
//  meshSchema.hpp
//  GraphicsEngine
//
//  Created by Jonathan Graham on 10/27/18.
//  Copyright © 2018 Jonathan Graham. All rights reserved.
//

#ifndef CORAL_MESHSCHEMA_HPP
#define CORAL_MESHSCHEMA_HPP

#include <coral/item.hpp>

#include <math/math.hpp>

#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usdGeom/mesh.h>

#include <vector>

namespace coral
{

struct MeshPolygons
{
    std::string name;
    std::vector< vec3f > points;
    std::vector< vec3f > normals;
    std::vector< vec4f > colors;
    std::vector< vec2f > texCoords;
    
    std::vector< size_t > faceVertexCounts;
    std::vector< size_t > faceVertexIndices;
};
    
class MeshSchema
{
    
public:
    
    explicit MeshSchema( const Item &i_item );
    ~MeshSchema() = default;
    
    MeshPolygons getPolygons() const;
    mat4f getWorldMatrix() const;
    
    void setPolygons( const MeshPolygons &i_polygons );

    
private:
    
    pxr::UsdGeomMesh m_mesh;
};
    
} // namespace coral

#endif /* CORAL_MESHSCHEMA_HPP */
