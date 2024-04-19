#include "block.h"
#include "game_map.h"
#include<bits/stdc++.h>
int main()
{
    srand(time(0));
    GameMap game_map=random_generate(1);
    game_map.print_map(1);
    game_map.print_map(0);
    return 0;
}