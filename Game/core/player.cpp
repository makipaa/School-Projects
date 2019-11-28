#include "player.h"


namespace Student {

Player::Player(const std::string &name,
               const std::vector<std::shared_ptr<Course::GameObject>> objects,
               const QColor color):
PlayerBase::PlayerBase(name,objects)
{
    color_ = color;
    resources_ = Course::ConstResourceMaps::HQ_BUILD_COST;
}

Course::ResourceMap Player::getResources()
{
    return this->resources_;
}

bool Player::modifyResources(Course::ResourceMap resources)
{
    Course::ResourceMap result_map = Course::mergeResourceMaps
                                     (resources_, resources);

    for(auto resourse : result_map){
        if (resourse.second < 0){
            return false;
        }
    }

    resources_ = result_map;
    return true;
}

bool Player::modifyResource(Course::BasicResource resource, int amount)
{
    if (resources_[resource] + amount >= 0){
        resources_[resource] += amount;
        return true;
    }

    else{
        return false;
    }

}

QColor Player::getColor()
{
    return color_;
}

bool Player::funcHasBuiltHq()
{
    return hasBuiltHQ_;
}

void Player::changeHQBuildStatus()
{
    hasBuiltHQ_ = true;
}

} // Namespace Student

