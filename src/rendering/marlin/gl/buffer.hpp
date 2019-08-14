//
//  buffer.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/10/19.
//

#ifndef MARLIN_BUFFER_HPP
#define MARLIN_BUFFER_HPP

#include <math/math.hpp>

#import <OpenGL/gl3.h>

#include <vector>

namespace marlin
{
    
enum class BufferType {
    Vertex = 0,
    Index = 1,
    Count = 2,
};
    
class ArrayBuffer
{
public:
    
    ArrayBuffer();
    explicit ArrayBuffer( BufferType i_type );
    
    void load();
    void unload();
    
    void bind();
    void unbind();
    
    void bufferData( GLsizeiptr i_size, const void* i_data );

    template < class T, class A >
    void bufferSubData( GLintptr* io_offset, const std::vector< T, A > &i_data );
    
    template < class T >
    void enableVertexAttribute( size_t i_index, size_t i_size, GLintptr* io_offset );
    
    template < class T, class A >
    void bufferVertexData( size_t i_index, size_t i_size, GLintptr* io_offset, const std::vector< T, A > &i_data );
    
private:
    
    bool m_loaded;
    GLenum m_target;
    GLuint m_handle;
};

} // namespace marlin

#include "buffer.tpp"

#endif /* MARLIN_BUFFER_HPP */
