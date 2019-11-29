#ifndef LUMBERJACK_H
#define LUMBERJACK_H

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "interfaces/igameeventhandler.h"
#include "tiles/tilebase.h"


namespace Student {

/**
 * @brief The Lumberjack class represents a lumberjack in the game.
 *
 * Lumberjack has following production-efficiency: \n
 * * Money - 0.25 \n
 * * Food - 5.00 \n
 * * Wood - 0.75 \n
 * * Stone - 5.00 \n
 *
 * Lumberjack consumes money, food, a lot of wood and stone. \n
 * Resourcefoucs on wood.
 */
class Lumberjack : public Course::WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Lumberjack() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler Points to the GameEventHandler.
     * @param objectmanager Points to the GameEventHandler.
     * @param owner Points to the owning player.
     */
    Lumberjack(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& cost =
                Course::ConstResourceMaps::LUMBERJACK_RECRUITMENT_COST,
            const Course::ResourceMapDouble& efficiency =
                Course::ConstResourceMaps::LUMBERJACK_WORKER_EFFICIENCY
            );

    /**
     * @brief Default destructor.
     */
    ~Lumberjack() = default;

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

#endif // LUMBERJACK_H
