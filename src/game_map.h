#ifndef GAME_MAP
#define GAME_MAP
#include "block.h"
class GameMap{
    public:
        GameMap(int width, int height);
        void set_block(int x, int y, Block block);
        Block get_block(int x, int y);
        void print_map();
    private:
        int width;
        int height;
        Block **mapp;
};
#endif