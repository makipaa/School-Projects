#include "studentHeadQuarters.h"


namespace Student {

StudentHeadQuarters::StudentHeadQuarters(
        const std::shared_ptr<GameEventHandler>& eventhandler,
        const std::shared_ptr<ObjectManager>& objectmanager,
        const std::shared_ptr<Course::PlayerBase>& owner,
        const int& tilespaces,
        const Course::ResourceMap& buildcost,
        const Course::ResourceMap& production
        ):
    HeadQuarters(
        eventhandler,
        objectmanager,
        owner,
        tilespaces,
        buildcost,
        production
        )
{
}

bool StudentHeadQuarters::canBePlacedOnTile(
        const std::shared_ptr<Course::TileBase> &target) const
{
    return target->getType() != "Water";
}

} // Namespace Student

