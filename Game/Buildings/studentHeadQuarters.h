#ifndef STUDENTHEADQUARTER_H
#define STUDENTHEADQUARTER_H

#include "buildings/headquarters.h"
#include "core/resourcemaps.h"
#include "core/gameeventhandler.h"
#include "core/objectmanager.h"


namespace Student {

class StudentHeadQuarters : public Course::HeadQuarters
{
public:
    StudentHeadQuarters() = delete;

    explicit StudentHeadQuarters(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
                Course::ConstResourceMaps::HQ_BUILD_COST,
            const Course::ResourceMap& production =
                Course::ConstResourceMaps::HQ_PRODUCTION
            );

    virtual ~StudentHeadQuarters() = default;

    virtual bool canBePlacedOnTile(const std::shared_ptr<Course::TileBase>
                                   &target) const;
};
} // Namespace Student

#endif // STUDENTHEADQUARTER_H
