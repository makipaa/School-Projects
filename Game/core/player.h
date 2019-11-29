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

    /**
     * @brief Modifies player's resources with amounts given in a ResourceMap
     * @param resources ResourceMap which has the modifying amounts
     * @note Map with negative values can be used for subtraction
     * @post Exception Guarantee: No throw.
     * @return Returns false if subtraction would make any resource value
     * negative, otherwise returns true.
     */
    bool modifyResources(Course::ResourceMap resources);

    /**
     * @brief Modifies player's specific resource with given amount.
     * @param resource The resource which is modified.
     * @param amount How much resource is modified.
     * @note Map with negative values can be used for subtraction
     * @post Exception Guarantee: No throw.
     * @return Returns false if subtraction would make the resource value
     * negative, otherwise returns true.
     */
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
