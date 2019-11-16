#ifndef MINER_H
#define MINER_H

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "interfaces/igameeventhandler.h"
#include "Student_tiles/water.h"

class Miner : public Course::WorkerBase
{
public:
    Miner() = delete;

    Miner(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& cost =
                Course::ConstResourceMaps::BW_RECRUITMENT_COST,
            const Course::ResourceMapDouble& efficiency =
                Course::ConstResourceMaps::BW_WORKER_EFFICIENCY
            );
    ~Miner() = default;

    virtual const Course::ResourceMapDouble tileWorkAction();

    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    virtual std::string getType() const override;



};

#endif // MINER_H