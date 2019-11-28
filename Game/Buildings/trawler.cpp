#include "trawler.h"


namespace Student {

Trawler::Trawler(const std::shared_ptr<GameEventHandler>& eventhandler,
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

std::string Trawler::getType() const
{
    return "Trawler";
}

bool Trawler::canBePlacedOnTile(
        const std::shared_ptr<Course::TileBase> &target) const
{
    return target->getType() == "Water";
}

} // Namespace Student
