#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Item;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Scene(QObject *parent = nullptr);
    virtual ~Scene();

protected:
    void addItem(Item *item);
    void addItem(QGraphicsItem *item);

    QVector<Item *> m_items;

private:
    Q_SLOT void adaptItemsToSize(const QSizeF &size);
};

#endif // SCENE_H
