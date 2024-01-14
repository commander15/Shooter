#include "imageitem.h"

ImageItem::ImageItem(const QString &image, const QSize &size, Item *parent) :
    Item(parent),
    m_image(image),
    m_size(size),
    m_imageItem(this)
{
    setImageIndex(1);
}

ImageItem::~ImageItem()
{
}

QString ImageItem::image() const
{
    return m_image;
}

void ImageItem::setImageIndex(int index)
{
    if (index < 1)
        index = 1;
    else if (index > 24)
        index = 24;

    m_imageItem.setPixmap(pixmap(m_image, index, m_size.width(), m_size.height()));
    m_imageIndex = index;
}
