#include "openglwindow.hpp"

#include <app/actions/actionManager.hpp>

#include <QtCore/QCoreApplication>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>
#include <QWidget>

#include <iostream>

OpenGLWindow::OpenGLWindow(QWindow *parent)
: QWindow(parent)
, m_animating(false)
, m_context(0)
, m_device(0)
{
    setSurfaceType(QWindow::OpenGLSurface);
}

OpenGLWindow::~OpenGLWindow()
{
    delete m_device;
}

void OpenGLWindow::render(QPainter *painter)
{
    Q_UNUSED(painter);
}

void OpenGLWindow::initialize()
{
}

void OpenGLWindow::update()
{
}

void OpenGLWindow::render()
{
    if (!m_device)
    {
        m_device = new QOpenGLPaintDevice;
    }
    
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
    
    m_device->setSize(size() * devicePixelRatio());
    m_device->setDevicePixelRatio(devicePixelRatio());
    
    QPainter painter(m_device);
    render(&painter);
}

void OpenGLWindow::renderLater()
{
    requestUpdate();
}

bool OpenGLWindow::event(QEvent *event)
{
    switch (event->type()) {
        case QEvent::UpdateRequest:
            renderNow();
            return true;
        default:
            return QWindow::event(event);
    }
}

void OpenGLWindow::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);
    
    if (isExposed())
        renderNow();
}

void OpenGLWindow::renderNow()
{
    if (!isExposed())
        return;
    
    bool needsInitialize = false;
    
    if (!m_context) {
        m_context = new QOpenGLContext(this);
        
        QSurfaceFormat format;
        format.setDepthBufferSize( 24 );
        format.setMajorVersion( 3 );
        format.setMinorVersion( 2 );
        format.setSamples( 4 );
        format.setProfile( QSurfaceFormat::CoreProfile );
        
        m_context->setFormat(format);
        m_context->create();
        
        needsInitialize = true;
    }
    
    m_context->makeCurrent(this);
    
    if (needsInitialize) {
        initializeOpenGLFunctions();
        initialize();
    }
    
    update();
    render();
    
    m_context->swapBuffers(this);
    
    if (m_animating)
        renderLater();
}

void OpenGLWindow::setAnimating(bool animating)
{
    m_animating = animating;
    
    if (animating)
        renderLater();
}

void OpenGLWindow::mousePressEvent(QMouseEvent *i_event)
{
    std::cout << "Mouse Pressed" << std::endl;
    QWindow::mousePressEvent(i_event);
}

void OpenGLWindow::mouseReleaseEvent(QMouseEvent *i_event)
{
    std::cout << "Mouse Released" << std::endl;
    QWindow::mouseReleaseEvent(i_event);
}

void OpenGLWindow::mouseMoveEvent(QMouseEvent *i_event)
{
    std::cout << "Mouse Moved" << std::endl;
    QWindow::mouseMoveEvent(i_event);
}

void OpenGLWindow::resizeEvent(QResizeEvent *i_event)
{
    std::cout << "Resize Event" << std::endl;
    QWindow::resizeEvent(i_event);
}


