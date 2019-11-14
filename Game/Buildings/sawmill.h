#ifndef SAWMILL_H
#define SAWMILL_H


#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "gameeventhandler.h"
#include "objectmanager.h"

namespace Student {

class Sawmill : public Course::BuildingBase
{
public:

    Sawmill() = delete;

    explicit Sawmill(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Course::ConstResourceMaps::FARM_BUILD_COST,
            const Course::ResourceMap& production = Course::ConstResourceMaps::FARM_PRODUCTION
            );

    virtual ~Sawmill() = default;


    virtual std::string getType() const override;

}; // class Sawmill

} // namespace Student


#endif // SAWMILL_H
