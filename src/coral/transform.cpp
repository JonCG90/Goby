//
//  transform.cpp
//  Goby
//
//  Created by Jonathan Graham on 4/11/19.
//  Copyright © 2019 Jonathan Graham. All rights reserved.
//

#include "transform.hpp"

#include <vector>

namespace coral
{
    
//Transform::Transform()
//{
//    reset();
//}
//    
//void Transform::setTranslate( const vec3d &i_translate )
//{
//    m_components[ 0 ] = i_translate;
//}
//    
//vec3d Transform::getTranslate() const
//{
//    return m_components[ 0 ];
//}
//
//void Transform::setRotate( const vec3d &i_rotate )
//{
//    m_components[ 1 ] = i_rotate;
//}
//    
//vec3d Transform::getRotate() const
//{
//    return m_components[ 1 ];
//}
//    
//void Transform::setScale( const vec3d &i_scale )
//{
//    m_components[ 2 ] = i_scale;
//}
//    
//vec3d Transform::getScale() const
//{
//    return m_components[ 2 ];
//}
//    
//void Transform::setPivot( const vec3d &i_pivot )
//{
//    m_pivot = i_pivot;
//}
//    
//vec3d Transform::getPivot() const
//{
//    return m_pivot;
//}
//    
//mat4d Transform::getMatrix() const
//{
//    mat4d matrix = mat4d( 1.0 );
//    
//    matrix = glm::translate( matrix, getTranslate() );
//    
//    const vec3d &pivot = getPivot();
//    matrix = glm::translate( matrix, -pivot );
//    
//    const vec3d &rotate = getRotate();
//    matrix = glm::rotate( matrix, rotate.x, vec3d( 1, 0, 0 ) );
//    matrix = glm::rotate( matrix, rotate.y, vec3d( 0, 1, 0 ) );
//    matrix = glm::rotate( matrix, rotate.z, vec3d( 0, 0, 1 ) );
//    
//    matrix = glm::translate( matrix, pivot );
//    
//    matrix = glm::scale( matrix, getScale() );
//    
//    return matrix;
//}
//    
//void Transform::reset()
//{
//    m_components[ 0 ] = vec3d( 0.0 );
//    m_components[ 1 ] = vec3d( 0.0 );
//    m_components[ 2 ] = vec3d( 1.0 );
//
//    m_pivot = vec3d( 0.0 );
//}
    
} // namespace coral
