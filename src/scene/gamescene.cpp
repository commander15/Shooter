#include "gamescene.h"

#include <QWidget>
#include <QTimer>

GameScene::GameScene(QObject *parent) :
    Scene(parent),
    background(QPixmap(":/assets/bg.jpg"))
{
    addItem(&background);
}

void GameScene::init(QWidget *view)
{
    player.init(this);

    adaptToSize(view->size());
    connect(this, &QGraphicsScene::sceneRectChanged, this, [=](const QRectF &rect) {
        adaptToSize(rect.size().toSize());
    });
}

void GameScene::adaptToSize(const QSize &size)
{
    QPixmap pixmap(":/assets/bg.jpg");
    pixmap = pixmap.scaled(pixmap.width(), size.height());
    background.setPixmap(pixmap);

    player.setY(size.height() - 128 - 16);
}
