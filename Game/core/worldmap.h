#ifndef WORLDMAP_H
#define WORLDMAP_H
#include "tiles/tilebase.h"

namespace Student {

class Worldmap
{
public:
    Worldmap(int map_width, int map_height);
    ~Worldmap();
    int get_width();
    int get_height();

    std::vector<std::shared_ptr<Course::TileBase>> map_tiles;

private:
    int width_;
    int height_;

};

} // End namespace
#endif // WORLDMAP_H
