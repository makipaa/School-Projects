#ifndef SAWMILL_H
#define SAWMILL_H

#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "core/gameeventhandler.h"
#include "core/objectmanager.h"


namespace Student {

/**
 * @brief This class represents a sawmill in the game.
 *
 * Can only be placed in a Forest-tile which is
 * owned by the player in turn.
 * Boosts wood production.
 */
class Sawmill : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Sawmill() = delete;

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
    explicit Sawmill(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
                Course::ConstResourceMaps::SAWMILL_BUILD_COST,
            const Course::ResourceMap& production =
                Course::ConstResourceMaps::SAWMILL_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Sawmill() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @copydoc BuildingBase::canBePlacedOnTile()
     */
    virtual bool canBePlacedOnTile(const std::shared_ptr<Course::TileBase>
                                   &target) const;

};
} // namespace Student

#endif // SAWMILL_H
