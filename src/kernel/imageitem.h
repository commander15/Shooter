#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include "item.h"

class ImageItem : public Item
{
public:
    ImageItem(const QString &image, const QSize &size, Item *parent = nullptr);
    virtual ~ImageItem();

    QString image() const;

    void setImageIndex(int index);

    inline ItemType itemType() const override
    {return Image;}

protected:
    const QString m_image;
    int m_imageIndex;
    const QSize m_size;

    QGraphicsPixmapItem m_imageItem;
};

#endif // IMAGEITEM_H
