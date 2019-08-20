#include "mainWindow.hpp"
#include "ui_mainWindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui( new Ui::MainWindow )
{
    AppEventFilter* appFilter( new AppEventFilter( this ) );
    qApp->installEventFilter( appFilter );
    
    ui->setupUi( this );
}

MainWindow::~MainWindow()
{
    delete ui;
}

AppEventFilter::AppEventFilter( QObject* i_parent )
    : QObject( i_parent )
{
}

bool AppEventFilter::eventFilter( QObject* i_obj, QEvent* i_event)
{
    return QObject::eventFilter( i_obj, i_event );
}
