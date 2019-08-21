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
    
class Action
{
public:
    
    Action() = delete;
    explicit Action( const std::string &i_identifier );
    virtual ~Action() = default;
    
    std::string getID() const;

    virtual std::string getName() const = 0;
    virtual void execute( const ActionContextPtr &i_context ) = 0;
    
private:
    
    std::string m_identifier;
};
    
} // namespace Goby

#endif /* GOBY_ACTION_HPP */
