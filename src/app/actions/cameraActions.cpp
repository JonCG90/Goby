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

void CameraAction::execute( const ActionContext &i_context )
{
}
    
CameraMoveForwardAction::CameraMoveForwardAction()
    : CameraAction( "Camera:Forward" )
{
}
    
std::string CameraMoveForwardAction::getName() const
{
    return "Move Forward";
}
    
} // namespace Goby
