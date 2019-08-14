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
    
    void setParameter( ShaderParameterPtr i_param );
    void bindParameters();
    
private:
    
    Shader m_shader;
    std::map< std::string, ShaderParameterPtr > m_parameters;
    
    void bindParameter( ShaderParameterPtr i_param );
};
    
} // namespace marlin

#endif /* MARLIN_MATERIAL_HPP */
