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
    /**
     * @brief Constructor
     * @param location Location where the marker is drawn
     * @param size Size of one side of the marker square
     */
    TileMarker(QPointF location, double size);

    /**
     * @brief boundingRect
     * @return the bounding rectangle of this item.
     */
    QRectF boundingRect() const override;

    /**
     * @brief Draws the image.
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);


private:
    QPointF m_scenelocation_;
    double m_size_;
};
} // Namespace Student

#endif // TILEMARKER_H
