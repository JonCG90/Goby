//
//  cameraActions.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#ifndef GOBY_CAMERAACTIONS_HPP
#define GOBY_CAMERAACTIONS_HPP

#include "action.hpp"

namespace Goby
{
    
class CameraAction : public Action
{
public:
    
    CameraAction() = delete;
    explicit CameraAction( const std::string &i_identifier );
    ~CameraAction() override = default;
    
    std::string getName() const override = 0;
    void execute( const ActionContext &i_context ) override;
    
};
    
class CameraMoveForwardAction : public CameraAction
{
public:
    
    CameraMoveForwardAction();
    std::string getName() const override;
    
};
    
} // namespace Goby

#endif /* GOBY_CAMERAACTIONS_HPP */
