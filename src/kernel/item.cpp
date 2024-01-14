#include "item.h"

Item::Item(Item *parent) :
    QGraphicsItemGroup(parent)
{
    setZValue(1);
}

Item::~Item()
{
}

void Item::adaptToSceneSize(const QSize &size)
{
    Q_UNUSED(size)
}

QPixmap Item::pixmap(const QString &image, int index, int width, int height)
{
    QString fileName = ":/assets/" + image;
    fileName += '/' + image + ".png";
}
