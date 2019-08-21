//
//  cameraActionContext.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/21/19.
//

#include "cameraActionContext.hpp"

namespace Goby
{

CameraActionContext::CameraActionContext( CameraController* i_controller )
: controller( i_controller )
{
}

CameraActionContextPtr CameraActionContext::context( CameraController* i_controller )
{
    return std::make_shared< CameraActionContext >( i_controller );
}

} // namespace Goby
