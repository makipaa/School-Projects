#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"
#include "core/playerbase.h"
#include "core/basicresources.h"

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

    void addBuilding(
            const std::shared_ptr<Course::BuildingBase>& building);
    std::shared_ptr<Course::BuildingBase> getBuilding(Course::ObjectId building_id);


    std::vector<std::shared_ptr<Course::BuildingBase>> getBuildings();

    std::vector<std::shared_ptr<Course::TileBase>> getTiles();



private:
    std::vector<std::shared_ptr<Course::TileBase>> tiles_;
    std::vector<std::shared_ptr<Course::BuildingBase>> buildings_;
};
}
#endif // OBJECTMANAGER_H

