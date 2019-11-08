#include "gameeventhandler.h"


namespace Student {

GameEventHandler::GameEventHandler()
{

}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                       Course::ResourceMap resources)
{
    Course::ResourceMap result_map = Course::mergeResourceMaps
                                     (resources_[player], resources);

    for(auto resourse : result_map){
        if (resourse.second < 0){
            return false;
        }
    }

    resources_[player] = result_map;
    return true;
}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                      Course::BasicResource resource, int amount)
{
    if (resources_[player][resource] - amount < 0){
        resources_[player][resource] -= amount;
        return true;
    }

    else{
        return false;
    }

}

} // namespace
