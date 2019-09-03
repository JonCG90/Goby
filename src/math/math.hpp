//
//  math.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/7/19.
//

#ifndef MATH_HPP
#define MATH_HPP

#include "defs.hh"

template < typename T, typename U, typename V >
inline T clamp( T i_value, U i_lower, V i_upper )
{
    T lower = static_cast< T >( i_lower );
    T upper = static_cast< T >( i_upper );

    if ( i_value < lower )
    {
        return lower;
    }
    else if ( i_value > upper )
    {
        return upper;
    }
    else
    {
        return i_value;
    }
}

#endif /* MATH_HPP */
