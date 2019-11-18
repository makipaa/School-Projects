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

        QImage imageForest_ = QImage("Images/forest.png");
        QImage imageCobblestone_ = QImage("Images/mountain.png");
        QImage imageWater_ = QImage("Images/water.png");
        QImage imageSwamp_ = QImage("Images/swamp.png");
        QImage imageGrass_ = QImage("Images/grass.png");
        QImage imageHeadquarters_ = QImage("Images/headquarters.png");
        QImage imageOutpost_ = QImage("Images/outpost.png");


};
} // Namespace
#endif // MAPITEM_H
