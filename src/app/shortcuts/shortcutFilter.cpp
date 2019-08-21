//
//  shortcutFilter.cpp
//  Goby
//
//  Created by Jonathan Graham on 8/20/19.
//

#include "shortcutFilter.hpp"

#include <app/actions/actionManager.hpp>
#include <app/shortcuts/shortcutReceiver.hpp>
#include <app/shortcuts/shortcutManager.hpp>

#include <QApplication>
#include <QEvent>
#include <QCursor>
#include <QKeyEvent>
#include <QWindow>

namespace Goby
{

ShortcutEventFilter::ShortcutEventFilter( QObject* i_parent )
: QObject( i_parent )
{
}

bool ShortcutEventFilter::eventFilter( QObject* i_obj, QEvent* i_event)
{
    if ( i_event->type() == QEvent::Type::KeyPress )
    {
        const QKeyEvent* keyEvent = static_cast< QKeyEvent* >( i_event );
        const Qt::Key key = static_cast< Qt::Key >( keyEvent->key() );
        
        QWindow *window = qApp->focusWindow();

        while ( window != nullptr )
        {
            ShortcutReceiver* shortcutReceiver = dynamic_cast< ShortcutReceiver* >( window );
            if ( shortcutReceiver != nullptr )
            {
                ActionContextPtr context = shortcutReceiver->getContext();
                std::string actionID;
                if ( ShortcutManager::sharedManager().getShortcut( key, actionID ) && context != nullptr )
                {
                    ActionManager::sharedManager().executeAction( actionID, context );
                    return true;
                }
            }

            window = window->parent();
        }
    }

    return QObject::eventFilter( i_obj, i_event );
}
    
} // namespace Goby

#include "moc_shortcutFilter.cpp"
