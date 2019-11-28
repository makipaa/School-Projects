#ifndef SIMPLEMAPITEM_HH
#define SIMPLEMAPITEM_HH

#include <QGraphicsItem>
#include <QPainter>
#include <memory>
#include <map>

#include "core/gameobject.h"

namespace Student {

class MapItem : public QGraphicsItem
{
public:

    MapItem(const std::shared_ptr<Course::GameObject> &obj, double size, QImage image);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    const std::shared_ptr<Course::GameObject> &getBoundObject();

    bool isSameObj(std::shared_ptr<Course::GameObject> obj);

    int getSize() const;

    void setSize(int size);

private:
    const std::shared_ptr<Course::GameObject> m_gameobject;
    QPointF m_scenelocation;
    double m_size;

    QImage image_;
};
} // Namespace

#endif // MAPITEM_H
