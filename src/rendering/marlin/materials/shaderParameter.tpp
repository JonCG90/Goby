//
//  shaderParameter.tpp
//  Goby
//
//  Created by Jonathan Graham on 8/14/19.
//

#include <math/math.hpp>

namespace marlin
{

template < typename T >
ShaderParameterPtr ShaderParameterValue::createParameter( const std::string &name, T value )
{
    std::shared_ptr< ShaderParameter< T > > param = std::make_shared< T >( name, value );
    return param;
}

template< typename T >
const ShaderParameter< T >* ShaderParameterValue::getParameterAsType() const {
    
    const ShaderParameter< T >* typedParameter = dynamic_cast< const ShaderParameter< T >* >( this );
    return typedParameter;
}

template< typename T >
T ShaderParameterValue::getAsType() const {
    
    const ShaderParameter< T >* typedParameter = getParameterAsType< T >();
    return typedParameter->getValue();
}

template< typename T >
ShaderParameter< T >::ShaderParameter( std::string name, T value ) : ShaderParameterValue( name )
, m_value( value )
{
    setType();
}

template< typename T >
T ShaderParameter< T >::getValue() const {
    return m_value;
}

template< typename T >
void ShaderParameter< T >::setValue( T value ) {
    m_value = value;
}

template< typename T >
void ShaderParameter< T >::setType()
{
    m_type = ShaderParameterType::Count;
}
    
} // namespace marlin

