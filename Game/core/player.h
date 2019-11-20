#ifndef PLAYER_H
#define PLAYER_H
#include "core/playerbase.h"
#include "core/basicresources.h"
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
    QColor getColor();
    bool funcHasBuiltHq();
    void changeHQBuildStatus();

private:
    QColor color_;
    Course::ResourceMap resources_;
    bool hasBuiltHQ = false;

};

} // Namespace

#endif // PLAYER_H
