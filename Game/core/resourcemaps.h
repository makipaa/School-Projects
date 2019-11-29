#ifndef RESOURCEMAPS_H
#define RESOURCEMAPS_H

#include "core/basicresources.h"

/**
 * @brief This file contains info about buildings,
 * workers, their efficiency and build/recruit cost.
 */
namespace Course {

namespace ConstResourceMaps {

const ResourceMap EMPTY = {};

// Building - Farm
const ResourceMap FARM_BUILD_COST = {
    {BasicResource::MONEY, 50},
    {BasicResource::FOOD, 100},
    {BasicResource::WOOD, 25},
    {BasicResource::STONE, 0}
};
const ResourceMap FARM_PRODUCTION = {
    {BasicResource::MONEY, 1},
    {BasicResource::FOOD, 5}
};

// Building - HeadQuarters
const ResourceMap HQ_BUILD_COST = {
    {BasicResource::MONEY, 750},
    {BasicResource::FOOD, 1000},
    {BasicResource::WOOD, 500},
    {BasicResource::STONE, 250}
};
const ResourceMap HQ_PRODUCTION = {
    {BasicResource::MONEY, 10},
    {BasicResource::FOOD, 2},
};

// Building - Outpost
const ResourceMap OUTPOST_BUILD_COST = {
    {BasicResource::MONEY, 150},
    {BasicResource::FOOD, 200},
    {BasicResource::WOOD, 200},
    {BasicResource::STONE, 25}
};

const ResourceMap OUTPOST_PRODUCTION = {
    {BasicResource::MONEY, -5},
    {BasicResource::FOOD, -2}
};

// Building - Mine
const ResourceMap MINE_BUILD_COST = {
    {BasicResource::MONEY, 75},
    {BasicResource::FOOD, 150},
    {BasicResource::WOOD, 100},
    {BasicResource::STONE, 100}
};

const ResourceMap MINE_PRODUCTION = {
    {BasicResource::MONEY, 5},
    {BasicResource::STONE, 20}
};

// Building - Trawler
const ResourceMap TRAWLER_BUILD_COST = {
    {BasicResource::MONEY, 50},
    {BasicResource::FOOD, 100},
    {BasicResource::WOOD, 200},
    {BasicResource::STONE, 0}

};

const ResourceMap TRAWLER_PRODUCTION = {
    {BasicResource::MONEY, 5},
    {BasicResource::FOOD, 10}
};

// Building - Sawmill
const ResourceMap SAWMILL_BUILD_COST = {
    {BasicResource::MONEY, 50},
    {BasicResource::FOOD, 100},
    {BasicResource::WOOD, 250},
    {BasicResource::STONE, 0}
};

const ResourceMap SAWMILL_PRODUCTION = {
    {BasicResource::MONEY, 5},
    {BasicResource::WOOD, 25}
};

// Worker - BasicWorker
const ResourceMapDouble BW_WORKER_EFFICIENCY = {
    {MONEY, 0.25},
    {FOOD, 1.00},
    {WOOD, 0.75},
    {STONE, 0.50}
};

const ResourceMap BW_RECRUITMENT_COST = {
    {MONEY, 10},
    {FOOD, 25},
    {WOOD, 0},
    {STONE, 0},
};

// Worker - Fisher
const ResourceMapDouble FISHER_WORKER_EFFICIENCY = {
    {MONEY, 0.25},
    {FOOD, 5.00},
    {WOOD, 0.75},
    {STONE, 0.50}
};

const ResourceMap FISHER_RECRUITMENT_COST = {
    {MONEY, 10},
    {FOOD, 25},
    {WOOD, 35},
    {STONE, 5}
};

// Worker - Farmer
const ResourceMapDouble FARMER_WORKER_EFFICIENCY = {
    {MONEY, 0.25},
    {FOOD, 5.00},
    {WOOD, 0.75},
    {STONE, 0.50},
};

const ResourceMap FARMER_RECRUITMENT_COST = {
    {MONEY, 10},
    {FOOD, 25},
    {WOOD, 50},
    {STONE, 5}
};

// Worker - Miner
const ResourceMapDouble MINER_WORKER_EFFICIENCY = {
    {MONEY, 0.25},
    {FOOD, 1.00},
    {WOOD, 0.75},
    {STONE, 5.00}
};

const ResourceMap MINER_RECRUITMENT_COST = {
    {MONEY, 10},
    {FOOD, 25},
    {WOOD, 35},
    {STONE, 60}
};

// Worker - PeatWorker
const ResourceMapDouble PEATWORKER_WORKER_EFFICIENCY = {
    {MONEY, 5.00},
    {FOOD, 1.00},
    {WOOD, 0.75},
    {STONE, 0.50}
};

const ResourceMap PEATWORKER_RECRUITMENT_COST = {
    {MONEY, 10},
    {FOOD, 35},
    {WOOD, 35},
    {STONE, 0},
};

// Worker - Lumberjack
const ResourceMapDouble LUMBERJACK_WORKER_EFFICIENCY = {
    {MONEY, 0.25},
    {FOOD, 5.00},
    {WOOD, 0.75},
    {STONE, 5.00},
};

const ResourceMap LUMBERJACK_RECRUITMENT_COST = {
    {MONEY, 10},
    {FOOD, 25},
    {WOOD, 80},
    {STONE, 45}
};

const ResourceMap FOREST_BP = {
    {MONEY, 1},
    {FOOD, 3},
    {WOOD, 5},
    {STONE, 1},
};

const ResourceMap GRASSLAND_BP = {
    {MONEY, 2},
    {FOOD, 5},
    {WOOD, 1},
    {STONE, 1},
};

const ResourceMap SWAMP_BP = {
    {MONEY, 2},
    {FOOD, 2},
    {WOOD, 1},
    {STONE, 0},
};

const ResourceMap COBBLESTONE_BP = {
    {MONEY, 3},
    {FOOD, 0},
    {WOOD, 1},
    {STONE, 5},
};

const ResourceMap WATER_BP = {
    {MONEY, 2},
    {FOOD, 5},
    {WOOD, 0},
    {STONE, 0},
};
}
}

#endif // RESOURCEMAPS_H
