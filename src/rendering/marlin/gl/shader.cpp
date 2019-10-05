//
//  shader.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/11/19.
//

#include "shader.hpp"

#include <vector>

namespace marlin
{

void compileShader( const std::string &i_shaderSrc, const GLuint i_shaderId )
{
    const GLchar *shaderSrc = i_shaderSrc.c_str();
    glShaderSource( i_shaderId, 1, &shaderSrc, nullptr );
    
    // Compile Shader
    glCompileShader( i_shaderId );
    
    GLint success;
    GLchar infoLog[ 512 ];
    
    glGetShaderiv( i_shaderId, GL_COMPILE_STATUS, &success );
    if( !success )
    {
        glGetShaderInfoLog( i_shaderId, 512, NULL, infoLog );
        std::cout << "Warning: Shader compilation error:\n" << infoLog << std::endl;
    };
}
    
GLuint createShader( const std::string &i_shaderSource, const GLenum i_shaderType )
{
    const GLuint shaderId = glCreateShader( i_shaderType );
    compileShader( i_shaderSource, shaderId );
        
    return shaderId;
}
    
void linkShaders( const GLuint i_shaderProgram, const std::vector< GLuint> &i_shaders )
{
    // Attach shaders to program
    for ( const GLuint shader : i_shaders )
    {
        glAttachShader( i_shaderProgram, shader );
    }
    
    // Link shaders
    glLinkProgram( i_shaderProgram );
    
    GLint success = true;
    GLchar infoLog[ 512 ];
    
    glGetShaderiv( i_shaderProgram, GL_LINK_STATUS, &success );
    if( !success )
    {
        glGetShaderInfoLog( i_shaderProgram, 512, NULL, infoLog );
        std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    };
}
    
Shader::Shader()
    : m_loaded( false )
    , m_handle( 0 )
{
}
    
void Shader::load()
{
    if ( m_loaded )
    {
        return;
    }
    
    const GLuint vertexHandle = createShader( m_vertexSource, GL_VERTEX_SHADER );
    const GLuint fragmentHandle = createShader( m_fragmentSource, GL_FRAGMENT_SHADER );
    
    m_handle = glCreateProgram();
    linkShaders( m_handle, { vertexHandle, fragmentHandle } );

    // Delete shaders
    glDeleteShader( vertexHandle );
    glDeleteShader( fragmentHandle );
}
    
void Shader::unload()
{
    if ( !m_loaded )
    {
        return;
    }
    
    glDeleteProgram( m_handle );
    m_handle = 0;
}
    
void Shader::bind()
{
    glUseProgram( m_handle );
}

void Shader::unbind()
{
    glUseProgram( 0 );
}
    
void Shader::setShaderSource( const std::string &i_vertexSource, const std::string &i_fragmentSource )
{
    m_vertexSource = i_vertexSource;
    m_fragmentSource = i_fragmentSource;
}
    
void Shader::setBool( const std::string &i_param, bool i_value )
{
    GLint location;
    if ( getUniformLocation( i_param, location ) )
    {
        glUniform1i( location, static_cast< GLint>( i_value ) );
    }
}
    
void Shader::setInt( const std::string &i_param, int i_value )
{
    GLint location;
    if ( getUniformLocation( i_param, location ) )
    {
        glUniform1i( location, static_cast< GLint>( i_value ) );
    }
}

void Shader::setFloat( const std::string &i_param, float i_value )
{
    GLint location;
    if ( getUniformLocation( i_param, location ) )
    {
        glUniform1f( location, static_cast< GLfloat >( i_value ) );
    }
}

void Shader::setVec2f( const std::string &i_param, vec2f i_value )
{
    GLint location;
    if ( getUniformLocation( i_param, location ) )
    {
        glUniform2f( location, static_cast< GLfloat >( i_value.x ),
                               static_cast< GLfloat >( i_value.y ) );
    }
}

void Shader::setVec3f( const std::string &i_param, vec3f i_value )
{
    GLint location;
    if ( getUniformLocation( i_param, location ) )
    {
        glUniform3f( location, static_cast< GLfloat >( i_value.x ),
                           static_cast< GLfloat >( i_value.y ),
                           static_cast< GLfloat >( i_value.z ) );
    }
}

void Shader::setVec4f( const std::string &i_param, vec4f i_value )
{
    GLint location;
    if ( getUniformLocation( i_param, location ) )
    {
        glUniform4f( location, static_cast< GLfloat >( i_value.x ),
                               static_cast< GLfloat >( i_value.y ),
                               static_cast< GLfloat >( i_value.z ),
                               static_cast< GLfloat >( i_value.w ) );
    }
}

void Shader::setMat4f( const std::string &i_param, mat4f i_value )
{
    GLint location;
    if ( getUniformLocation( i_param, location ) )
    {
        GLfloat matrix[ 16 ];
        
        for ( size_t col = 0; col < 4; col++ )
        {
            for ( size_t row = 0; row < 4; row++ )
            {
                matrix[ 4 * col + row ] = static_cast< GLfloat >( i_value[ col ][ row ] );
            }
        }
        
        glUniformMatrix4fv( location, 1, GL_FALSE, matrix );
    }
}
    
bool Shader::getUniformLocation( const std::string &i_param, GLint &o_location ) const
{
    o_location = glGetUniformLocation( m_handle, i_param.c_str() );
    
    if ( o_location == -1 )
    {
        std::cout << "Shader: Warning: Unable to find uniform location for : " << i_param << std::endl;
        return false;
    }
    
    return true;
}
    
} // namespace marlin
