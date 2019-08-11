//
//  buffer.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/10/19.
//

#include "buffer.hpp"

namespace marlin
{
    
ArrayBuffer::ArrayBuffer()
    : ArrayBuffer( BufferType::Vertex )
{
}
    
ArrayBuffer::ArrayBuffer( BufferType i_type )
    : m_loaded( false )
    , m_handle( 0 )
{
    switch ( i_type ) {
        case BufferType::Vertex:
            m_target = GL_ARRAY_BUFFER;
            break;
        case BufferType::Index:
            m_target = GL_ELEMENT_ARRAY_BUFFER;
            break;
        default:
            m_target = GL_ARRAY_BUFFER;
            break;
    }
    
    glGenBuffers( 1, &m_handle );
}
    
void ArrayBuffer::load()
{
    if ( m_loaded )
    {
        unload();
    }
    
    glGenBuffers( 1, &m_handle );
}
    
void ArrayBuffer::bind()
{
    glBindBuffer( GL_ARRAY_BUFFER, m_handle );
}
    
void ArrayBuffer::unload()
{
    if ( !m_loaded )
    {
        return;
    }
    
    glDeleteBuffers( 1, &m_handle );
    m_target = 0;
}
    
void ArrayBuffer::bufferData( GLsizeiptr i_size, const void* i_data )
{
    glBufferData( m_target, i_size, static_cast< const GLvoid* >( i_data ), GL_STATIC_DRAW );
}
    
} // namespace marlin
