#ifndef STUDENTFARM_H
#define STUDENTFARM_H

#include "buildings/farm.h"
#include "core/resourcemaps.h"
#include "core/gameeventhandler.h"
#include "core/objectmanager.h"


namespace Student {

/**
 * @brief This class represents a farm in the game.
 *
 * Can only be placed in a Grassland-tile which is
 * owned by the player in turn.
 * Boosts food production.
 */
class StudentFarm : public Course::Farm
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    StudentFarm() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the GameEventHandler.
     * @param objectmanager points to the ObjectManager.
     * @param owner points to the owning player.
     *
     * @post Exception Guarantee: No guarantee.
     * @exception OwnerConflict - if the building conflicts with tile's
     * ownership.
     */
    explicit StudentFarm(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
                Course::ConstResourceMaps::FARM_BUILD_COST,
            const Course::ResourceMap& production =
                Course::ConstResourceMaps::FARM_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~StudentFarm() = default;

    /**
     * @copydoc BuildingBase::canBePlacedOnTile()
     */
    virtual bool canBePlacedOnTile(const std::shared_ptr<Course::TileBase>
                                   &target) const;
};
} // Namespace Student

#endif // STUDENTFARM_H
