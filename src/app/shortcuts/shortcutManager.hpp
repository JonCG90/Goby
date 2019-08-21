//
//  shortcutManager.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/18/19.
//

#ifndef GOBY_SHORTCUTMANAGER_HPP
#define GOBY_SHORTCUTMANAGER_HPP

#include <QtCore/qnamespace.h>

#include <iostream>
#include <map>

namespace Goby
{
    
class ShortcutManager
{
public:
    
    static ShortcutManager &sharedManager();
    
    ShortcutManager() = default;
    ~ShortcutManager() = default;
    
    ShortcutManager( ShortcutManager const & ) = delete;
    void operator=( ShortcutManager const & ) = delete;
    
    void registerShortcut( Qt::Key i_key, const std::string &i_actionID );
    
    bool getShortcut( Qt::Key i_key, std::string &o_actionID ) const;

private:
    
    std::map< Qt::Key, std::string > m_shortcuts;
    
};
    
} // namespace Goby

#endif /* GOBY_SHORTCUTMANAGER_HPP */
