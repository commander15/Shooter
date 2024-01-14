#ifndef SHOOTERWINDOW_H
#define SHOOTERWINDOW_H

#include <QMainWindow>

#include <scene/gamescene.h>

namespace Ui {
class ShooterWindow;
}

class ShooterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShooterWindow(QWidget *parent = nullptr);
    ~ShooterWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::ShooterWindow *ui;

    GameScene scene;
};

#endif // SHOOTERWINDOW_H
