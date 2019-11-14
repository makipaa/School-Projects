#include "sawmill.h"


namespace Student {

Sawmill::Sawmill(const std::shared_ptr<GameEventHandler>& eventhandler,
           const std::shared_ptr<ObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces,
           const Course::ResourceMap& buildcost,
           const Course::ResourceMap& production
           ):
    BuildingBase(
        eventhandler,
        objectmanager,
        owner,
        tilespaces,
        buildcost,
        production
        )
{
}

std::string Sawmill::getType() const
{
    return "Sawmill";
}


} // namespace Student
