#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class AppEventFilter : public QObject
{
    Q_OBJECT
    
public:
    
    explicit AppEventFilter( QObject* i_parent );
    ~AppEventFilter() = default;
    
    bool eventFilter( QObject* i_obj, QEvent* i_event) override;
};

#endif // MAINWINDOW_HPP
