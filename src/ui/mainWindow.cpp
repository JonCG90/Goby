#include "mainWindow.hpp"
#include "ui_mainWindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui( new Ui::MainWindow )
{    
    ui->setupUi( this );
}

MainWindow::~MainWindow()
{
    delete ui;
}
