#include "Graphics/gamescene.h"


namespace Student {

GameScene::GameScene(QWidget* parent,
                     int width,
                     int height,
                     int scale):

    QGraphicsScene(parent),
    m_mapBoundRect_(nullptr),
    m_width_(20),
    m_height_(10),
    m_scale_(50)
{
    setSize(width, height);
    setScale(scale);
}

void GameScene::setSize(int width, int height)
{
    if(width >= SCENE_WIDTH_LIMITS.first &&
         width <= SCENE_WIDTH_LIMITS.second)
    {
        m_width_ = width;
    }
    if(height >= SCENE_HEIGHT_LIMITS.first &&
            height <= SCENE_HEIGHT_LIMITS.second)
    {
        m_height_ = height;
    }
    resize();
}

void GameScene::setScale(double scale)
{
    if(scale >= SCENE_SCALE_LIMITS.first &&
            scale <= SCENE_SCALE_LIMITS.second)
    {
        m_scale_ = scale;
    }
    resize();
}

void GameScene::resize()
{
    if ( m_mapBoundRect_ != nullptr ){
        QGraphicsScene::removeItem(m_mapBoundRect_);
    }
    QRectF rect = QRectF(0,0, m_width_ * m_scale_, m_height_ * m_scale_);

    addRect(rect);
    setSceneRect(rect);
    m_mapBoundRect_ = items().back();
    // Draw on the bottom of all items
    m_mapBoundRect_->setZValue(-1);
}

int GameScene::getScale() const
{
    return m_scale_;
}

std::pair<int, int> GameScene::getSize() const
{
    return {m_width_, m_height_};
}

bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent* mouse_event =
                dynamic_cast<QGraphicsSceneMouseEvent*>(event);

        if ( sceneRect().contains(mouse_event->scenePos())){

            QPointF point = mouse_event->scenePos() / m_scale_;

            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            auto objects = items(point * m_scale_);

            if (objects.size() != 1){
                // Get the clicked tile
                // Tile is second lowest in the scene after the scene itself
                QGraphicsItem* pressed = (objects.end()[-2]);
                auto clicked_object = static_cast<Student::MapItem*>(pressed)
                        ->getBoundObject();
                emit sendID(static_cast<Student::MapItem*>(pressed)
                            ->getBoundObject()->ID);
                return true;
            }
        }
    }

    return QGraphicsScene::event(event);
}

QImage GameScene::getImage(std::string buildingName)
{
    return images_.at(buildingName);
}

void GameScene::drawItem(std::shared_ptr<Course::GameObject> obj)
{
    std::map<std::string, QImage>::iterator iter = images_.find(obj->getType());

    if(iter != images_.end()){
        QImage image = images_[obj->getType()];
        MapItem* nItem = new MapItem(obj, m_scale_, image);
        addItem(nItem);
    }

}

void GameScene::drawBorder(QColor color, QPointF location)
{
    TileBorder* border = new TileBorder(color,location,m_scale_);
    border->setZValue(2);
    addItem(border);
}

void GameScene::drawMarker(QPointF location)
{
    if (current_marker_){
       delete current_marker_;
    }
    current_marker_ = new TileMarker(location,m_scale_);
    current_marker_->setZValue(3);
    addItem(current_marker_);

}

void GameScene::removeMarker()
{
    if (current_marker_){
       delete current_marker_;
    }
    current_marker_ = nullptr;
}

} // Namespace Student
