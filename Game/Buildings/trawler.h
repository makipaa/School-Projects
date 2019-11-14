#ifndef TRAWLER_H
#define TRAWLER_H


#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "gameeventhandler.h"
#include "objectmanager.h"

namespace Student {

class Trawler : public Course::BuildingBase
{
public:

    Trawler() = delete;

    explicit Trawler(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Course::ConstResourceMaps::FARM_BUILD_COST,
            const Course::ResourceMap& production = Course::ConstResourceMaps::FARM_PRODUCTION
            );

    virtual ~Trawler() = default;


    virtual std::string getType() const override;

}; // class Trawler

} // namespace Student


#endif // TRAWLER_H
