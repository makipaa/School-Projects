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
    /**
     * @brief Constructor
     * @param bordercolor color used for drawing the borders
     * @param location location where the bordets are drawn
     * @param size size of one side in border square
     * @pre obj must have a valid Coordinate.
     * @post Exception Guarantee: No guarantee.
     */
    TileBorder(QColor bordercolor, QPointF location, double size);

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

    /**
     * @brief Gives the borders location
     * @return Returns the borders upper left corners location
     */
    QPointF getLocation();

private:
    QColor borderColor_;
    QPointF m_scenelocation_;
    int m_size_;

};
} // Namespace Student

#endif // TILEBORDER_H
