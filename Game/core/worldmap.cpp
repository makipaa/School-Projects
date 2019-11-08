#include "worldmap.h"

namespace Student {

Worldmap::Worldmap(int map_width, int map_height)
{
    height_ = map_height;
    width_ = map_width;
}

int Worldmap::get_width()
{
    return width_;
}

int Worldmap::get_height()
{
    return height_;
}

} //namespace
