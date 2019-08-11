//
//  meshUtilities.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/11/19.
//

#include "meshUtilities.hpp"

namespace marlin
{

namespace utils
{
    
bool convertMeshToGlArrays( const MeshGeom &i_geom,
                            std::vector< GLfloat > &o_points,
                            std::vector< GLfloat > &o_normals,
                            std::vector< GLfloat > &o_colors,
                            std::vector< GLfloat > &o_texCoords,
                            std::vector< GLuint > &o_indices )
{
    bool success = true;
    const size_t numPoints = i_geom.points.size();
    
    std::vector< GLfloat > inPoints;
    inPoints.reserve( 3 * numPoints );
    
    for ( const vec3f &point : i_geom.points )
    {
        inPoints.push_back( static_cast< GLfloat >( point[ 0 ] ) );
        inPoints.push_back( static_cast< GLfloat >( point[ 1 ] ) );
        inPoints.push_back( static_cast< GLfloat >( point[ 2 ] ) );
    }
    
    o_points = inPoints;
    
    // Make normals same size as points
    o_normals.clear();
    o_normals.resize( numPoints );
    std::fill( o_normals.begin(), o_normals.end(), GLfloat( 0.0 ) );
    
    o_indices.clear();
    
    // Tessellate polygons
    // For example:
    // FaceVertexCount 6
    // Indices 1, 2, 3, 4, 5, 6
    // Triangulates into:
    // Indices 1, 2, 3, 1, 3, 4, 1, 4, 5, 1, 5, 6
    const std::vector< size_t > &indices = i_geom.faceVertexIndices;
    
    // The index into the indices vector of the current face
    size_t faceIdx = 0;
    
    for ( size_t faceVertexCount : i_geom.faceVertexCounts )
    {
        // The last index from the previous triangle which will be
        // the middle index of the next triangle
        size_t lastIdx = faceIdx + 1;
        
        for ( size_t faceVertex = 2; faceVertex < faceVertexCount; faceVertex++ )
        {
            o_indices.push_back( static_cast< GLuint >( indices[ faceIdx     ] ) );
            o_indices.push_back( static_cast< GLuint >( indices[ lastIdx     ] ) );
            o_indices.push_back( static_cast< GLuint >( indices[ lastIdx + 1 ] ) );
            
            lastIdx++;
        }
        
        faceIdx += faceVertexCount;
    }
    
    // Compute smooth normals
    for ( size_t faceIdx = 0; faceIdx < o_indices.size(); faceIdx += 3 )
    {
        GLuint i0 = o_indices[ faceIdx     ];
        GLuint i1 = o_indices[ faceIdx + 1 ];
        GLuint i2 = o_indices[ faceIdx + 2 ];
        
        vec3< GLfloat > v1( o_points[ 3 * i0 ], o_points[ 3 * i0 + 1 ], o_points[ 3 * i0 + 2 ] );
        vec3< GLfloat > v2( o_points[ 3 * i1 ], o_points[ 3 * i1 + 1 ], o_points[ 3 * i1 + 2 ] );
        vec3< GLfloat > v3( o_points[ 3 * i2 ], o_points[ 3 * i2 + 1 ], o_points[ 3 * i2 + 2 ] );
        
        vec3< GLfloat > l1 = v1 - v2;
        vec3< GLfloat > l2 = v3 - v2;
        
        vec3< GLfloat > n = -glm::normalize( glm::cross( l1, l2 ) );
        
        o_normals[ 3 * i0     ] += n[ 0 ];
        o_normals[ 3 * i0 + 1 ] += n[ 1 ];
        o_normals[ 3 * i0 + 2 ] += n[ 2 ];
        
        o_normals[ 3 * i1     ] += n[ 0 ];
        o_normals[ 3 * i1 + 1 ] += n[ 1 ];
        o_normals[ 3 * i2 + 2 ] += n[ 2 ];
        
        o_normals[ 3 * i2     ] += n[ 0 ];
        o_normals[ 3 * i2 + 1 ] += n[ 1 ];
        o_normals[ 3 * i2 + 2 ] += n[ 2 ];
    }
    
    // Normalize normals
    for ( size_t normalIdx = 0; normalIdx < o_normals.size(); normalIdx += 3 )
    {
        vec3< GLfloat > n( o_normals[ normalIdx ], o_normals[ normalIdx + 1 ], o_normals[ normalIdx + 2 ] );
        vec3< GLfloat > normalized = glm::normalize( n );
        
        o_normals[ normalIdx     ] = normalized.x;
        o_normals[ normalIdx + 1 ] = normalized.y;
        o_normals[ normalIdx + 2 ] = normalized.z;
    }
    
    // Use the polygon color if there are the correct amount, otherwise use the first color
    vec4f firstColor = i_geom.colors.empty() ? vec4f( 1.0 ) : i_geom.colors[ 0 ];
    bool usePolyColor = i_geom.colors.size() == numPoints;
    
    for ( size_t i = 0; i < numPoints; i++ )
    {
        vec4f currentColor = usePolyColor ? i_geom.colors[ i ] : firstColor;
        
        o_colors.push_back( static_cast< GLfloat >( currentColor[ 0 ] ) );
        o_colors.push_back( static_cast< GLfloat >( currentColor[ 1 ] ) );
        o_colors.push_back( static_cast< GLfloat >( currentColor[ 2 ] ) );
        o_colors.push_back( static_cast< GLfloat >( currentColor[ 3 ] ) );
    }
    
    return success;
}
    
} // namespace utils
    
} // namespace marlin
