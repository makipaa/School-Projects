#ifndef SIMPLEMAPITEM_HH
#define SIMPLEMAPITEM_HH

#include <QGraphicsItem>
#include <QPainter>

#include <memory>
#include <map>

#include "core/gameobject.h"

namespace Student {

class MapItem : public QGraphicsItem
{
public:

    MapItem(const std::shared_ptr<Course::GameObject> &obj, int size);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    const std::shared_ptr<Course::GameObject> &getBoundObject();

    void updateLoc();

    bool isSameObj(std::shared_ptr<Course::GameObject> obj);

    int getSize() const;

    void setSize(int size);

private:
    const std::shared_ptr<Course::GameObject> m_gameobject;
    QPoint m_scenelocation;
    int m_size;

    static std::map<std::string, QColor> c_mapcolors;
    static void addNewColor(std::string type);

    std::map<std::string, QImage> images_ = {{"Forest", QImage("Images/forest.png")},
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
} // Namespace
#endif // MAPITEM_H
