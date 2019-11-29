#ifndef SIMPLEMAPITEM_HH
#define SIMPLEMAPITEM_HH

#include <QGraphicsItem>
#include <QPainter>
#include <memory>
#include <map>

#include "core/gameobject.h"

namespace Student {

/**
 * @brief This class acts as a single GameObject element.
 */
class MapItem : public QGraphicsItem
{
public:
    /**
     * @brief Constructor
     *
     * @param obj shared_ptr to the obj.
     * @param size of the created item in pixels.
     * @pre obj must have a valid Coordinate.
     * @post Exception Guarantee: No guarantee.
     */
    MapItem(const std::shared_ptr<Course::GameObject> &obj, double size, QImage image);

    /**
     * @brief Default destructor.
     */
    virtual ~MapItem() = default;

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
     * @return Returns a pointer to the game object.
     */
    const std::shared_ptr<Course::GameObject> &getBoundObject();

    /**
     * @return Size of a one rectangle.
     * @post Exception Guarantee: No throw.
     */
    int getSize() const;

    /**
     * @brief Sets size of a single rectangle.
     * @param size Of a one side.
     * @post Exception Guarantee: No throw.
     */
    void setSize(int size);

private:
    const std::shared_ptr<Course::GameObject> m_gameobject_;
    QPointF m_scenelocation_;
    double m_size_;

    QImage image_;
};
} // Namespace

#endif // MAPITEM_H
