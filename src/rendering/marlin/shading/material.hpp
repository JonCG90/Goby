//
//  material.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/14/19.
//

#ifndef MARLIN_MATERIAL_HPP
#define MARLIN_MATERIAL_HPP

#include "shader.hpp"
#include "shaderParameter.hpp"

#include <map>

namespace marlin
{

class Material
{
public:
    
    Material() = default;
    ~Material() = default;
    
    void load();
    void unload();
    
    void update( const std::string &i_vertexSource, const std::string &i_fragmentSource );
    
    void bind();
    void unbind();
    
    template < typename T >
    void setParameter( const std::string &i_name, T i_value );
        
private:
    
    Shader m_shader;
    std::map< std::string, ShaderParameterPtr > m_parameters;
    
    void setParameter( ShaderParameterPtr i_param );
    
    void bindParameters();
    void bindParameter( ShaderParameterPtr i_param );
};
    
} // namespace marlin

#include "material.tpp"

#endif /* MARLIN_MATERIAL_HPP */
