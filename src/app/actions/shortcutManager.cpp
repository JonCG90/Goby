//
//  shortcutManager.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/18/19.
//

#include "shortcutManager.hpp"

namespace Goby
{
    
ShortcutManager &ShortcutManager::sharedManager()
{
    static ShortcutManager instance;
    return instance;
}
    
void ShortcutManager::registerShortcut( Qt::Key i_key, const std::string &i_actionID )
{
    m_shortcuts[ i_key ] = i_actionID;
}
    
bool ShortcutManager::getShortcut( Qt::Key i_key, std::string &o_actionID ) const
{
    const auto itr = m_shortcuts.find( i_key );
    if ( itr != m_shortcuts.end() )
    {
        o_actionID = itr->second;
        return true;
    }
    
    return false;
}
    
} // namespace Goby
