#ifndef FISHER_H
#define FISHER_H

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "interfaces/igameeventhandler.h"
#include "tiles/tilebase.h"


namespace Student {

/**
 * @brief The Fisher class represents a fisher in the game.
 *
 * Fisher has following production-efficiency: \n
 * * Money - 0.25 \n
 * * Food - 5.00 \n
 * * Wood - 0.75 \n
 * * Stone - 0.50 \n
 *
 * Farmer consumes food, money, wood and a little bit of stone. \n
 * Resourcefoucs on food.
 */
class Fisher : public Course::WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Fisher() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler Points to the GameEventHandler.
     * @param objectmanager Points to the GameEventHandler.
     * @param owner Points to the owning player.
     */
    Fisher(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& cost =
                Course::ConstResourceMaps::FISHER_RECRUITMENT_COST,
            const Course::ResourceMapDouble& efficiency =
                Course::ConstResourceMaps::FISHER_WORKER_EFFICIENCY
            );
    /**
     * @brief Default destructor.
     */
    ~Fisher() = default;

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

#endif // FISHER_H
