#ifndef COBBLESTONE_H
#define COBBLESTONE_H

#include "tiles/tilebase.h"


namespace Student {

/**
 * @brief The Cobblestone class represents Cobblestone in the gameworld.
 *
 * Cobblestone has BasicProduction: \n
 * * Money = 3
 * * Food = 0
 * * Wood = 1
 * * Stone = 5
 * * Ore = 0
 */
class Cobblestone : public Course::TileBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Cobblestone() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the GameEventHandler.
     * @param objectmanager points to the ObjetManager.
     */
    Cobblestone(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 2,
           const Course::ResourceMap& production =
            Course::ConstResourceMaps::COBBLESTONE_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Cobblestone() = default;

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

#endif // COBBLESTONE_H
