#ifndef STUDENTFARM_H
#define STUDENTFARM_H

#include "buildings/farm.h"
#include "core/resourcemaps.h"
#include "core/gameeventhandler.h"
#include "core/objectmanager.h"


namespace Student {

class StudentFarm : public Course::Farm
{
public:
    StudentFarm() = delete;

    explicit StudentFarm(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
                Course::ConstResourceMaps::FARM_BUILD_COST,
            const Course::ResourceMap& production =
                Course::ConstResourceMaps::FARM_PRODUCTION
            );

    virtual ~StudentFarm() = default;

    virtual bool canBePlacedOnTile(const std::shared_ptr<Course::TileBase>
                                   &target) const;
};
} // Namespace Student

#endif // STUDENTFARM_H
