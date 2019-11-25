#ifndef TILEMARKER_H
#define TILEMARKER_H


#include <QGraphicsItem>
#include <QPainter>

#include <memory>
#include <map>

#include "core/gameobject.h"

namespace Student {

class TileMarker : public QGraphicsItem
{
public:

    TileMarker(QPointF location, double size);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    const std::shared_ptr<Course::GameObject> &getBoundObject();



private:
    QPointF m_scenelocation_;
    double m_size_;
};
} // Namespace

#endif // TILEMARKER_H
