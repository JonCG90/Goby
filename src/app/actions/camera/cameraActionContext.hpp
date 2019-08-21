//
//  cameraActionContext.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/21/19.
//

#ifndef cameraActionContext_hpp
#define cameraActionContext_hpp

#include <iostream>

#include <app/actions/actionContext.hpp>
#include <app/camera/cameraController.hpp>

namespace Goby
{

struct CameraActionContext;
using CameraActionContextPtr = std::shared_ptr< CameraActionContext >;

struct CameraActionContext : public ActionContext
{
public:
    
    explicit CameraActionContext( CameraController* i_controller );
    ~CameraActionContext() override = default;
    
    static CameraActionContextPtr context( CameraController* i_controller );
    
    CameraController* controller;
};
    
} // namespace Goby

#endif /* cameraActionContext_hpp */
