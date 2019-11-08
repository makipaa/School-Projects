#ifndef GAMEEVENTHANDLER_H
#define GAMEEVENTHANDLER_H

#include "interfaces/igameeventhandler.h"
#include "core/gameobject.h"


namespace Student {

class GameEventHandler : public Course::iGameEventHandler
{

public:

    GameEventHandler();

    virtual ~GameEventHandler() = default;

    virtual bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                Course::BasicResource resource,
                                int amount) = 0;

    virtual bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                 Course::ResourceMap resources) = 0;

};
}
#endif // GAMEEVENTHANDLER_H
