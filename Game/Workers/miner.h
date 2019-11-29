#ifndef MINER_H
#define MINER_H

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "interfaces/igameeventhandler.h"
#include "tiles/tilebase.h"


namespace Student {

/**
 * @brief The Miner class represents a miner in the game.
 *
 * Miner has following production-efficiency: \n
 * * Money - 0.25 \n
 * * Food - 1.00 \n
 * * Wood - 0.75 \n
 * * Stone - 5.00 \n
 *
 * Miner consumes money, food, wood and a lot of stone. \n
 * Resourcefoucs on stone.
 */
class Miner : public Course::WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Miner() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler Points to the GameEventHandler.
     * @param objectmanager Points to the GameEventHandler.
     * @param owner Points to the owning player.
     */
    Miner(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& cost =
                Course::ConstResourceMaps::MINER_RECRUITMENT_COST,
            const Course::ResourceMapDouble& efficiency =
                Course::ConstResourceMaps::MINER_WORKER_EFFICIENCY
            );

    /**
     * @brief Default destructor.
     */
    ~Miner() = default;

    /**
     * @copydoc WorkerBase::doSpecialAction()
     */
    virtual void doSpecialAction() override;

    /**
     * @copydoc WorkerBase::tileWorkAction()
     */
    virtual const Course::ResourceMapDouble tileWorkAction() override;

    /**
     * @copydoc WorkerBase::canBePlacedOnTile()
     */
    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    /**
     * @copydoc WorkerBase::getType()
     */
    virtual std::string getType() const override;

};
} // Namespace Student

#endif // MINER_H
