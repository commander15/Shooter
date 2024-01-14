#ifndef PLAYERAVATAR_H
#define PLAYERAVATAR_H

#include "avatar.h"

#include <GameIO/gamepad.h>

#include <QtCore/qtimer.h>

class PlayerAvatar : public QObject, public Avatar
{
    Q_OBJECT

public:
    explicit PlayerAvatar(Item *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    Q_SLOT void processLeftPress(bool pressed);
    Q_SLOT void processRightPress(bool pressed);
    void processButtonPress(int id, bool pressed);

    Q_SLOT void processInput();

    GameIO::Gamepad m_gamepad;
    QList<int> m_buttons;

    QTimer m_timer;
};

#endif // PLAYERAVATAR_H
