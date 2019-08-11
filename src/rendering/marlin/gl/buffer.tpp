//
//  buffer.tpp
//  Goby
//
//  Created by Jonathan Graham on 8/10/19.
//

namespace marlin
{

template < class T, class A >
void ArrayBuffer::bufferSubData( GLintptr* io_offset,
                                 const std::vector< T, A > &i_data )
{
    if ( !i_data.empty() )
    {
        const size_t bufferSize = sizeof( T ) * i_data.size();
        glBufferSubData( m_target, *io_offset, bufferSize, &( i_data[0] ) );
        *io_offset += bufferSize;
    }
}
    
template < class T >
void ArrayBuffer::enableVertexAttribute( size_t i_index,
                                         size_t i_size,
                                         GLintptr* io_offset )
{
    glEnableVertexAttribArray( i_index );
    glVertexAttribPointer( static_cast< GLuint >( i_index ),
                          static_cast< GLint >( i_size ),
                          GL_FLOAT,
                          GL_FALSE,
                          static_cast< GLsizei >( i_size * sizeof( T ) ),
                          reinterpret_cast< GLvoid * >( io_offset ) );
}
    
template < class T, class A >
void ArrayBuffer::bufferVertexData( size_t i_index,
                                    size_t i_size,
                                    GLintptr* io_offset,
                                    const std::vector< T, A > &i_data )
{
    enableVertexAttribute< T >( i_index, i_size, io_offset );
    bufferSubData( io_offset, i_data );
}

} // namespace marlin
