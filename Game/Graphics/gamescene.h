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
const std::pair<int, int> SCENE_HEIGHT_LIMITS = {1, 50};
const std::pair<int, int> SCENE_SCALE_LIMITS = {1, 500};

/**
 * @brief The GameScene class
 * This class handles the game scene itself,
 * checking the borders of it, drawing it etc.
 */
class GameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the class.
     *
     * @param qt_parent points to the parent object per Qt's parent-child-system.
     * @param width in tiles for the game map.
     * @param height in tiles for the game map.
     * @param scale is the size in pixels of a single square tile.
     *
     * @pre 0 < width <= 100 && 0 < height <= 50 && 0 < scale <= 500. Otherwise
     * default values are used for the created object.
     * @post Exception Guarantee: No guarantee.
     */
    GameScene(QWidget* parent = nullptr,
              int width = 20,
              int height = 10,
              int scale = 50);
    /**
     * @brief Default destructor
     */
    ~GameScene() = default;

    /**
     * @brief Sets size of the scene.
     * @param width Width of the scene.
     * @param height Heigth of the scene.
     * @pre Width and height must be within limits.
     * @post Exception Guarantee: No throw.
     */
    void setSize(int width, int height);

    /**
     * @brief Sets scale for the scene.
     * @param scale Value for the scale.
     * @pre Scale must be within limits.
     * @post Exception Guarantee: No guarantee.
     */
    void setScale(double scale);

    /**
     * @brief Adjusts the size of the scene.
     * @post Exception Guarantee: No guarantee.
     */
    void resize();

    /**
     * @return Scale value m_scale_.
     * @post Exception Guarantee: No throw.
     */
    int getScale() const;

    /**
     * @return Size of the map as a pair.
     * @post Exception Guarantee: No throw.
     */
    std::pair<int,int> getSize() const;

    /**
     * @brief Searches for the right picture for the object and draws it.
     * @param obj Wanted object to be drawn.
     * @post Exception Guarantee: No guarantee.
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief Draws borders for the desired location.
     * @param color Color to be used.
     * @param location Location where the borders will be drawn.
     * @post Exception Guarantee: No guarantee.
     */
    void drawBorder(QColor color, QPointF location);

    /**
     * @brief Draws a highlighter as a tile is clicked. Easier to track
     * which tile is clicked.
     * @param location Location to be highlighted.
     * @post Exception Guarantee: No guarantee.
     */
    void drawMarker(QPointF location);

    /**
     * @brief Removes highlight.
     * @post Exception Guarantee: No guarantee.
     */
    void removeMarker();

    /**
     * @brief As a tile or a object is clicked, it emits a signal which has
     * tile ID as its parameter.
     * @param event that has happened.
     * @return True: if event was  handled in the handler.
     * False: if the event handling was passed over.
     */
    virtual bool event(QEvent* event) override;

    /**
     * @param buildingName Name of the building.
     * @return Image respective to the building name.
     * @post Exception Guarantee: Basic.
     */
    QImage getImage(std::string buildingName);

signals:
    /**
     * @brief Sends the tiles ID.
     */
    void sendID(unsigned int);

private:

    QGraphicsItem* m_mapBoundRect_;
    int m_width_;
    int m_height_;
    double m_scale_;
    TileMarker* current_marker_ = nullptr;
    std::map<std::string, QImage> images_ =
            {{"Forest", QImage(":/Images/forest.png")},
            {"Water", QImage(":/Images/water.png")},
            {"Swamp", QImage(":/Images/swamp.png")},
            {"Cobblestone", QImage(":/Images/mountain.png")},
            {"Grassland", QImage(":/Images/grass.png")},
            {"Farm", QImage(":/Images/farm.png")},
            {"HeadQuarters", QImage(":/Images/headquarters.png")},
            {"Outpost", QImage(":/Images/outpost.png")},
            {"Mine", QImage(":/Images/mine.png")},
            {"Trawler", QImage(":/Images/trawler.png")},
            {"Sawmill", QImage(":/Images/sawmill.png")}};

};
} // Namespace Student

#endif // GAMESCENE_H
