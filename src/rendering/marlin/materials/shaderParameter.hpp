//
//  shaderParameter.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/14/19.
//

#ifndef MARLIN_SHADERPARAMETER_HPP
#define MARLIN_SHADERPARAMETER_HPP

#include <iostream>

namespace marlin
{
   
// Parameter type enum
enum class ShaderParameterType
{
    Bool,
    Int,
    Float,
    Double,
    Vec2f,
    Vec3f,
    Vec4f,
    Mat4x4f,
    Count,
};
  
class ShaderParameterValue;
    
template < class T >
class ShaderParameter;
    
using ShaderParameterPtr = std::shared_ptr< ShaderParameterValue >;
    
class ShaderParameterValue
{
public:
    
    ShaderParameterValue( const std::string &name );
    virtual ~ShaderParameterValue() = default;
    
    std::string getName() const;
    ShaderParameterType getType() const;
    
    template < typename T >
    static ShaderParameterPtr createParameter( const std::string &name, T value );
    
    template< typename T >
    const ShaderParameter< T >* getParameterAsType() const;
    
    template< typename T >
    T getAsType() const;
    
protected:
    
    std::string m_name;
    ShaderParameterType m_type;
};
    
template< typename T >
class ShaderParameter : public ShaderParameterValue
{
public:
    
    ShaderParameter() = default;
    ~ShaderParameter() = default;
    ShaderParameter( std::string name, T value );
    
    void setValue( T value );
    T getValue() const;
    
private:
    
    T m_value;
    
    void setType();
};
    
} // namespace marlin

// Templates
#include "shaderParameter.tpp"

#endif /* MARLIN_SHADERPARAMETER_HPP */
