#ifndef STUDENTHEADQUARTER_H
#define STUDENTHEADQUARTER_H

#include "buildings/headquarters.h"
#include "core/resourcemaps.h"
#include "core/gameeventhandler.h"
#include "core/objectmanager.h"


namespace Student {

/**
 * @brief This class represents a HeadQuarters in the game.
 *
 * Can be placed on any unowned tile except on water.
 * Only one HQ can be build.
 * Claims tiles around itself if they are unclaimed.
 * Radius 3.
 */
class StudentHeadQuarters : public Course::HeadQuarters
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    StudentHeadQuarters() = delete;

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
    explicit StudentHeadQuarters(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
                Course::ConstResourceMaps::HQ_BUILD_COST,
            const Course::ResourceMap& production =
                Course::ConstResourceMaps::HQ_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~StudentHeadQuarters() = default;

    /**
     * @copydoc BuildingBase::canBePlacedOnTile()
     */
    virtual bool canBePlacedOnTile(const std::shared_ptr<Course::TileBase>
                                   &target) const;
};
} // Namespace Student

#endif // STUDENTHEADQUARTER_H
