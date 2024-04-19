#ifndef GAME_MAP
#define GAME_MAP
#include "block.h"
class GameMap{
    public:
        GameMap(int width, int height);
        void set_block(int x, int y, Block block, int query);
        Block get_block(int x, int y, int query); //query=0: game map; query=1: answer
        void print_map(int query);
        void set_player(int x, int y);
    private:
        int width;
        int height;
        Block **mapp;
        int playerx;
        int playery;
        Block **mapp_answer;
};

GameMap random_generate(int level);
#endif