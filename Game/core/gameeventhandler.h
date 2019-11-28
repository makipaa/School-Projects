#ifndef GAMEEVENTHANDLER_H
#define GAMEEVENTHANDLER_H

#include "interfaces/igameeventhandler.h"
#include "core/gameobject.h"
#include "core/player.h"
#include "core/basicresources.h"
#include "core/worldgenerator.h"
#include "objectmanager.h"


namespace Student {

class GameEventHandler : public Course::iGameEventHandler
{
public:
    GameEventHandler();

    virtual ~GameEventHandler() = default;

    virtual bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                Course::BasicResource resource,
                                int amount);

    virtual bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                 Course::ResourceMap resources);

    void add_player(std::vector<std::shared_ptr<Student::Player>> players);

    void setObjectManager(std::shared_ptr<Student::ObjectManager> objM);

    void new_round();

    void changeTurn();

    int getRoundNumber();

    std::shared_ptr<Student::Player> getPlayerInTurn();

    Course::ResourceMap resourcemapMakeNegative
        (Course::ResourceMap resourcemap);

    std::map<std::string, int> getScores();

private:   
    std::vector<std::shared_ptr<Student::Player>> players_ = {};
    std::shared_ptr<Student::Player> playerInTurn_;
    std::shared_ptr<Student::ObjectManager> objM_;

    int roundNumber_ = 1;
    int countScore(std::shared_ptr<Student::Player> player);
};
} // Namespace Student

#endif // GAMEEVENTHANDLER_H
