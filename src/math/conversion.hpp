//
//  conversion.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/19/19.
//

#ifndef conversion_hpp
#define conversion_hpp

#include "math.hpp"

template < class T, class U >
mat4< T > convertType( const mat4< U > &i_matrix )
{
    mat4< T > outMatrix;
    
    for ( int col = 0; col < 4; col++ )
    {
        const vec4< U > &inColumn = i_matrix[ col ];
        vec4< T > &outColumn = outMatrix[ col ];
        
        for ( int row = 0; row < 4; row++ )
        {
            outColumn[ row ] = static_cast< T >( inColumn[ row ] );
        }
    }
    
    return outMatrix;
}

#endif /* conversion_hpp */
