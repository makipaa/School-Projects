#ifndef TRAWLER_H
#define TRAWLER_H

#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "core/gameeventhandler.h"
#include "core/objectmanager.h"


namespace Student {

/**
 * @brief This class represents a trawler in the game.
 *
 * Can only be placed in a Water-tile which is
 * owned by the player in turn.
 * Boosts food production.
 */
class Trawler : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Trawler() = delete;

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
    explicit Trawler(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
                Course::ConstResourceMaps::TRAWLER_BUILD_COST,
            const Course::ResourceMap& production =
                Course::ConstResourceMaps::TRAWLER_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Trawler() = default;

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
} // Namespace Student

#endif // TRAWLER_H
