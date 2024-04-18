#include "game_map.h"
#include "block.h"
#include <bits/stdc++.h>

GameMap::GameMap(int width, int height){
    this->width = width;
    this->height = height;
    mapp = new Block*[height];
    mapp_answer = new Block*[height];
    for(int i = 0; i < height; i++){
        mapp[i] = new Block[width];
        mapp_answer[i] = new Block[width];
    }
    this->playerx = 0;
    this->playery = 0;
}

void GameMap::set_block(int x, int y, Block block){
    mapp[x][y] = block;
}

Block GameMap::get_block(int x, int y){
    return mapp[x][y];
}

void GameMap::print_map(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            std::cout<<mapp[i][j].get_type()<<" ";
        }
        std::cout<<std::endl;
    }
}
GameMap GameMap::random_generate(int level){
    int n=int(sqrt(level))+4;
    GameMap game_map(n,n);
    //select random spots for void
    int void_count=rand()%(n-3)+int((n-3)*(n-3)/7);
    int source_count=int(n/4);
    for(int i=0;i<void_count;i++){
        int x=rand()%n;
        int y=rand()%n;
        Block block(3);
        if(game_map.get_block(x,y).get_type()==3)
            i--;
        else
            game_map.set_block(x,y,block);
    }
    std::vector<int> sourcex,sourcey;
    //select random spots for source
    for(int i=0;i<source_count;i++){
        int x=rand()%n;
        int y=rand()%n;
        Block block(1);
        if(game_map.get_block(x,y).get_type()==3 or game_map.get_block(x,y).get_type()==1)
            i--;
        else
            game_map.set_block(x,y,block);
            sourcex.push_back(x);
            sourcey.push_back(y);
    }
    for(int i=0;i<source_count;i++){
        game_map.dfs(sourcex[i],sourcey[i],level,0);
    }
}