#ifndef COBBLESTONE_H
#define COBBLESTONE_H

#include "tiles/tilebase.h"

namespace Student {

class Cobblestone : public Course::TileBase
{
public:

    Cobblestone() = delete;

    Cobblestone(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 2,
           const Course::ResourceMap& production = Course::ConstResourceMaps::COBBLESTONE_BP);

    virtual ~Cobblestone() = default;

    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

};

} // namespace Student


#endif // COBBLESTONE_H
