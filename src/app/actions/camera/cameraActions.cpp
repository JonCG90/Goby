//
//  cameraActions.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#include "cameraActions.hpp"

namespace Goby
{
    
CameraAction::CameraAction( const std::string &i_identifier )
    : ToggleAction( i_identifier )
{
}

void CameraAction::execute( const ActionContextPtr &i_context, bool i_state )
{
    CameraActionContextPtr cameraContext = std::dynamic_pointer_cast< CameraActionContext >( i_context );
    if ( cameraContext  )
    {
        CameraController* controller = cameraContext->controller;
        if ( controller != nullptr )
        {
            updateCameraController( controller, i_state );
        }
    }
}
    
CameraMoveForwardAction::CameraMoveForwardAction()
    : CameraAction( "Camera:Forward" )
{
}
    
std::string CameraMoveForwardAction::getName() const
{
    return "Move Forward";
}
    
void CameraMoveForwardAction::updateCameraController( CameraController* i_controller, bool i_state )
{
    if ( i_state )
    {
        i_controller->setMoveDirection( vec3d( 0.0, 0.0, -1.0 ) );
    }
    else
    {
        i_controller->setMoveDirection( vec3d( 0.0, 0.0, 1.0 ) );
    }
}

CameraMoveBackwardAction::CameraMoveBackwardAction()
: CameraAction( "Camera:Backward" )
{
}

std::string CameraMoveBackwardAction::getName() const
{
    return "Move Backward";
}

void CameraMoveBackwardAction::updateCameraController( CameraController* i_controller, bool i_state )
{
    if ( i_state )
    {
        i_controller->setMoveDirection( vec3d( 0.0, 0.0, 1.0 ) );
    }
    else
    {
        i_controller->setMoveDirection( vec3d( 0.0, 0.0, -1.0 ) );
    }
}

CameraMoveLeftAction::CameraMoveLeftAction()
: CameraAction( "Camera:Left" )
{
}

std::string CameraMoveLeftAction::getName() const
{
    return "Move Left";
}

void CameraMoveLeftAction::updateCameraController( CameraController* i_controller, bool i_state )
{
    if ( i_state )
    {
        i_controller->setMoveDirection( vec3d( -1.0, 0.0, 0.0 ) );
    }
    else
    {
        i_controller->setMoveDirection( vec3d( 1.0, 0.0, 0.0 ) );
    }
}

CameraMoveRightAction::CameraMoveRightAction()
: CameraAction( "Camera:Right" )
{
}

std::string CameraMoveRightAction::getName() const
{
    return "Move Right";
}

void CameraMoveRightAction::updateCameraController( CameraController* i_controller, bool i_state )
{
    if ( i_state )
    {
        i_controller->setMoveDirection( vec3d( 1.0, 0.0, 0.0 ) );
    }
    else
    {
        i_controller->setMoveDirection( vec3d( -1.0, 0.0, 0.0 ) );
    }
}
    
} // namespace Goby
