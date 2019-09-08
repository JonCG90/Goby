//
//  cameraControl.hpp
//  Goby
//
//  Created by Jonathan Graham on 9/2/19.
//

#ifndef GOBY_CAMERACONTROL_HPP
#define GOBY_CAMERACONTROL_HPP

#include <math/math.hpp>

#include <memory>

namespace Goby
{
    
struct RenderCamera
{
    vec3d position;
    vec3d target;
    vec3d up;
};
    
class CameraControl
{
public:
    
    CameraControl() = default;
    virtual ~CameraControl() = default;
    
    virtual void reset( const RenderCamera &i_camera ) = 0;
    
    virtual void updateMoveInput( const vec3d &i_moveInput, double dt );
    virtual void updateLookInput( const vec2d &i_lookInput, bool i_mouseDown, double dt );
    
    virtual mat4d getViewMatrix() = 0;
};
    
using CameraControlPtr = std::shared_ptr< CameraControl >;
    
} // namespace Goby

#endif /* GOBY_CAMERACONTROL_HPP */
