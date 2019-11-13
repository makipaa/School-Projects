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

private:
    QColor color_;

};

} // Namespace

#endif // PLAYER_H
