#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>

#include <math.h>
#include <map>
#include <memory>

#include "core/gameobject.h"
#include "tiles/tilebase.h"
#include "Graphics/mapitem.h"
#include "Graphics/tileborder.h"
#include "Graphics/tilemarker.h"

namespace Student {

const std::pair<int, int> SCENE_WIDTH_LIMITS = {1, 100};
const std::pair<int, int> SCENE_HEIGHT_LIMITS = {1, 100};
const std::pair<int, int> SCENE_SCALE_LIMITS = {1, 500};

class GameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GameScene(QWidget* parent = nullptr,
              int width = 21,
              int height = 11,
              int scale = 50);

    ~GameScene() = default;

    void setSize(int width, int height);

    void setScale(double scale);

    void resize();

    int getScale() const;

    std::pair<int,int> getSize() const;

    void drawItem( std::shared_ptr<Course::GameObject> obj);

    void drawBorder(QColor color, QPointF location);

    void drawMarker(QPointF location);

    void removeMarker();

    void removeBorder(QPoint location);

    void removeItem( std::shared_ptr<Course::GameObject> obj);

    void updateItem( std::shared_ptr<Course::GameObject> obj);

    virtual bool event(QEvent* event) override;

signals:
    void sendID(unsigned int);

private:

    QGraphicsItem* m_mapBoundRect;
    int m_width;
    int m_height;
    double m_scale;

    TileMarker* current_marker;


};

} // Namespace

#endif // GAMESCENE_H
