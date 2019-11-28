#include "tileborder.h"


namespace Student {

TileBorder::TileBorder(QColor bordercolor, QPointF location, double size)
{
    borderColor_ = bordercolor;
    m_scenelocation_ = location;
    m_size_ = size;
}

QRectF TileBorder::boundingRect() const
{
    return QRectF(m_scenelocation_ * m_size_,
                  m_scenelocation_ * m_size_ + QPoint(m_size_, m_size_));
}

void TileBorder::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option ); Q_UNUSED( widget );
    QPen borderSetting(borderColor_, 2);
    painter->setPen(borderSetting);

    // Offset so the border is inside the tile
    painter->drawRect(boundingRect().x()+borderSetting.width()/2,
                      boundingRect().y()+borderSetting.width()/2,
                      boundingRect().width()-borderSetting.width(),
                      boundingRect().height()-borderSetting.width());
}

QPointF TileBorder::getLocation()
{
    return m_scenelocation_;
}

} // Namespace Student
