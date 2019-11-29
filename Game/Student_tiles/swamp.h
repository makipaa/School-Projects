#ifndef SWAMP_H
#define SWAMP_H

#include "tiles/tilebase.h"


namespace Student {

/**
 * @brief The Swamp class represents Swamp in the gameworld.
 *
 * Swamp has BasicProduction: \n
 * * Money = 2
 * * Food = 2
 * * Wood = 1
 * * Stone = 0
 */
class Swamp : public Course::TileBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Swamp() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the GameEventHandler.
     * @param objectmanager points to the ObjetManager.
     */
    Swamp(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 2,
           const Course::ResourceMap& production =
                Course::ConstResourceMaps::SWAMP_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Swamp() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @copydoc BuildingBase::addBuilding()
     */
    void addBuilding(
            const std::shared_ptr<Course::BuildingBase>& building) override;

};
} // Namespace Student

#endif // SWAMP_H
