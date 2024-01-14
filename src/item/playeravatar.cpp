#include "playeravatar.h"

#include <GameIO/gamepadmanager.h>

#include <QGraphicsSceneEvent>

using namespace GameIO;

PlayerAvatar::PlayerAvatar(Item *parent) :
    Avatar("player", parent)
{
    QList<int> gamepads = GamepadManager::instance()->connectedGamepads();
    if (!gamepads.isEmpty())
        m_gamepad.setId(gamepads.constFirst());

    connect(&m_gamepad, &Gamepad::buttonLeftChanged, this, &PlayerAvatar::processLeftPress);
    connect(&m_gamepad, &Gamepad::buttonRightChanged, this, &PlayerAvatar::processRightPress);

    m_timer.setInterval(80);
    connect(&m_timer, &QTimer::timeout, this, &PlayerAvatar::processInput);
}

void PlayerAvatar::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event;
}

void PlayerAvatar::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

void PlayerAvatar::processLeftPress(bool pressed)
{
    processButtonPress(1, pressed);
}

void PlayerAvatar::processRightPress(bool pressed)
{
    processButtonPress(2, pressed);
}

void PlayerAvatar::processButtonPress(int id, bool pressed)
{
    qDebug("%d %s !", id, (pressed ? "pressed" : "released"));

    if (pressed && !m_buttons.contains(id))
        m_buttons.append(id);
    else if (!pressed && m_buttons.contains(id))
        m_buttons.removeOne(id);
    else
        qDebug("Oups !");

    if (!m_buttons.isEmpty() && !m_timer.isActive()) {
        processInput();
        m_timer.start();
    } else if (m_buttons.isEmpty() && m_timer.isActive())
        m_timer.stop();
}

void PlayerAvatar::processInput()
{
    for (int button : std::as_const(m_buttons)) {
        switch (button) {
        case 1:
            moveBy(-6, 0);
            break;

        case 2:
            moveBy(6, 0);
            break;

        default:
            break;
        }
    }
}
