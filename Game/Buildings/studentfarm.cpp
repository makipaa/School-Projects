#include "studentfarm.h"

namespace Student {

StudentFarm::StudentFarm(
        const std::shared_ptr<GameEventHandler>& eventhandler,
        const std::shared_ptr<ObjectManager>& objectmanager,
        const std::shared_ptr<Course::PlayerBase>& owner,
        const int& tilespaces,
        const Course::ResourceMap& buildcost,
        const Course::ResourceMap& production
        ):
    Farm(
        eventhandler,
        objectmanager,
        owner,
        tilespaces,
        buildcost,
        production
        )
{
}

bool StudentFarm::canBePlacedOnTile(const std::shared_ptr<Course::TileBase> &target) const
{
    return target->getType() == "Grassland";
}

} // Namespace Student
