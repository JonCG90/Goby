//
//  shaderParameter.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/14/19.
//

#include "shaderParameter.hpp"

namespace marlin
{
    
ShaderParameterValue::ShaderParameterValue( const std::string &name )
    : m_name( name )
    , m_type( ShaderParameterType::Count )
{
}

std::string ShaderParameterValue::getName() const
{
    return m_name;
}

ShaderParameterType ShaderParameterValue::getType() const
{
    return m_type;
}
    
template<>
void ShaderParameter< bool >::setType()
{
    m_type = ShaderParameterType::Bool;
}

template<>
void ShaderParameter< int >::setType()
{
    m_type = ShaderParameterType::Int;
}

template<>
void ShaderParameter< float >::setType()
{
    m_type = ShaderParameterType::Float;
}

template<>
void ShaderParameter< double >::setType()
{
    m_type = ShaderParameterType::Double;
}

template<>
void ShaderParameter< vec2f >::setType()
{
    m_type = ShaderParameterType::Vec2f;
}

template<>
void ShaderParameter< vec3f >::setType()
{
    m_type = ShaderParameterType::Vec3f;
}

template<>
void ShaderParameter< vec4f >::setType()
{
    m_type = ShaderParameterType::Vec4f;
}

template<>
void ShaderParameter< mat4f >::setType()
{
    m_type = ShaderParameterType::Mat4x4f;
}
    
} // namespace marlin
