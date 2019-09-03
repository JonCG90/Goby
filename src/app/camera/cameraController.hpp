//
//  cameraController.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/15/19.
//

#ifndef CAMERACONTROLLER_HPP
#define CAMERACONTROLLER_HPP

#include <app/camera/control/cameraControl.hpp>

#include <math/math.hpp>

namespace Goby
{

enum class CameraContolType
{
    Fly,
    Orbit,
    Count,
};

class CameraController
{
public:
    
    CameraController();
    ~CameraController() = default;
    
    void setType( CameraContolType i_type );
    
    void reset( const RenderCamera &i_camera );
    void update( double i_dt );
    
    void update( const vec2i &i_delta );
    void setMoveDirection( const vec3d &i_direction );
    
    mat4d getView() const;

private:
    
    CameraContolType m_type;
    CameraControlPtr m_control;
    
    vec2i m_delta;
    vec3d m_moveDirection;
    
    mat4d m_view;
    
private:
    
};
    
} // namespace Goby

#endif /* cameraController_hpp */
