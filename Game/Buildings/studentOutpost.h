#ifndef STUDENTOUTPOST_H
#define STUDENTOUTPOST_H

#include "buildings/outpost.h"
#include "core/resourcemaps.h"
#include "core/gameeventhandler.h"
#include "core/objectmanager.h"


namespace Student {

class StudentOutpost : public Course::Outpost
{
public:
    StudentOutpost() = delete;

    explicit StudentOutpost(
            const std::shared_ptr<GameEventHandler>& eventhandler,
            const std::shared_ptr<ObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
                Course::ConstResourceMaps::OUTPOST_BUILD_COST,
            const Course::ResourceMap& production =
                Course::ConstResourceMaps::OUTPOST_PRODUCTION
            );

    virtual ~StudentOutpost() = default;

    virtual bool canBePlacedOnTile(const std::shared_ptr<Course::TileBase>
                                   &target) const;
};
} // Namespace Student

#endif // STUDENTOUTPOST_H
