#ifndef LEVEL_H
#define LEVEL_H

#include "game_map.h"
#include "block.h"

class Level{
    public:
        Level(int level);
        Level();
        int Run();
        GameMap game_map;
    private:
        int level;
};

#endif