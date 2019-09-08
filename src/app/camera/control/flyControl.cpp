//
//  flyControl.cpp
//  Goby
//
//  Created by Jonathan Graham on 9/2/19.
//

#include "flyControl.hpp"

#include "glm/gtc/matrix_transform.hpp"

namespace Goby
{
    
FlyControl::FlyControl()
    : m_pitch( 0.0 )
    , m_yaw( -90.0 )
    , m_roll( 0.0 )
    , m_translateSensitivity( 0.5 )
    , m_rotateSensitivity( 3.0 )
    , m_mouseDown( false )
    , m_dirty( true )
{
}
    
void FlyControl::reset( const RenderCamera &i_camera )
{
    m_position = i_camera.position;
    m_direction = glm::normalize( i_camera.target - i_camera.position );
    m_up = i_camera.up;
    
    // TODO GET PITCH YAW AND ROLL
    m_roll = 0.0;
    
    m_dirty = true;
}
    
void FlyControl::updateMoveInput( const vec3d &i_moveInput, double dt )
{
    translate( i_moveInput * dt );
}

void FlyControl::updateLookInput( const vec2d &i_lookInput, bool i_mouseDown, double dt )
{
    if ( i_mouseDown )
    {
        vec2d delta( 0.0 );
        
        if ( m_mouseDown )
        {
            delta = ( i_lookInput - m_prevLookInput ) * dt;
            rotate( delta.y, delta.x, 0.0 );
        }
        
        m_prevLookInput = i_lookInput;
    }
    
    m_mouseDown = i_mouseDown;
}
    
void FlyControl::rotate( double i_pitch, double i_yaw, double i_roll )
{
    m_pitch += ( i_pitch * m_rotateSensitivity );
    m_yaw += ( i_yaw * m_rotateSensitivity );
    m_roll += ( i_roll * m_rotateSensitivity );

    m_pitch = clamp( m_pitch, -89.0, 89.0 );
        
    vec3d direction;
    
    const double pitchRad = glm::radians( m_pitch );
    const double yawRad = glm::radians( m_yaw );

    direction.x = cos( pitchRad ) * cos( yawRad );
    direction.y = sin( pitchRad );
    direction.z = cos( pitchRad ) * sin( yawRad );
    
    // Normalize
    direction = glm::normalize( direction );
        
    vec3d right = glm::cross( direction, vec3d( 0, 1, 0 ) );
    vec3d up = glm::normalize( glm::cross( right, direction ) );
    
    m_direction = direction;
    m_up = up;
    
    m_dirty = true;
}
    
void FlyControl::translate( const vec3d &i_translation )
{
    if ( i_translation == vec3d( 0.0 ) )
    {
        return;
    }
    
    // Generate camera basis vectors
    const vec3d x = glm::cross( m_direction, m_up );
    const vec3d &y = m_up;
    const vec3d &z = m_direction;
    
    // Transformation matrix to change basis
    const mat4d basis( x.x, x.y, x.z, 0,
                       y.x, y.y, y.z, 0,
                       z.x, z.y, z.z, 0,
                       0,   0,   0,   1 );
    
    vec4d translateCamera( i_translation, 0 );
    vec4d translateGlobal = basis * translateCamera;
    
    m_position += ( m_translateSensitivity * vec3d( translateGlobal.x, translateGlobal.y, translateGlobal.z ) );
    m_dirty = true;
}
    
mat4d FlyControl::getViewMatrix()
{
    // Update matrix if dirty
    if ( m_dirty )
    {
        m_view = glm::lookAt( m_position, m_position + m_direction, vec3d( 0, 1, 0 ) );
        m_dirty = false;
    }
    
    return m_view;
}
    
} // namespace Goby
