#ifndef SWAMP_H
#define SWAMP_H


#include "tiles/tilebase.h"


namespace Student {

class Swamp : public Course::TileBase
{
public:

    Swamp() = delete;

    Swamp(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 2,
           const Course::ResourceMap& production = Course::ConstResourceMaps::SWAMP_BP);

    virtual ~Swamp() = default;

    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

};

} // namespace Student



#endif // SWAMP_H
