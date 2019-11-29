#ifndef PLAYER_H
#define PLAYER_H

#include "core/playerbase.h"
#include "core/basicresources.h"
#include "core/resourcemaps.h"
#include "qcolor.h"


namespace  Student {

/**
 * @brief The Player class
 *
 * Handles players resources etc.
 */
class Player : public Course::PlayerBase
{
public:

    /**
     * @brief Constructor for the Class.
     * @param name Name of the player.
     * @param objects  A std::vector of shared-pointers to
     * GameObjects.
     * @param color Player colour.
     * @post Exception Guarantee: No guarantee.
     */
    Player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject>> objects,
           const QColor color);
    /**
     * @brief Default destructor.
     */
    virtual ~Player() = default;

    /**
     * @return Resources of the player.
     * @post Exception Guarantee: No throw.
     */
    Course::ResourceMap getResources();

    bool modifyResources(Course::ResourceMap resources);

    bool modifyResource(Course::BasicResource resource, int amount);

    /**
     * @brief Checks if the player has already built HQ.
     * @return Boolean value whether its built or not.
     */
    bool funcHasBuiltHq();

    /**
     * @brief Changes the build status to true (because only one
     * HQ can be built).
     * @post Exception Guarantee: No guarantee.
     */
    void changeHQBuildStatus();

    /**
     * @return Color of the player.
     * @post Exception Guarantee: No throw.
     */
    QColor getColor();

private:
    QColor color_;
    Course::ResourceMap resources_;
    bool hasBuiltHQ_ = false;

};
} // Namespace Student

#endif // PLAYER_H
