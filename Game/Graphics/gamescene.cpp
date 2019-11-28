#include "Graphics/gamescene.h"


namespace Student {

GameScene::GameScene(QWidget* parent,
                     int width,
                     int height,
                     int scale):

    QGraphicsScene(parent),
    m_mapBoundRect(nullptr),
    m_width(20),
    m_height(10),
    m_scale(50)
{
    setSize(width, height);
    setScale(scale);
}

void GameScene::setSize(int width, int height)
{
    if ( width >= SCENE_WIDTH_LIMITS.first && width <= SCENE_WIDTH_LIMITS.second )
    {
        m_width = width;
    }
    if ( height >= SCENE_HEIGHT_LIMITS.first && height <= SCENE_HEIGHT_LIMITS.second )
    {
        m_height = height;
    }
    resize();
}

void GameScene::setScale(double scale)
{
    if ( scale >= SCENE_SCALE_LIMITS.first && scale <= SCENE_SCALE_LIMITS.second )
    {
        m_scale = scale;
    }
    resize();
}

void GameScene::resize()
{
    if ( m_mapBoundRect != nullptr ){
        QGraphicsScene::removeItem(m_mapBoundRect);
    }
    QRectF rect = QRectF(0,0, m_width * m_scale, m_height * m_scale);

    addRect(rect);
    setSceneRect(rect);
    m_mapBoundRect = items().back();
    // Draw on the bottom of all items
    m_mapBoundRect->setZValue(-1);
}

int GameScene::getScale() const
{
    return m_scale;
}

std::pair<int, int> GameScene::getSize() const
{
    return {m_width, m_height};
}

void GameScene::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    QList<QGraphicsItem*> items_list = items();
    if ( items_list.size() != 1 ){
        for ( auto item : items_list ){
            MapItem* mapItem = static_cast<MapItem*>(item);
            if (mapItem->isSameObj(obj)){
                mapItem->updateLoc();
            }
        }
    }
}

bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent* mouse_event =
                dynamic_cast<QGraphicsSceneMouseEvent*>(event);

        if ( sceneRect().contains(mouse_event->scenePos())){

            QPointF point = mouse_event->scenePos() / m_scale;

            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            auto objects = items(point * m_scale);

            if (objects.size() != 1){
                // Get the clicked tile
                // Tile is the second lowest in the scene after the scene itself
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

void GameScene::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    QList<QGraphicsItem*> items_list = items(obj->getCoordinate().asQpoint());
    if ( items_list.size() == 1 ){
        qDebug() << "Nothing to be removed at the location pointed by given obj.";
    } else {
        for ( auto item : items_list ){
            if (MapItem* mapitem = dynamic_cast<MapItem*>(item)){
                if ( mapitem->isSameObj(obj) ){
                    delete mapitem;
                }
            }
        }
    }
}


void GameScene::drawItem(std::shared_ptr<Course::GameObject> obj)
{
    std::map<std::string, QImage>::iterator iter = images_.find(obj->getType());

    if(iter != images_.end()){
        QImage image = images_[obj->getType()];
        MapItem* nItem = new MapItem(obj, m_scale, image);
        addItem(nItem);
    }
    else {
        qDebug() << "Image not found.";
    }

}

void GameScene::drawBorder(QColor color, QPointF location)
{
    TileBorder* border = new TileBorder(color,location,m_scale);
    border->setZValue(2);
    addItem(border);
}

void GameScene::drawMarker(QPointF location)
{
    if (current_marker){
       delete current_marker;
    }
    current_marker = new TileMarker(location,m_scale);
    current_marker->setZValue(3);
    addItem(current_marker);

}

void GameScene::removeMarker()
{
    if (current_marker){
       delete current_marker;
    }
    current_marker = nullptr;
}

void GameScene::removeBorder(QPoint location)
{
    QList<QGraphicsItem*> items_list = items(location);
    if ( items_list.size() == 1 ){
        qDebug() << "Nothing to be removed at the location pointed by given obj.";
    } else {
        for ( auto item : items_list ){
            if (TileBorder* border = dynamic_cast<TileBorder*>(item)){
                delete border;
            }
        }
    }
}

}
