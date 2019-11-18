#ifndef TILEBORDER_H
#define TILEBORDER_H


#include <QGraphicsItem>
#include <QPainter>

#include <memory>
#include <map>

#include "tiles/tilebase.h"
#include "core/player.h"

namespace Student {

class TileBorder : public QGraphicsItem
{
public:

    TileBorder(QColor bordercolor, QPoint location, int size);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QPoint getLocation();


private:
    QColor borderColor_;
    QPoint m_scenelocation_;
    int m_size_;

};
} // Namespace

#endif // TILEBORDER_H
