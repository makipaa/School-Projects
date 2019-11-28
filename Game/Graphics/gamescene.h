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

    virtual bool event(QEvent* event) override;

    QImage getImage(std::string buildingName);

signals:
    void sendID(unsigned int);

private:

    QGraphicsItem* m_mapBoundRect_;
    int m_width_;
    int m_height_;
    double m_scale_;
    TileMarker* current_marker_ = nullptr;
    std::map<std::string, QImage> images_ =
            {{"Forest", QImage("Images/forest.png")},
            {"Water", QImage("Images/water.png")},
            {"Swamp", QImage("Images/swamp.png")},
            {"Cobblestone", QImage("Images/mountain.png")},
            {"Grassland", QImage("Images/grass.png")},
            {"Farm", QImage("Images/farm.png")},
            {"HeadQuarters", QImage("Images/headquarters.png")},
            {"Outpost", QImage("Images/outpost.png")},
            {"Mine", QImage("Images/mine.png")},
            {"Trawler", QImage("Images/trawler.png")},
            {"Sawmill", QImage("Images/sawmill.png")}};

};
} // Namespace Student

#endif // GAMESCENE_H
