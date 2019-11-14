#include "player.h"

namespace Student {

Player::Player(const std::string &name,
               const std::vector<std::shared_ptr<Course::GameObject>> objects,
               const QColor color):
PlayerBase::PlayerBase(name,objects)
{
    color_ = color;
}




} // Namespace

