#include "objectmanager.h"

namespace Student {


ObjectManager::ObjectManager()
{

}

std::vector<std::shared_ptr<Course::TileBase>> ObjectManager::getTiles
            (const std::vector<Course::Coordinate> &coordinates)
{
    std::vector<std::shared_ptr<Course::TileBase>> found_tiles;

    for(Course::Coordinate coordinate : coordinates){
        for(std::shared_ptr<Course::TileBase> tile : tiles_){
            if ((*tile).getCoordinate() == coordinate){
                found_tiles.push_back(tile);
                break;
            }
        }
    }

    return found_tiles;
}

std::vector<std::shared_ptr<Course::TileBase>> ObjectManager::getTiles()
{
    return tiles_;
}


std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::ObjectId &id)
{
    for(std::shared_ptr<Course::TileBase> tile : tiles_){
        if ((*tile).ID == id){
            return tile;
        }
    }
    return nullptr;
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{
    for(std::shared_ptr<Course::TileBase> tile : tiles_){
        if ((*tile).getCoordinate() == coordinate){
            return tile;
        }
    }
    return nullptr;

}

void ObjectManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{
    for(std::shared_ptr<Course::TileBase> tile : tiles){
        tiles_.push_back(tile);
    }
}



} // student
