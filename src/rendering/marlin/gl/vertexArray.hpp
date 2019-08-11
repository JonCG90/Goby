//
//  vertexArray.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/11/19.
//

#ifndef MARLIN_VERTEXARRAY_HPP
#define MARLIN_VERTEXARRAY_HPP

#import <OpenGL/gl3.h>

namespace marlin
{
    
class VertexArray
{
public:
    
    VertexArray();
    ~VertexArray() = default;
    
    void load();
    void unload();
    
    void bind();
    void unbind();
    
private:
    
    GLuint m_handle;
};
    
} // namespace marlin

#endif /* MARLIN_VERTEXARRAY_HPP */
