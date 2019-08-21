#include "ui/usdRenderWindow.hpp"

#include <app/actions/actionManager.hpp>
#include <app/shortcuts/shortcutFilter.hpp>
#include <app/shortcuts/shortcutManager.hpp>

#include <QtGui/QGuiApplication>

#include <iostream>

void initGoby( QGuiApplication &app )
{
    // Install event filter
    Goby::ShortcutEventFilter* eventFilter = new Goby::ShortcutEventFilter( &app );
    app.installEventFilter( eventFilter );
    
    // Init action Manager
    Goby::ActionManager::sharedManager();
}

int main( int argc, char *argv[] )
{
    QGuiApplication app( argc, argv );
    
    initGoby( app );
    
    QSurfaceFormat format;
    format.setSamples( 16 );
    
    UsdRenderWindow window;
    window.setFormat( format );
    window.resize( 640, 480 );
    window.show();
    
    window.setAnimating( true );
    
    return app.exec();
}
