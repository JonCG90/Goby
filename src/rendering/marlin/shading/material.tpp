//
//  material.tpp
//  Goby
//
//  Created by Jonathan Graham on 8/14/19.
//

#include "shaderParameter.hpp"

namespace marlin
{
    
template < typename T >
void Material::setParameter( const std::string &i_name, T i_value )
{
    ShaderParameterPtr parameter = ShaderParameterValue::createParameter( i_name, i_value );
    setParameter( parameter );
}
    
} // namespace marlin
