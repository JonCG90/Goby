//
//  action.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#ifndef GOBY_ACTION_HPP
#define GOBY_ACTION_HPP

#include <iostream>

namespace Goby
{
    
struct ActionContext
{
public:
    
    ActionContext() = default;
    virtual ~ActionContext() = default;
};
    
class Action
{
public:
    
    Action() = delete;
    explicit Action( const std::string &i_identifier );
    virtual ~Action() = default;
    
    virtual std::string getName() const = 0;
    virtual void execute( const ActionContext &i_context ) = 0;

private:
    
    std::string m_identifier;
};
    
using ActionPtr = std::shared_ptr< Action >;
    
} // namespace Goby

#endif /* GOBY_ACTION_HPP */
