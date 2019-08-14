//
//  material.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/14/19.
//

#include "material.hpp"

namespace marlin
{
    
void Material::setParameter( ShaderParameterPtr i_param )
{
    m_parameters[ i_param->getName() ] = i_param;
}
    
void Material::bindParameters()
{
    m_shader.bind();
    
    for ( const auto &pair : m_parameters )
    {
        bindParameter( pair.second );
    }
    
    m_shader.unbind();
}
    
void Material::bindParameter( ShaderParameterPtr i_param )
{
    const std::string name = i_param->getName();
    
    switch ( i_param->getType() ) {
            
        case ShaderParameterType::Bool:
        {
            bool value = i_param->getAsType< bool >();
            m_shader.setBool( name, value );
            break;
        }
        case ShaderParameterType::Int:
        {
            int value = i_param->getAsType< int >();
            m_shader.setInt( name, value );
            break;
        }
        case ShaderParameterType::Float:
        {
            float value = i_param->getAsType< float >();
            m_shader.setFloat( name, value );
            break;
        }
        case ShaderParameterType::Double:
        {
            float value = static_cast< float >( i_param->getAsType< double >() );
            m_shader.setFloat( name, value );
            break;
        }
        case ShaderParameterType::Vec2f:
        {
            vec2f value = i_param->getAsType< vec2f >();
            m_shader.setVec2f( name, value );
            break;
        }
        case ShaderParameterType::Vec3f:
        {
            vec3f value = i_param->getAsType< vec3f >();
            m_shader.setVec3f( name, value );
            break;
        }
        case ShaderParameterType::Vec4f:
        {
            vec4f value = i_param->getAsType<  vec4f >();
            m_shader.setVec4f( name, value );
            break;
        }
        case ShaderParameterType::Mat4x4f:
        {
            mat4f value = i_param->getAsType< mat4f >();
            m_shader.setMat4f( name, value );
            break;
        }

        default:
            break;
    }}
    
} // namespace marlin
