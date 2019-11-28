#include "gameeventhandler.h"
#include "iostream"

namespace Student {

GameEventHandler::GameEventHandler()
{

}

void GameEventHandler::addPlayers(std::vector<std::shared_ptr<Student::Player>> players)
{
   players_ = std::vector<std::shared_ptr<Student::Player>>(players);
   playerInTurn_ = players_.at(0);
}

std::vector<std::shared_ptr<Player> > GameEventHandler::getPlayers()
{
    return players_;
}

void GameEventHandler::setObjectManager(std::shared_ptr<ObjectManager> objM)
{
    objM_ = objM;
}

void GameEventHandler::new_round()
{
    for (auto tile : objM_->getTiles()){
        if(tile->getOwner()){
            tile->generateResources();
        }
    }

    roundNumber_ ++;

}

void GameEventHandler::changeTurn()
{
    if (playerInTurn_ == players_.back()){
        playerInTurn_ = players_.front();
        this->new_round();
    }
    else{
        for (int i = 0; i < int(players_.size()) - 1; i++){
            if (players_.at(i)->getName() == playerInTurn_->getName()){
                playerInTurn_ = players_.at(i+1);
                break;
            }
        }
    }
}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                       Course::ResourceMap resources)
{
    for (auto found_player : players_){
        if (found_player->getName() == player->getName()){
            return found_player->modifyResources(resources);
        }
    }

    return false;

}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                      Course::BasicResource resource, int amount)
{

    for (auto found_player : players_){
        if (found_player->getName() == player->getName()){
            return found_player->modifyResource(resource, amount);
        }
    }

    return false;
}

Course::ResourceMap GameEventHandler::resourcemapMakeNegative
    (Course::ResourceMap resourcemap)
{
    Course::ResourceMap result = resourcemap;
    for ( std::pair<Course::BasicResource,int> pair : result){
        result[pair.first] = -pair.second;
    }
    return result;
}

std::map<std::string, int> GameEventHandler::getScores()
{
    std::map<std::string, int> scoreMap;
    for (auto player : players_){
        scoreMap[player->getName()] = countScore(player);
    }
    return scoreMap;
}

int GameEventHandler::countScore(std::shared_ptr<Player> player)
{
    int score = 0;
    Course::ResourceMap cumulativeResources;
    cumulativeResources = Course::mergeResourceMaps(player->getResources(), cumulativeResources);
    for (auto object : player->getObjects()){
        if (auto building = std::dynamic_pointer_cast<Course::BuildingBase>(object)){
            cumulativeResources = Course::mergeResourceMaps(building->BUILD_COST, cumulativeResources);
        }
        else if (auto worker = std::dynamic_pointer_cast<Course::WorkerBase>(object)){
            cumulativeResources = Course::mergeResourceMaps(worker->RECRUITMENT_COST, cumulativeResources);
        }
    }
    for (auto resourse : cumulativeResources){
        score += resourse.second;
    }
    return score;

}

std::shared_ptr<Student::Player> GameEventHandler::getPlayerInTurn(){
    return playerInTurn_;
}

int GameEventHandler::getRoundNumber(){
    return roundNumber_;
}

} // namespace
