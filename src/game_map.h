#ifndef GAME_MAP
#define GAME_MAP
#include "block.h"
#include <vector>
class GameMap{
    public:
        GameMap(int width, int height);
        GameMap();
        void set_block(int x, int y, Block block, int query);
        Block get_block(int x, int y, int query); //query=0: game map; query=1: answer
        void print_map(int query);
        void set_player(int x, int y);
        int get_playerx();
        int get_playery();
        int get_width();
        int get_height();
        void set_width(int width);
        void set_height(int height);
        int check_winstate(); //0: targets not all activated; 1: targets all activated but not all pipes activated; 2: all pipes activated
        int get_targetcount();
        int get_pipecount();
        int init_targetcount();
        int init_pipecount();
        int get_targets_activated();
        int get_pipes_activated();
        void init_sources();
        void init_tutorial();
    private:
        int width;
        int height;
        Block **mapp;
        int playerx;
        int playery;
        Block **mapp_answer;
        int pipecount;
        int targetcount;
        std::vector<std::pair<int,int>> sources;
};

GameMap random_generate(int level);
#endif