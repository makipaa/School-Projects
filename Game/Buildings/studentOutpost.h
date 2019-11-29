#ifndef STUDENTOUTPOST_H
#define STUDENTOUTPOST_H

#include "buildings/outpost.h"
#include "core/resourcemaps.h"
#include "core/gameeventhandler.h"
#include "core/objectmanager.h"


namespace Student {

/**
 * @brief This class represents a Outpost in the game.
 *
 * Can be placed on any unowned tile except on water.
 * Claims tiles around itself if they are unclaimed.
 * Radius 1.
 */
class StudentOutpost : public Course::Outpost
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    StudentOutpost() = delete;

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
    explicit StudentOutpost(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
                Course::ConstResourceMaps::OUTPOST_BUILD_COST,
            const Course::ResourceMap& production =
                Course::ConstResourceMaps::OUTPOST_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~StudentOutpost() = default;

    /**
     * @copydoc BuildingBase::canBePlacedOnTile()
     */
    virtual bool canBePlacedOnTile(const std::shared_ptr<Course::TileBase>
                                   &target) const;
};
} // Namespace Student

#endif // STUDENTOUTPOST_H
