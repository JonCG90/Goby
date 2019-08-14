//
//  shader.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/11/19.
//

#ifndef MARLIN_SHADER_HPP
#define MARLIN_SHADER_HPP

#include <math/math.hpp>

#include <OpenGL/gl3.h>

#include <iostream>

namespace marlin
{
    
class Shader
{
public:
    
    Shader();
    ~Shader() = default;
    
    void load();
    void unload();
    
    void bind();
    void unbind();
    
    void setShaderSource( const std::string &i_vertexSource, const std::string &i_fragmentSource );
    
    void setBool( const std::string &i_param, bool i_value );
    void setInt( const std::string &i_param, int i_value );
    void setFloat( const std::string &i_param, float i_value );
    void setVec2f( const std::string &i_param, vec2f i_value );
    void setVec3f( const std::string &i_param, vec3f i_value );
    void setVec4f( const std::string &i_param, vec4f i_value );
    void setMat4f( const std::string &i_param, mat4f i_value );
    
private:
    
    bool m_loaded;
    GLuint m_handle;
    std::string m_vertexSource;
    std::string m_fragmentSource;
    
private:
    
    bool getUniformLocation( const std::string &i_param, GLint &o_location ) const;
    
};

} // namespace marlin
    
#endif /* MARLIN_SHADER_HPP */
