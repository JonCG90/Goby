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
    , m_mouseDown( false )
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
    
    // Normalize move direction
    vec3d moveDirection = m_moveDirection;
    if ( moveDirection != vec3d( 0.0 ) )
    {
        moveDirection = glm::normalize( moveDirection );
    }
    
    switch ( m_type ) {
        case CameraContolType::Fly:
        {
            m_control->updateMoveInput( moveDirection, dt );
            m_control->updateLookInput( m_lookCoords, m_mouseDown, dt );
            break;
        }
        case CameraContolType::Orbit:
            
            break;
        default:
            break;
    }
}
    
void CameraController::mouseStateChanged( bool i_isDown )
{
    m_mouseDown = i_isDown;
}
    
void CameraController::setMoveDirection( const vec3d &i_direction )
{
    m_moveDirection += i_direction;
}

void CameraController::updateLookCoords( const vec2d &i_lookCoords )
{
    m_lookCoords = i_lookCoords;
}
    
mat4d CameraController::getView() const
{
    return m_control->getViewMatrix();
}
    
} // namespace Goby
