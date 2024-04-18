#include "block.h"
#include "game_map.h"
#include<bits/stdc++.h>
int main()
{
    Block block(1);
    int connect_directions[4]={1,1,0,0};
    block.set_connect_directions(connect_directions);
    block.rotate(0);
    std::cout<<block.get_type()<<std::endl;
    block.print_directions();

    GameMap game_map(5,5);
    Block block2(1);
    game_map.set_block(1,2,block2);
    game_map.print_map();
    return 0;
}