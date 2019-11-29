#include "mapitem.h"
#include "qdebug.h"


namespace Student {

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, double size,
                 QImage image):
    m_gameobject_(obj),
    m_scenelocation_(m_gameobject_->getCoordinatePtr()->asQpoint()),
    m_size_(size),
    image_(image)
{
}

QRectF MapItem::boundingRect() const
{
    return QRectF(m_scenelocation_ * m_size_, m_scenelocation_ * m_size_ +
                  QPointF(m_size_, m_size_));
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    Q_UNUSED( option ); Q_UNUSED( widget );
    painter->drawImage(boundingRect(), image_);
}

const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return m_gameobject_;
}

int MapItem::getSize() const
{
    return m_size_;
}

void MapItem::setSize(int size)
{
    if ( size > 0 && size <= 500 ){
        m_size_ = size;
    }
}

} // Namespace Student
