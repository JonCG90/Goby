//
//  cameraController.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/15/19.
//

#include "cameraController.hpp"

#include "glm/gtc/matrix_transform.hpp"

#include <algorithm>
#include <iostream>

namespace Goby
{

CameraController::CameraController()
    : m_type( CameraContolType::Fly )
    , m_lookSensitivity( 1.0 )
    , m_moveSensitivity( 0.1 )
{
}
    
void CameraController::reset( const RenderCamera &i_camera )
{
    m_position = i_camera.position;
    m_target = i_camera.target;
    m_up = i_camera.up;
}
    
void CameraController::update( double i_dt )
{
    const double dt = std::min( 100.0, i_dt );
    
    vec3d moveDirection = vec3d( 0.0, 0.0, 0.0 );
    if ( moveDirection != m_moveDirection )
    {
        moveDirection = glm::normalize( m_moveDirection );
    }
    
    switch ( m_type ) {
        case CameraContolType::Fly:
        {
            translate( moveDirection, i_dt );
            break;
        }
        case CameraContolType::Orbit:
            
            break;
        default:
            break;
    }
    
    m_delta = vec2i( 0.0 );
}
    
void CameraController::translate( const vec3d &i_direction, double i_dt )
{
    const vec3d translate = ( m_moveSensitivity * i_dt ) * i_direction;
    m_position += translate;
    m_target += translate;
}
    
void CameraController::setMoveDirection( const vec3d &i_direction )
{
    m_moveDirection += i_direction;
}

void CameraController::update( const vec2i &i_delta )
{
    m_delta += i_delta;
}
    
mat4d CameraController::getView() const
{
    return glm::lookAt( m_position, m_target, m_up );
}
    
} // namespace Goby
