//
//  action.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#ifndef GOBY_ACTION_HPP
#define GOBY_ACTION_HPP

#include <iostream>

#include <app/actions/actionContext.hpp>

namespace Goby
{
    
class Action;
using ActionPtr = std::shared_ptr< Action >;
    
class TriggerAction;
using TriggerActionPtr = std::shared_ptr< TriggerAction >;
    
class ToggleAction;
using ToggleActionPtr = std::shared_ptr< ToggleAction >;
    
class Action
{
public:
    
    Action() = delete;
    explicit Action( const std::string &i_identifier );
    virtual ~Action() = default;
    
    std::string getID() const;

    virtual std::string getName() const = 0;
    
private:
    
    std::string m_identifier;
};
    
    class TriggerAction : public Action
{
public:
    
    TriggerAction() = delete;
    explicit TriggerAction( const std::string &i_identifier );
    ~TriggerAction() override = default;
    
    std::string getName() const override = 0;
    virtual void execute( const ActionContextPtr &i_context ) = 0;
};
    
class ToggleAction : public Action
{
public:
    
    ToggleAction() = delete;
    explicit ToggleAction( const std::string &i_identifier );
    ~ToggleAction() override = default;
    
    std::string getName() const override = 0;
    virtual void execute( const ActionContextPtr &i_context, bool i_state ) = 0;
};
    
} // namespace Goby

#endif /* GOBY_ACTION_HPP */
