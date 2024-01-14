#include "avatar.h"

#include <QtGui/qbrush.h>

#include <QGraphicsScene>

#define SIZE() QSize(80, 80)

Avatar::Avatar(const QString &image, Item *parent) :
    Item(parent),
    image(image),
    m_avatarItem(this),
    m_energyItem(this)
{
    m_energyItem.setBrush(QBrush(Qt::green));
    m_energyItem.setX(SIZE().width() / 3);

    setZValue(10);
    setVisible(false);
}

Avatar::~Avatar()
{
}

void Avatar::init(QGraphicsScene *scene)
{
    setPixmap(1);
    setEnergy(100);
    setVisible(true);

    scene->addItem(this);
}

void Avatar::setPixmap(int index)
{
    if (index < 1)
        index = 1;

    m_avatarItem.setPixmap(pixmap(index));
}

void Avatar::setEnergy(int energy)
{
    QRectF rect = m_energyItem.rect();
    rect.setWidth(32);
    rect.setHeight(6);
    m_energyItem.setRect(rect);
}

QPixmap Avatar::pixmap(int index) const
{
    return QPixmap(fileName(index)).scaled(SIZE(), Qt::KeepAspectRatio);
}

QString Avatar::fileName(int index) const
{
    return ":/assets/" + image + '/' + image + QString::number(index) + ".png";
}
