#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <kernel/scene.h>

#include <item/playeravatar.h>
#include <item/avatar.h>

#include <QtWidgets/qgraphicsitem.h>

//#include <GameIO/gamepad.h>

class GameScene : public Scene
{
    Q_OBJECT

public:
    explicit GameScene(QObject *parent = nullptr);

    void init(QWidget *view);

private:
    Q_SLOT void adaptToSize(const QSize &size);

    PlayerAvatar player;

    QGraphicsPixmapItem background;
};

#endif // GAMESCENE_H
