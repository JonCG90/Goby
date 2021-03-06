//
//  actionManager.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#ifndef GOBY_ACTIONMANAGER_HPP
#define GOBY_ACTIONMANAGER_HPP

#include "action.hpp"

#include <QtCore/qnamespace.h>
#include <QEvent>

#include <map>
#include <set>

namespace Goby
{
    
class ActionManager
{
public:
    
    static ActionManager &sharedManager();
    
    ActionManager();
    ~ActionManager() = default;
    
    ActionManager( ActionManager const & ) = delete;
    void operator=( ActionManager const & ) = delete;
    
    bool executeAction( const std::string &i_actionID, ActionContextPtr i_context, bool i_state );
    
private:
    
    std::map< std::string, ActionPtr > m_actions;
    std::set< ToggleActionPtr > m_toggledActions;
    
private:
    
    void registerAction( ActionPtr i_action );
    ActionPtr getAction( const std::string &i_actionID ) const;
};
    
} // namespace Goby

#endif /* GOBY_ACTIONMANAGER_HPP */
