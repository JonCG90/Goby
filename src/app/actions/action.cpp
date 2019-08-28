//
//  action.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#include "action.hpp"

namespace Goby
{
    
Action::Action( const std::string &i_identifier )
    : m_identifier( i_identifier )
{
}
    
std::string Action::getID() const
{
    return m_identifier;
}
    
TriggerAction::TriggerAction( const std::string &i_identifier )
    : Action( i_identifier )
{
}
    
ToggleAction::ToggleAction( const std::string &i_identifier )
    : Action( i_identifier )
{
}

    
} // namespace Goby
