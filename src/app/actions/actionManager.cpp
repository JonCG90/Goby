//
//  actionManager.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#include "actionManager.hpp"

#include "cameraActions.hpp"
#include "shortcutManager.hpp"

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
    
bool ActionManager::handleEvent( QEvent* i_event )
{
    if ( i_event->type() == QEvent::KeyPress )
    {
        QKeyEvent* keyEvent = static_cast< QKeyEvent* >( i_event );
        const int key = keyEvent->key();
    
        std::string actionID;
        if ( ShortcutManager::sharedManager().getShortcut( static_cast< Qt::Key >( key ), actionID ) )
        {
            ActionPtr action = getAction( actionID );
            if ( action != nullptr )
            {
                const ActionContext context;
                action->execute( context );
                return true;
            }
        }
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
