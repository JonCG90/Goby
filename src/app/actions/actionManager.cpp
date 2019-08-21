//
//  actionManager.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#include "actionManager.hpp"

#include "cameraActions.hpp"

#include <app/shortcuts/shortcutManager.hpp>

#include <QKeyEvent>

namespace Goby
{
    
ActionManager &ActionManager::sharedManager()
{
    static ActionManager instance;
    return instance;
}
    
ActionManager::ActionManager()
{
    ShortcutManager &shortcutManager = ShortcutManager::sharedManager();

    ActionPtr cameraForward = std::make_shared< CameraMoveForwardAction >();
    registerAction( cameraForward );
    shortcutManager.registerShortcut( Qt::Key::Key_W, cameraForward->getID() );
}
    
bool ActionManager::executeAction( std::string i_actionID, ActionContextPtr i_context ) const
{
    ActionPtr action = getAction( i_actionID );
    if ( action != nullptr )
    {
        action->execute( i_context );
    }
    
    return false;
}

void ActionManager::registerAction( ActionPtr i_action )
{
    m_actions[ i_action->getID() ] = i_action;
}
    
ActionPtr ActionManager::getAction( const std::string &i_actionID ) const
{
    auto itr = m_actions.find( i_actionID );
    if ( itr != m_actions.end() )
    {
        return itr->second;
    }
    
    return nullptr;
}
    
} // namespace Goby
