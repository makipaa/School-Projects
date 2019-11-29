#ifndef PEATWORKER_H
#define PEATWORKER_H

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "interfaces/igameeventhandler.h"
#include "tiles/tilebase.h"


namespace Student {

/**
 * @brief The Peatworker class represents a "swamp worker" in the game.
 *
 * Peatworker has following production-efficiency: \n
 * * Money - 5.00 \n
 * * Food - 1.00 \n
 * * Wood - 0.75 \n
 * * Stone - 0.50 \n
 *
 * Peatworker consumes money, food and wood. \n
 * Resourcefoucs on money.
 */
class PeatWorker : public Course::WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    PeatWorker() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler Points to the GameEventHandler.
     * @param objectmanager Points to the GameEventHandler.
     * @param owner Points to the owning player.
     */
    PeatWorker(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& cost =
                Course::ConstResourceMaps::PEATWORKER_RECRUITMENT_COST,
            const Course::ResourceMapDouble& efficiency =
                Course::ConstResourceMaps::PEATWORKER_WORKER_EFFICIENCY
            );

    /**
     * @brief Default destructor.
     */
    ~PeatWorker() = default;

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
} //Namespace Student

#endif // PEATWORKER_H
