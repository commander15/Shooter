#include "shooterwindow.h"
#include "ui_shooterwindow.h"

#include <QResizeEvent>

ShooterWindow::ShooterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShooterWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);

    scene.init(this);

    setCursor(Qt::CursorShape::BlankCursor);
}

ShooterWindow::~ShooterWindow()
{
    delete ui;
}

void ShooterWindow::resizeEvent(QResizeEvent *event)
{
    QRect rect;
    rect.setSize(event->size());
    scene.setSceneRect(rect);
    QMainWindow::resizeEvent(event);
}
