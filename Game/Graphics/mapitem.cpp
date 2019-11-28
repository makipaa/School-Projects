#include "mapitem.h"
#include "qdebug.h"


namespace Student {

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, double size,
                 QImage image):
    m_gameobject(obj),
    m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()),
    m_size(size),
    image_(image)
{
}

QRectF MapItem::boundingRect() const
{
    return QRectF(m_scenelocation * m_size, m_scenelocation * m_size +
                  QPointF(m_size, m_size));
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    Q_UNUSED( option ); Q_UNUSED( widget );
    painter->drawImage(boundingRect(), image_);
}

const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return m_gameobject;
}

bool MapItem::isSameObj(std::shared_ptr<Course::GameObject> obj)
{
    return obj == m_gameobject;
}

int MapItem::getSize() const
{
    return m_size;
}

void MapItem::setSize(int size)
{
    if ( size > 0 && size <= 500 ){
        m_size = size;
    }
}

} // Namespace Student
