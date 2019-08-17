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
#include <QKeyEvent>

#include <map>

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
    
private:
    
    std::map< Qt::Key, ActionPtr > m_actions;
    
private:
    
    void registerAction( ActionPtr i_action, Qt::Key i_key );

};
    
} // namespace Goby

#endif /* GOBY_ACTIONMANAGER_HPP */
