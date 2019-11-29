 #include "tilemarker.h"


namespace Student {

TileMarker::TileMarker(QPointF location, double size)
{
    m_scenelocation_ = location;
    m_size_ = size;
}

QRectF TileMarker::boundingRect() const
{
    return QRectF(m_scenelocation_ * m_size_,
                  m_scenelocation_ * m_size_ + QPoint(m_size_, m_size_));
}

void TileMarker::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option ); Q_UNUSED( widget );
    QBrush borderSetting(Qt::white);
    painter->setBrush(borderSetting);
    painter->setPen(Qt::NoPen);
    painter->setOpacity(0.3);

    // Offset so the border is inside the tile
    painter->drawRect(boundingRect());
}

} // Namespace Student
