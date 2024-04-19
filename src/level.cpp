#include "level.h"
#include "game_map.h"
#include "block.h"
#include <bits/stdc++.h>
Level::Level(int level){
    this->level=level;
    this->game_map=random_generate(level);
    this->game_map.set_player(0,0);
    this->game_map.init_targetcount();
    this->game_map.init_pipecount();
    this->game_map.init_sources();
}
Level::Level(){
    this->level=0;
    this->game_map=GameMap(3,3);
}
//ANSI COLOR CODE
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
int Level::Run(){
    system("clear");
    while(1)
    {
        game_map.print_map(0);
        std::cout<<"Targets activated: "<<game_map.get_targets_activated()<<"/"<<game_map.get_targetcount()<<std::endl;
        std::cout<<"Pipes activated: "<<game_map.get_pipes_activated()<<"/"<<game_map.get_pipecount()<<std::endl;
        std::cout<<"Press 'w' to move up, 's' to move down, 'a' to move left, 'd' to move right,\n 'l' to rotate left, 'r' to rotate right,\n 'q' to quit."<<std::endl;
        char c;
        c=getchar();
        system("clear");
        int px=game_map.get_playerx();
        int py=game_map.get_playery();
        int width=game_map.get_width();
        int height=game_map.get_height();
        switch(c){
            case 'w':
                px=(px-1+height)%height;
                this->game_map.set_player(px,py);
                break;
            case 's':
                px=(px+1)%height;
                this->game_map.set_player(px,py);
                break;
            case 'a':
                py=(py-1+width)%width;
                this->game_map.set_player(px,py);
                break;
            case 'd':
                py=(py+1)%width;
                this->game_map.set_player(px,py);
                break;
            case 'q':
                std::cout<<"Are you sure to quit? (y/n)";
                char cc;
                std::cin>>cc;
                if(cc=='y'){
                    system("clear");
                    std::cout<<"You have quit the game. Press any key to reveal the answer."<<std::endl;
                    getchar();
                    system("clear");
                    game_map.print_map(1);
                    std::cout<<"Press any key to continue."<<std::endl;
                    std::cin.get();
                    return this->game_map.check_winstate();
                }
                break;
            case 'l':
                {
                    Block blk1=this->game_map.get_block(px,py,0);
                    blk1.rotate(0);
                    this->game_map.set_block(px,py,blk1,0);
                    break;
                }
            case 'r':
                {
                    Block blk2=this->game_map.get_block(px,py,0);
                    blk2.rotate(1);
                    this->game_map.set_block(px,py,blk2,0);
                    break;
                }
        }
        if(this->game_map.check_winstate()==2){
            return 2;
        }
    }

}