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
            if (tile->getCoordinate() == coordinate){
                found_tiles.push_back(tile);
                break;
            }
        }
    }

    return found_tiles;
}

void ObjectManager::addBuilding(
        const std::shared_ptr<Course::BuildingBase> &building)
{
    buildings_.push_back(building);
}

void ObjectManager::addWorker(
        const std::shared_ptr<Course::WorkerBase> &worker)
{
    workers_.push_back(worker);
}

std::shared_ptr<Course::BuildingBase> ObjectManager::getBuilding(Course::ObjectId building_id)
{
    for(std::shared_ptr<Course::BuildingBase> building : buildings_){
        if (building->ID == building_id){
            return building;
        }
    }
    return nullptr;
}

std::shared_ptr<Course::WorkerBase> ObjectManager::getWorker(Course::ObjectId workerID)
{
    for(std::shared_ptr<Course::WorkerBase> worker : workers_){
        if (worker->ID == workerID){
            return worker;
        }
    }
    return nullptr;
}


std::vector<std::shared_ptr<Course::BuildingBase> > ObjectManager::getBuildings()
{
    return buildings_;
}

std::vector<std::shared_ptr<Course::TileBase>> ObjectManager::getTiles()
{
    return tiles_;
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(
        const Course::ObjectId &id)
{
    for(std::shared_ptr<Course::TileBase> tile : tiles_){
        if ((*tile).ID == id){
            return tile;
        }
    }
    return nullptr;
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(
        const Course::Coordinate &coordinate)
{
    for(std::shared_ptr<Course::TileBase> tile : tiles_){
        if ((*tile).getCoordinate() == coordinate){
            return tile;
        }
    }
    return nullptr;

}

void ObjectManager::addTiles(
        const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{
    for(std::shared_ptr<Course::TileBase> tile : tiles){
        tiles_.push_back(tile);
    }
}

} // Namespace Student
