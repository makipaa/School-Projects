#include "gameeventhandler.h"

namespace Student {

GameEventHandler::GameEventHandler()
{

}

void GameEventHandler::add_player(std::vector<std::shared_ptr<Student::Player>> players)
{
   players_ = std::vector<std::shared_ptr<Student::Player>>(players);
   playerInTurn_ = players_.at(0);
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

std::shared_ptr<Student::Player> GameEventHandler::getPlayerInTurn(){
    return playerInTurn_;
}

int GameEventHandler::getRoundNumber(){
    return roundNumber_;
}

} // namespace
