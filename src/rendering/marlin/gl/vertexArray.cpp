//
//  vertexArray.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/11/19.
//

#include "vertexArray.hpp"

namespace marlin
{
    
VertexArray::VertexArray()
    : m_handle( 0 )
{
}
    
void VertexArray::load()
{
    glGenVertexArrays( 1, &m_handle );
}
    
void VertexArray::unload()
{
    glDeleteVertexArrays( 1, &m_handle );
    m_handle = 0;
}
    
void VertexArray::bind()
{
    glBindVertexArray( m_handle );
}
    
void VertexArray::unbind()
{
    glBindVertexArray( 0 );
}
    
} // namespace marlin

