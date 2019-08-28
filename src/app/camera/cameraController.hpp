//
//  cameraController.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/15/19.
//

#ifndef CAMERACONTROLLER_HPP
#define CAMERACONTROLLER_HPP

#include <math/math.hpp>

namespace Goby
{

enum class CameraContolType
{
    Fly,
    Orbit,
    Count,
};
    
struct RenderCamera
{
    vec3d position;
    vec3d target;
    vec3d up;
};

class CameraController
{
public:
    
    CameraController();
    ~CameraController() = default;
    
    void reset( const RenderCamera &i_camera );
    void update( double i_dt );
    
    void update( const vec2i &i_delta );
    void translate( const vec3d &i_direction, double i_dt );
    void setMoveDirection( const vec3d &i_direction );
    
    mat4d getView() const;

private:
    
    CameraContolType m_type;
    double m_lookSensitivity;
    double m_moveSensitivity;
    vec2i m_delta;
    
    vec3d m_moveDirection;
    
    vec3d m_position;
    vec3d m_target;
    vec3d m_up;
    
    mat4d m_view;
    
private:
    
};
    
} // namespace Goby

#endif /* cameraController_hpp */
