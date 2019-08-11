//
//  mesh.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/10/19.
//

#ifndef MARLINE_MESH_HPP
#define MARLINE_MESH_HPP

#include "geometry.hpp"

#include "../gl/buffer.hpp"
#include "../gl/vertexArray.hpp"

#include <math/math.hpp>

namespace marlin
{

class Mesh
{
public:
    
    explicit Mesh( MeshGeom i_geom );
    
    void load();
    void unload();
    
    void update( MeshGeom i_geom );
    void render();
    
private:
    
    struct GeomData
    {
        std::vector< GLfloat > points;
        std::vector< GLfloat > normals;
        std::vector< GLfloat > colors;
        std::vector< GLfloat > texCoords;
        std::vector< GLuint > indices;
    };
    
    bool m_loaded;
    GeomData m_geom;
    
    ArrayBuffer m_vertexBuffer;
    ArrayBuffer m_indexBuffer;
    
    VertexArray m_vertexArray;
    
    size_t m_indexCount;

};
    
} // namespace marlin

#endif /* MARLINE_MESH_HPP */
