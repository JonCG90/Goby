#include "ui/usdRenderWindow.hpp"

#include <QtGui/QGuiApplication>

#include <iostream>

int main( int argc, char *argv[] )
{
    QGuiApplication app( argc, argv );
    
    QSurfaceFormat format;
    format.setSamples( 16 );
    
    UsdRenderWindow window;
    window.setFormat( format );
    window.resize( 640, 480 );
    window.show();
    
    window.setAnimating( true );
        
    return app.exec();
}
