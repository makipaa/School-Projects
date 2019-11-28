#ifndef WATER_H
#define WATER_H

#include "tiles/tilebase.h"


namespace Student {

class Water : public Course::TileBase
{
public:
    Water() = delete;

    Water(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production =
                Course::ConstResourceMaps::WATER_BP);

    virtual ~Water() = default;

    virtual std::string getType() const override;

     void addBuilding(
             const std::shared_ptr<Course::BuildingBase>& building) override;

};
} // Namespace Student

#endif // WATER_H
