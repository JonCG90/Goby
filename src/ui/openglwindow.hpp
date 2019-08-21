#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>

#ifndef OpenGLWindow_HPP
#define OpenGLWindow_HPP

QT_BEGIN_NAMESPACE
class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;
QT_END_NAMESPACE

class OpenGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = 0);
    ~OpenGLWindow();
    
    virtual void render(QPainter *painter);
    virtual void render();
    
    virtual void initialize();
    
    void setAnimating(bool animating);
    
public slots:
    void renderLater();
    void renderNow();
    
protected:
    
    bool event(QEvent *event) override;
    
    // Mouse events
    void mousePressEvent(QMouseEvent *i_event) override;
    void mouseReleaseEvent(QMouseEvent *i_event) override;
    void mouseMoveEvent(QMouseEvent *i_event) override;
    
    void resizeEvent(QResizeEvent *i_event) override;
    
    void exposeEvent(QExposeEvent *event) override;
    
private:
    
    bool m_animating;
    
    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
};

#endif /* OpenGLWindow_HPP */
