#ifndef MINE_H
#define MINE_H


#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "gameeventhandler.h"
#include "objectmanager.h"

namespace Student {

class Mine : public Course::BuildingBase
{
public:

    Mine() = delete;

    explicit Mine(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Course::ConstResourceMaps::FARM_BUILD_COST,
            const Course::ResourceMap& production = Course::ConstResourceMaps::FARM_PRODUCTION
            );

    virtual ~Mine() = default;


    virtual std::string getType() const override;

}; // class Mine

} // namespace Student


#endif // MINE_H
