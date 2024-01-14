#ifndef ITEM_H
#define ITEM_H

#include <QtWidgets/QGraphicsItemGroup>

class QPixmap;
class QSoundEffect;

class Item : public QGraphicsItemGroup
{
public:
    enum ItemType {
        Image,
        AvatarItem
    };

    explicit Item(Item *parent = nullptr);
    virtual ~Item();

    virtual ItemType itemType() const = 0;

    //QSize size() const;

protected:
    virtual void adaptToSceneSize(const QSize &size);

    static QPixmap pixmap(const QString &image, int index, int width, int height);

    static void play(const QString &sound, int loops = 1);
    static QSoundEffect *soundEffect(const QString &sound);

private:
    static inline QHash<QString, QPixmap> m_pixmaps;
    static inline QHash<QString, QSoundEffect *> m_soundEffects;

    friend class Scene;
};

#endif // ITEM_H
