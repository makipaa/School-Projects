#ifndef GAMEEVENTHANDLER_H
#define GAMEEVENTHANDLER_H

#include "interfaces/igameeventhandler.h"
#include "core/gameobject.h"
#include "core/player.h"
#include "core/basicresources.h"
#include "core/worldgenerator.h"
#include "objectmanager.h"


namespace Student {

/**
 * @brief The GameEventHandler class
 *
 * Handles games resources, players etc.
 */
class GameEventHandler : public Course::iGameEventHandler
{
public:
    /**
     * @brief Parameterless constructor.
     * @post Exception Guarantee: No guarantee.
     */
    GameEventHandler();

    /**
     * @brief Default destructor.
     */
    virtual ~GameEventHandler() = default;

    /**
     * @copydoc iGameEventHandler::modifyResource()
     */
    virtual bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                Course::BasicResource resource,
                                int amount);

    /**
     * @copydoc iGameEventHandler::modifyResources()
     */
    virtual bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                 Course::ResourceMap resources);

    /**
     * @brief Adds players to the game.
     *
     * Sets the first player in the vector to the player in turn.
     *
     * @param Players to be added.
     * @post Exception Guarantee: Strong guarantee.
     */
    void addPlayers(std::vector<std::shared_ptr<Student::Player>> players);

    std::vector<std::shared_ptr<Student::Player>> getPlayers();

    /**
     * @brief Initializes the object manager.
     * @param objM
     * @post Exception Guarantee: No throw.
     */
    void setObjectManager(std::shared_ptr<Student::ObjectManager> objM);

    /**
     * @brief Checks which tiles are owned, calls a function to generate \n
     * resources for them and starts a new round.
     * @post Exception Guarantee: No guarantee.
     */
    void new_round();

    /**
     * @brief Changes the player in turn.
     * @post Exception Guarantee: No guarantee.
     */
    void changeTurn();

    /**
     * @return Round number.
     * @post Exception Guarantee: No throw.
     */
    int getRoundNumber();

    /**
     * @return Player in turn.
     * @post Exception Guarantee: No throw.
     */
    std::shared_ptr<Student::Player> getPlayerInTurn();

    Course::ResourceMap resourcemapMakeNegative
        (Course::ResourceMap resourcemap);

    /**
     * @return Each players score points.
     * @post Exception Guarantee: No guarantee.
     */
    std::map<std::string, int> getScores();

private:   
    std::vector<std::shared_ptr<Student::Player>> players_ = {};
    std::shared_ptr<Student::Player> playerInTurn_;
    std::shared_ptr<Student::ObjectManager> objM_;

    int roundNumber_ = 1;

    /**
     * @brief Counts score for a player.
     * @param player The player whose score we want to count.
     * @return The result.
     * @post Exception Guarantee: No guarantee.
     */
    int countScore(std::shared_ptr<Student::Player> player);
};
} // Namespace Student

#endif // GAMEEVENTHANDLER_H
