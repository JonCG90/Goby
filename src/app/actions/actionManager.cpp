//
//  actionManager.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/17/19.
//

#include "actionManager.hpp"

#include "cameraActions.hpp"

namespace Goby
{
    
ActionManager &ActionManager::sharedManager()
{
    static ActionManager instance;
    return instance;
}
    
ActionManager::ActionManager()
{
    ActionPtr cameraForward = std::make_shared< CameraMoveForwardAction >();
    registerAction( cameraForward, Qt::Key::Key_W );
}
    
void ActionManager::registerAction( ActionPtr i_action, Qt::Key i_key )
{
    m_actions[ i_key ] = i_action;
}
    
} // namespace Goby
