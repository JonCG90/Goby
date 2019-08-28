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
    
class CameraAction : public ToggleAction
{
public:
    
    CameraAction() = delete;
    explicit CameraAction( const std::string &i_identifier );
    ~CameraAction() override = default;
    
    std::string getName() const override = 0;
    void execute( const ActionContextPtr &i_context, bool i_state ) override;
    
protected:
    
    virtual void updateCameraController( CameraController* i_controller, bool i_state ) = 0;
};
    
class CameraMoveForwardAction : public CameraAction
{
public:
    
    CameraMoveForwardAction();
    ~CameraMoveForwardAction() = default;
    
    std::string getName() const override;
    
private:
    
    void updateCameraController( CameraController* i_controller, bool i_state ) override;

};
    
class CameraMoveBackwardAction : public CameraAction
{
public:
    
    CameraMoveBackwardAction();
    ~CameraMoveBackwardAction() = default;
    
    std::string getName() const override;
    
private:
    
    void updateCameraController( CameraController* i_controller, bool i_state ) override;
    
};

class CameraMoveLeftAction : public CameraAction
{
public:
    
    CameraMoveLeftAction();
    ~CameraMoveLeftAction() = default;
    
    std::string getName() const override;
    
private:
    
    void updateCameraController( CameraController* i_controller, bool i_state ) override;
    
};

class CameraMoveRightAction : public CameraAction
{
public:
    
    CameraMoveRightAction();
    ~CameraMoveRightAction() = default;
    
    std::string getName() const override;
    
private:
    
    void updateCameraController( CameraController* i_controller, bool i_state ) override;
    
};
    
} // namespace Goby

#endif /* GOBY_CAMERAACTIONS_HPP */
