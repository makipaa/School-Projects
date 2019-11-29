#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"
#include "core/playerbase.h"
#include "core/basicresources.h"
#include "workers/workerbase.h"


namespace Student {

/**
 * @brief The ObjectManager class
 *
 * Handles games tiles, buildings and workers.
 */
class ObjectManager : public Course::iObjectManager
{
public:
    /**
     * @brief Parameterless constructor.
     * @post Exception Guarantee: No guarantee.
     */
    ObjectManager();

    /**
     * @brief Default destructor.
     */
    virtual ~ObjectManager() = default;

    /**
     * @brief Adds tiles to the variable tiles_.
     * @param tiles The given tiles to be added.
     * @post Exception Guarantee: No guarantee.
     */
    virtual void addTiles(
            const std::vector<std::shared_ptr<Course::TileBase>>& tiles);

    /**
     * @brief Gets the wanted tile according to coordinates.
     * @param coordinate Where the tile should be.
     * @return Pointer to the tile which corresponds to the coordinate.
     * @post Exception Guarantee: No guarantee.
     */
    virtual std::shared_ptr<Course::TileBase> getTile(
            const Course::Coordinate& coordinate);

    /**
     * @brief Gets the wanted tile according to id.
     * @param Id Where the tile should be.
     * @return Pointer to the tile which corresponds to the id.
     * @post Exception Guarantee: No guarantee.
     */
    virtual std::shared_ptr<Course::TileBase> getTile(
            const Course::ObjectId& id);

    /**
     * @brief Gets all tiles with given coordinates
     * @param Vector of coordinates where the wanted tiles are
     * @return Tiles with the given coordinates
     * @note if coordinate which doesn't have tile is given, the coordinate is
     * ignored
     * @post Exception Guarantee: No throw
     */
    virtual std::vector<std::shared_ptr<Course::TileBase>> getTiles(
            const std::vector<Course::Coordinate>& coordinates);

    /**
     * @brief Adds the wanted building to the private variable buildings_;
     * @param building The building to be added.
     * @post Exception Guarantee: Strong guarantee.
     */
    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building);

    /**
     * @brief Adds the wanted worker to the private variable workers_;
     * @param worker The worker to be added.
     * @post Exception Guarantee: Strong guarantee.
     */
    void addWorker(const std::shared_ptr<Course::WorkerBase>& worker);


    std::shared_ptr<Course::WorkerBase> getWorker(Course::ObjectId workerID);
    std::shared_ptr<Course::BuildingBase> getBuilding(
            Course::ObjectId building_id);

    std::vector<std::shared_ptr<Course::BuildingBase>> getBuildings();

    /**
     * @return Returns the tiles_ variable.
     * @post Exception Guarantee: No throw.
     */
    std::vector<std::shared_ptr<Course::TileBase>> getTiles();

private:
    std::vector<std::shared_ptr<Course::TileBase>> tiles_ = {};
    std::vector<std::shared_ptr<Course::BuildingBase>> buildings_ {};
    std::vector<std::shared_ptr<Course::WorkerBase>> workers_ {};
};
} // Namespace Student

#endif // OBJECTMANAGER_H

