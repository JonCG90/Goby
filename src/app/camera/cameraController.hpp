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
    
    void mouseStateChanged( bool i_isDown );
    
    void updateLookCoords( const vec2d &i_lookCoords );
    void setMoveDirection( const vec3d &i_direction );
    
    mat4d getView() const;

private:
    
    CameraContolType m_type;
    CameraControlPtr m_control;
    
    vec2d m_lookCoords;
    vec3d m_moveDirection;
    bool m_mouseDown;
    
    mat4d m_view;
    
private:
    
};
    
} // namespace Goby

#endif /* cameraController_hpp */
