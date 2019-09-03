//
//  cameraController.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/15/19.
//

#include "cameraController.hpp"

#include <app/camera/control/flyControl.hpp>

#include "glm/gtc/matrix_transform.hpp"

#include <algorithm>
#include <iostream>

namespace Goby
{

CameraController::CameraController()
    : m_type( CameraContolType::Count )
{
    setType( CameraContolType::Fly );
}
    
void CameraController::setType( CameraContolType i_type )
{
    if ( m_type == i_type )
    {
        return;
    }
    
    switch ( i_type ) {
        case CameraContolType::Fly:
        {
            m_control = std::make_shared< FlyControl >();
            break;
        }
        default:
            break;
    }
    
    m_type = i_type;
}
    
void CameraController::reset( const RenderCamera &i_camera )
{
    m_control->reset( i_camera );
}
    
void CameraController::update( double i_dt )
{
    const double dt = std::min( 100.0, i_dt );
    
    vec3d moveDirection = vec3d( 0.0, 0.0, 0.0 );
    if ( moveDirection != m_moveDirection )
    {
        moveDirection = glm::normalize( m_moveDirection );
        
        switch ( m_type ) {
            case CameraContolType::Fly:
            {
                m_control->updateMove( moveDirection * dt );
                break;
            }
            case CameraContolType::Orbit:
                
                break;
            default:
                break;
        }
    }
    
    m_delta = vec2i( 0.0 );
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
    return m_control->getViewMatrix();
}
    
} // namespace Goby
