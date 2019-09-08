//
//  flyControl.hpp
//  Goby
//
//  Created by Jonathan Graham on 9/2/19.
//

#ifndef GOBY_FLYCONTROL_HPP
#define GOBY_FLYCONTROL_HPP

#include "cameraControl.hpp"

#include <math/math.hpp>

namespace Goby
{
    
class FlyControl : public CameraControl
{
public:
    
    FlyControl();
    ~FlyControl() override = default;
    
    void reset( const RenderCamera &i_camera ) override;
    
    void updateMoveInput( const vec3d &i_moveInput, double dt ) override;
    void updateLookInput( const vec2d &i_lookInput, bool i_mouseDown, double dt ) override;
        
    mat4d getViewMatrix() override;
    
private:
    
    double m_pitch = 0;
    double m_yaw = -90;
    double m_roll = 0;
    
    double m_translateSensitivity;
    double m_rotateSensitivity;
    
    vec3d m_position;
    vec3d m_direction;
    vec3d m_up;
    
    mat4d m_view;
    
    vec2d m_prevLookInput;
    bool m_mouseDown;
    bool m_dirty;
    
private:
    
    void rotate( double i_pitch, double i_yaw, double i_roll );
    void translate( const vec3d &i_translation );
    
};
    
} // namespace Goby

#endif /* GOBY_FLYCONTROL_HPP */
