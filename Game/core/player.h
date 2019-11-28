#ifndef PLAYER_H
#define PLAYER_H

#include "core/playerbase.h"
#include "core/basicresources.h"
#include "core/resourcemaps.h"
#include "qcolor.h"


namespace  Student {

class Player : public Course::PlayerBase
{
public:
    Player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject>> objects,
           const QColor color);

    Course::ResourceMap getResources();

    bool modifyResources(Course::ResourceMap resources);

    bool modifyResource(Course::BasicResource resource, int amount);

    bool funcHasBuiltHq();

    void changeHQBuildStatus();

    QColor getColor();

private:
    QColor color_;
    Course::ResourceMap resources_;
    bool hasBuiltHQ_ = false;

};
} // Namespace Student

#endif // PLAYER_H
