#include "scene.h"

#include "item.h"

Scene::Scene(QObject *parent) :
    QGraphicsScene{parent}
{
    adaptItemsToSize(sceneRect().size());
    connect(this, &QGraphicsScene::sceneRectChanged, this, [=](const QRectF &rect) {
        adaptItemsToSize(rect.size());
    });
}

Scene::~Scene()
{
}

void Scene::addItem(Item *item)
{
    QGraphicsScene::addItem(item);
    m_items.append(item);
}

void Scene::addItem(QGraphicsItem *item)
{
    QGraphicsScene::addItem(item);
}

void Scene::adaptItemsToSize(const QSizeF &size)
{
    for (Item *item : m_items)
        item->adaptToSceneSize(size.toSize());
}
