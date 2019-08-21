//
//  cameraActions.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#ifndef GOBY_CAMERAACTIONS_HPP
#define GOBY_CAMERAACTIONS_HPP

#include <app/actions/action.hpp>
#include <app/actions/camera/cameraActionContext.hpp>
#include <app/camera/cameraController.hpp>

namespace Goby
{
    
class CameraAction : public Action
{
public:
    
    CameraAction() = delete;
    explicit CameraAction( const std::string &i_identifier );
    ~CameraAction() override = default;
    
    std::string getName() const override = 0;
    void execute( const ActionContextPtr &i_context ) override;
    
protected:
    
    virtual void updateCameraController( CameraController* i_controller ) = 0;
};
    
class CameraMoveForwardAction : public CameraAction
{
public:
    
    CameraMoveForwardAction();
    ~CameraMoveForwardAction() = default;
    
    std::string getName() const override;
    
private:
    
    void updateCameraController( CameraController* i_controller ) override;

};
    
} // namespace Goby

#endif /* GOBY_CAMERAACTIONS_HPP */
