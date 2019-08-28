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
    
    ActionPtr cameraBackward = std::make_shared< CameraMoveBackwardAction >();
    registerAction( cameraBackward );
    shortcutManager.registerShortcut( Qt::Key::Key_S, cameraBackward->getID() );
    
    ActionPtr cameraLeft = std::make_shared< CameraMoveLeftAction >();
    registerAction( cameraLeft );
    shortcutManager.registerShortcut( Qt::Key::Key_A, cameraLeft->getID() );
    
    ActionPtr cameraRight = std::make_shared< CameraMoveRightAction >();
    registerAction( cameraRight );
    shortcutManager.registerShortcut( Qt::Key::Key_D, cameraRight->getID() );
}
    
bool ActionManager::executeAction( const std::string &i_actionID, ActionContextPtr i_context, bool i_state )
{
    ActionPtr action = getAction( i_actionID );
    if ( action != nullptr )
    {
        TriggerActionPtr triggerAction = std::dynamic_pointer_cast< TriggerAction >( action );
        if ( triggerAction != nullptr )
        {
            triggerAction->execute( i_context );
            return true;
        }
        
        ToggleActionPtr toggleAction = std::dynamic_pointer_cast< ToggleAction >( action );
        if ( toggleAction != nullptr )
        {
            // See if the action is already toggled, if it is and we are in a off state, remove it
            if ( m_toggledActions.count( toggleAction ) )
            {
                if ( !i_state )
                {
                    toggleAction->execute( i_context, i_state );
                    m_toggledActions.erase( toggleAction );
                }
            }
            else if ( i_state )
            {
                m_toggledActions.insert( toggleAction );
                toggleAction->execute( i_context, i_state );
            }
            
            return true;
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
