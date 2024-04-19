#include "block.h"
#include "game_map.h"
#include "level.h"
#include<bits/stdc++.h>
//ANSI COLOR CODE
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
void special_output(std::string s, std::string color)
{
    std::cout << color;
    for (int i = 0; i < s.length(); i++)
    {
        std::cout << s[i] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
void initialize_tutorial()
{
    Level tutorial;
    std::cout<<"Initializing..."<<std::endl;
    tutorial.game_map.init_tutorial();
    special_output("Welcome to the tutorial!"," ");
    special_output("In this game, you will be given a map with some \033[31msources\033[0m, \033[34mtargets\033[0m and \033[33mpipes\033[0m."," ");
    special_output("Your goal is to connect all the \033[34mtargets\033[0m to the \033[31msources\033[0m by rotating the \033[33mpipes\033[0m."," ");
    special_output("You can move the player using 'w','a','s','d' and rotate the pipe using 'l' and 'r'."," ");
    special_output("Let's start the tutorial!"," ");
    std::cout<<"Press any key to continue"<<std::endl;
    std::cin.get();
    system("clear");
    tutorial.game_map.print_map(0);
    special_output("This is the game map."," ");
    special_output("The square you are currently on is highlighted by a \033[33myellow square\033[0m."," ");
    special_output("The \033[31msources\033[0m are symbols with \033[34m'S'\033[0m and the \033[34mtargets\033[0m  are symbols with \033[34m'T'\033[0m."," ");
    special_output("\033[33m'-' and '|'\033[0m indicate the directions of the pipes. "," ");
    special_output("'X' indicates a void block which pipes cannot pass through."," ");
    std::cout<<"Press any key to continue"<<std::endl;
    std::cin.get();
    system("clear");
    tutorial.game_map.print_map(0);
    special_output("Pipes and targets that are connected to a source block will be shown in \033[34mBLUE\033[0m."," ");
    special_output("The connection can go through the edge of the map and reach the other side.",YELLOW);
    special_output("HINT: The top-left Target's pipe needs to face \033[33mup\033[0m for you to complete this level."," ");
    special_output("A \033[34mBASIC\033[0m completion of a level is when all targets are \033[34mBLUE\033[0m.","");
    special_output("Once \033[34mBASIC\033[0m completion is reached, you can press q to quit and the level is considered complete.","");
    special_output("However, you may also go for \033[33mPERFECT\033[0m completion, which is to activate all targets and pipes.","");
    special_output("Now, try to complete the level!"," ");
    std::cout<<"Press any key to continue"<<std::endl;
    std::cin.get();
    switch(tutorial.Run())
    {
        case 0:
            break;
        case 1:
            special_output("You have achieved \033[34mBASIC\033[0m completion. "," ");
            break;
        case 2:
            special_output("You have achieved \033[33mPERFECT\033[0m completion! Well done!"," ");
            break;
    }
    std::cout<<"Press any key to continue"<<std::endl;
    std::cin.get();
    system("clear");
    special_output("Congratulations! You have completed the tutorial!"," ");
    special_output("Every level except the tutorial will be randomly generated. You will have a unique experience each time you play."," ");
    special_output("There are 4 different levels of difficulty, each being exponentially more difficult than the previous."," ");
    special_output("Good luck and have fun!"," ");
    special_output("Press any key to start the game"," ");
    std::cin.get();
    system("clear");
}
int main()
{
    system("stty -icanon");
    srand(time(0));
    std::cout<<"-----------------------"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout<<"|"<<RED<<" I N F I N I "<<BLUE<<"F L O W"<<RESET<<" |"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout<<"-----------------------"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout<<"ENGG1340 Group 99"<<std::endl;
    std::cout<<"Press any key to start the game"<<std::endl;
    std::cin.get();
    system("clear");
    std::cout<<"Start tutorial? (y/n)"<<std::endl;
    char cc;
    std::cin>>cc;
    if(cc=='y'){
        initialize_tutorial();
    }
    system("clear");
    int difficulty_unlocked[4]={1,0,0,0};
    while(1)
    {
        int selection=0;
        char c;
        std::string diff_descriptions[4]={
            "Map Size: 4x4 to 5x5\n Difficulty index: 1-8",
            "Map Size: 6x6 to 7x7\n Difficulty index: 9-24",
            "Map Size: 8x8 to 10x10\n Difficulty index: 25-63",
            "Map Size: 11x11 to 15x15\n Difficulty index: 64-168"
        };
        std::string diff_names[4]={"EASY","NORMAL","HARD","INSANE"};
        std::string diff_colors[4]={GREEN,YELLOW,RED,MAGENTA};
        while(1){
            std::cout<<"Select difficulty level:"<<std::endl;
            std::cout<<"Use w/s to navigate and press enter to select, q to quit."<<std::endl;
            for(int i=0;i<4;i++){
                if(i==selection)std::cout<<YELLOW<<"> ";
                else std::cout<<"  ";
                std::cout<<diff_colors[i]<<diff_names[i]<<RESET<<std::endl;
                std::cout<<diff_descriptions[i]<<std::endl;
                if(i==selection)std::cout<<RESET;
                if(difficulty_unlocked[i]==0)std::cout<<"(Locked: Requires \033[34mBASIC\033[0m completion on previous difficulty level.)\n"<<std::endl;
                else std::cout<<std::endl;
            }
            c=getchar();
            if(c=='w'){
                selection=(selection-1+4)%4;
            }
            else if(c=='s'){
                selection=(selection+1)%4;
            }
            else if(c=='\n'){
                break;
            }
            else if(c=='q'){
                special_output("Thanks for playing!"," ");
                return 0;
            }
            system("clear");
        }
        if(difficulty_unlocked[selection]==0){
            special_output("This difficulty level is locked. Please complete the previous difficulty level first."," ");
            std::cout<<"Press any key to continue"<<std::endl;
            std::cin.get();
            system("clear");
            continue;
        }
        int difficulty,lower,upper;
        switch(selection){
            case 0:
                lower=1;
                upper=8;
                break;
            case 1:
                lower=9;
                upper=24;
                break;
            case 2:
                lower=25;
                upper=63;
                break;
            case 3:
                lower=64;
                upper=168;
                break;
        }
        difficulty=rand()%(upper-lower+1)+lower;
        Level level(difficulty);
        system("clear");
        switch(level.Run())
        {
            case 0:
                break;
            case 1:
                special_output("You have achieved \033[34mBASIC\033[0m completion. "," ");
                if(selection<3 and difficulty_unlocked[selection+1]==0){
                    special_output("You have unlocked the next difficulty level!"," ");
                    difficulty_unlocked[selection+1]=1;}
                break;
            case 2:
                special_output("You have achieved \033[33mPERFECT\033[0m completion! Well done!"," ");
                if(selection<3 and difficulty_unlocked[selection+1]==0){
                    special_output("You have unlocked the next difficulty level!"," ");
                    difficulty_unlocked[selection+1]=1;}
                break;
        }
    }
}

#undef RED
#undef GREEN
#undef YELLOW
#undef BLUE
#undef MAGENTA
#undef CYAN
#undef RESET