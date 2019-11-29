#ifndef WATER_H
#define WATER_H

#include "tiles/tilebase.h"


namespace Student {

/**
 * @brief The Water class represents Water in the gameworld.
 *
 * Water has BasicProduction: \n
 * * Money = 2
 * * Food = 5
 * * Wood = 0
 * * Stone = 0
 */
class Water : public Course::TileBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Water() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the GameEventHandler.
     * @param objectmanager points to the ObjetManager.
     */
    Water(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production =
                Course::ConstResourceMaps::WATER_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Water() = default;

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

#endif // WATER_H
