#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"

namespace Student
{

class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();
    virtual ~ObjectManager() = default;

    virtual void addTiles(
            const std::vector<std::shared_ptr<Course::TileBase>>& tiles);

    virtual std::shared_ptr<Course::TileBase> getTile(
            const Course::Coordinate& coordinate);

    virtual std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId& id);

    virtual std::vector<std::shared_ptr<Course::TileBase>> getTiles(
            const std::vector<Course::Coordinate>& coordinates);

    std::vector<std::shared_ptr<Course::TileBase>> getTiles();

private:
    std::vector<std::shared_ptr<Course::TileBase>> tiles_;

};

#endif // OBJECTMANAGER_H
}
