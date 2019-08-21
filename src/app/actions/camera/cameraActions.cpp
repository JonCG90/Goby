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
    : Action( i_identifier )
{
}

void CameraAction::execute( const ActionContextPtr &i_context )
{
    CameraActionContextPtr cameraContext = std::dynamic_pointer_cast< CameraActionContext >( i_context );
    if ( cameraContext  )
    {
        CameraController* controller = cameraContext->controller;
        if ( controller != nullptr )
        {
            updateCameraController( controller );
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
    
void CameraMoveForwardAction::updateCameraController( CameraController* i_controller )
{
    i_controller->translate( vec3d( 0.0, 0.0, 1.0 ), 1.0 );
}
    
} // namespace Goby
