//
//  mesh.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/10/19.
//

#include "mesh.hpp"

#include "meshUtilities.hpp"

#include <iostream>

namespace marlin
{
    
Mesh::Mesh( MeshGeom i_geom )
    : m_loaded( false )
{
    update( i_geom );
}
    
void Mesh::load()
{
    if ( m_loaded )
    {
        return;
    }
    
    const std::vector< GLfloat > &points = m_geom.points;
    const std::vector< GLfloat > &normals = m_geom.normals;
    const std::vector< GLfloat > &texCoords = m_geom.texCoords;
    const std::vector< GLfloat > &colors = m_geom.colors;
    const std::vector< GLuint >  &indices = m_geom.indices;
    
    m_vertexArray.load();
    m_vertexArray.bind();
    
    m_vertexBuffer = ArrayBuffer( BufferType::Vertex );
    m_vertexBuffer.load();
    m_vertexBuffer.bind();
    
    const size_t count = ( points.size()  +
                           normals.size() +
                           colors.size()  +
                           texCoords.size() );
    m_vertexBuffer.bufferData( static_cast< GLsizeiptr >( count * sizeof( GLfloat ) ), nullptr );
        
    GLintptr offset = 0;
    m_vertexBuffer.bufferVertexData( 0, 3, &offset, points );
    m_vertexBuffer.bufferVertexData( 2, 3, &offset, normals );
    m_vertexBuffer.bufferVertexData( 3, 2, &offset, texCoords );
    m_vertexBuffer.bufferVertexData( 4, 4, &offset, colors );
    
    m_indexBuffer = ArrayBuffer( BufferType::Index );
    m_indexBuffer.load();
    m_indexBuffer.bind();

    m_indexBuffer.bufferData( static_cast< GLsizeiptr >( indices.size() * sizeof( GLuint ) ), reinterpret_cast< const void* >( &indices ) );
    
    m_vertexArray.unbind();
    
    m_loaded = true;
}
    
void Mesh::unload()
{
    if ( !m_loaded )
    {
        return;
    }

    m_vertexArray.unload();
    m_vertexBuffer.unload();
    m_indexBuffer.unload();
    m_loaded = false;
}
    
void Mesh::update( MeshGeom i_geom )
{
    bool success = utils::convertMeshToGlArrays( i_geom,
                                                 m_geom.points,
                                                 m_geom.normals,
                                                 m_geom.colors,
                                                 m_geom.texCoords,
                                                 m_geom.indices );
    // Reset data
    if ( !success )
    {
        m_geom = GeomData();
    }
    
    m_indexCount = m_geom.indices.size();
}
    
void Mesh::render()
{
    if ( m_loaded && m_indexCount > 0 )
    {
        m_vertexArray.bind();
        glDrawElements( GL_TRIANGLES, static_cast< GLsizei >( m_indexCount ), GL_UNSIGNED_INT, 0 );
        m_vertexArray.unbind();
    }
}
    
} // namespace marlin
