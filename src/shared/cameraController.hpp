//
//  cameraController.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/15/19.
//

#ifndef CAMERACONTROLLER_HPP
#define CAMERACONTROLLER_HPP

#include <math/math.hpp>

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
    
    void update( double i_dx, double i_dy );

private:
    
    CameraContolType m_type;
    vec3d m_position;
    vec3d m_target;
};

#endif /* cameraController_hpp */
