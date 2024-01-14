#ifndef AVATAR_H
#define AVATAR_H

#include <kernel/item.h>

class Avatar : public Item
{
public:
    Avatar(const QString &image, Item *parent = nullptr);
    virtual ~Avatar();

    void init(QGraphicsScene *scene);

    void setPixmap(int index);

    void setEnergy(int energy);

    inline ItemType itemType() const
    { return AvatarItem; }

protected:
    virtual QPixmap pixmap(int index = -1) const;
    QString fileName(int index) const;

private:
    const QString image;
    QGraphicsPixmapItem m_avatarItem;
    QGraphicsRectItem m_energyItem;
};

#endif // AVATAR_H
