#ifndef GAMEEVENTHANDLER_H
#define GAMEEVENTHANDLER_H

#include "interfaces/igameeventhandler.h"
#include "core/gameobject.h"
#include "core/player.h"
#include "core/basicresources.h"
#include "core/worldgenerator.h"


namespace Student {

class GameEventHandler : public Course::iGameEventHandler
{

public:

    GameEventHandler();

    virtual ~GameEventHandler() = default;

    virtual bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                Course::BasicResource resource,
                                int amount)=0;

    virtual bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                 Course::ResourceMap resources)=0;

    void add_players(std::vector<std::shared_ptr<Student::Player>> players);

    void new_round();

    void changeTurn();

    std::shared_ptr<Student::Player> getPlayerInTurn();

    int getRoundNumber();

private:
    std::vector<std::shared_ptr<Student::Player>> players_ = {};
    std::shared_ptr<Student::Player> playerInTurn_ = players_[0];

    int roundNumber_ = 1;
};
}
#endif // GAMEEVENTHANDLER_H
