//
//  cameraController.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/15/19.
//

#include "cameraController.hpp"

#include "glm/gtc/matrix_transform.hpp"

namespace Goby
{

CameraController::CameraController()
    : m_type( CameraContolType::Fly )
    , m_lookSensitivity( 1.0 )
    , m_moveSensitivity( 1.0 )
{
}
    
void CameraController::reset( const RenderCamera &i_camera )
{
    m_position = i_camera.position;
    m_target = i_camera.target;
    m_up = i_camera.up;
}
    
void CameraController::translate( const vec3d &i_direction, double i_dt )
{
    const vec3d tranlate = ( m_moveSensitivity * i_dt) * i_direction;
    m_position += tranlate;
    m_target += tranlate;
}

void CameraController::update( double i_dx, double i_dy, double i_dt )
{
    switch ( m_type ) {
        case CameraContolType::Fly:
            
            break;
        case CameraContolType::Orbit:
            
            break;
        default:
            break;
    }
}
    
mat4d CameraController::getView() const
{
    return glm::lookAt( m_position, m_target, m_up );
}
    
} // namespace Goby
