#include "game_map.h"
#include "block.h"
#include <bits/stdc++.h>

//ANSI COLOR CODE
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

//BACKGROUND COLOR
#define BRED "\033[41m"
#define BGREEN "\033[42m"
#define BYELLOW "\033[43m"
#define BBLUE "\033[44m"
#define BMAGENTA "\033[45m"
#define BCYAN "\033[46m"
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

void GameMap::set_block(int x, int y, Block block, int query){
    if(query==0)mapp[x][y] = block;
    else if(query==1) mapp_answer[x][y]=block;
}
Block GameMap::get_block(int x, int y, int query){
    if(query==0)return mapp[x][y];
    else if(query==1)return mapp_answer[x][y];
}

void GameMap::print_map(int query){
    int**connectivity=new int*[height];
    Block**mapp_print=new Block*[height];
    for(int i=0;i<height;i++){
        connectivity[i]=new int[width];
        mapp_print[i]=new Block[width];
        for(int j=0;j<width;j++){
            connectivity[i][j]=0;
            if(query==0)mapp_print[i][j]=mapp[i][j];
            else if(query==1)mapp_print[i][j]=mapp_answer[i][j];
        }
    }
    //bfs to find connected blocks
    std::queue<std::pair<int,int> >q;
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            if(mapp_print[i][j].get_type()==1){
                q.push(std::make_pair(i,j));
                connectivity[i][j]=1;
            }
    while(!q.empty()){
        std::pair<int,int>cur=q.front();
        q.pop();
        int posx=cur.first,posy=cur.second;
        int dy[4]={-1,0,1,0},dx[4]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int new_x=(posx+dx[i]+height)%height,new_y=(posy+dy[i]+width)%width;
            if(mapp_print[new_x][new_y].get_type()!=3 and connectivity[new_x][new_y]==0){
                int* direction_a=mapp_print[posx][posy].get_connect_directions(),*direction_b=mapp_print[new_x][new_y].get_connect_directions();
                if(direction_a[i]==1 and direction_b[(i+2)%4]==1){
                    connectivity[new_x][new_y]=1;
                    q.push(std::make_pair(new_x,new_y));
                }
            }
        }
    }
    //use 3x3 to represent a block
    for(int i=0;i<height;i++){
        for(int k=0;k<3;k++){
            for(int j=0;j<width;j++){
                bool playerblock=false,connected=false;
                if(i==playerx and j==playery and k==1)playerblock=true;
                if(connectivity[i][j]==1)connected=true;
                switch(k){
                    case 0:
                        if(playerblock)std::cout<<BGREEN;
                        std::cout<<" ";
                        if(playerblock)std::cout<<RESET;
                        if(connected)std::cout<<BLUE;
                        if(mapp_print[i][j].get_connect_direction(1)==1)std::cout<<"|";
                        else std::cout<<" ";
                        if(connected)std::cout<<RESET;
                        if(playerblock)std::cout<<BGREEN;
                        std::cout<<" ";
                        if(playerblock)std::cout<<RESET;
                        break;
                    case 1:
                        if(connected)std::cout<<BLUE;
                        if(mapp_print[i][j].get_connect_direction(0)==1)std::cout<<"-";
                        else std::cout<<" ";
                        if(mapp_print[i][j].get_type()==1)std::cout<<"S";
                        else if(mapp_print[i][j].get_type()==2)std::cout<<"T";
                        else if(mapp_print[i][j].get_type()==3)std::cout<<"X";
                        else std::cout<<".";
                        if(mapp_print[i][j].get_connect_direction(2)==1)std::cout<<"-";
                        else std::cout<<" ";
                        if(connected)std::cout<<RESET;
                        break;
                    case 2:
                        if(playerblock)std::cout<<BGREEN;
                        std::cout<<" ";
                        if(playerblock)std::cout<<RESET;
                        if(connected)std::cout<<BLUE;
                        if(mapp_print[i][j].get_connect_direction(3)==1)std::cout<<"|";
                        else std::cout<<" ";
                        if(connected)std::cout<<RESET;
                        if(playerblock)std::cout<<BGREEN;
                        std::cout<<" ";
                        if(playerblock)std::cout<<RESET;
                        break;
                }
            }
            std::cout<<std::endl;
        }
    }
    for(int i=0;i<height;i++){
        delete[] connectivity[i];
        delete[] mapp_print[i];
    }
}
GameMap random_generate(int level){
    int n=int(sqrt(level))+3;
    GameMap game_map(n,n);
    //select random spots for void
    int void_count=rand()%(n-2)+int((n-2)*(n-2)/7);
    int source_count=rand()%std::max(int(n*n/50),1)+int(n*n/36);
    int target_count=n+rand()%std::max(int((n-2)*(n-2)/6),1);
    for(int i=0;i<void_count;i++){
        int x=rand()%n;
        int y=rand()%n;
        Block block(3);
        if(game_map.get_block(x,y,1).get_type()==3)
            i--;
        else
            game_map.set_block(x,y,block,1);
    }
    //select random spots for source
    for(int i=0;i<source_count;i++){
        int x=rand()%n;
        int y=rand()%n;
        Block block(1);
        if(game_map.get_block(x,y,1).get_type()==3 or game_map.get_block(x,y,1).get_type()==1)
            i--;
        else
            game_map.set_block(x,y,block,1);
    }
    bool found=false;
    int dy[4]={-1,0,1,0},dx[4]={0,-1,0,1};
    int**visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[n];
        for(int j=0;j<n;j++){
            if(game_map.get_block(i,j,1).get_type()==3 or game_map.get_block(i,j,1).get_type()==1)
                visited[i][j]=1;
            else
                visited[i][j]=0;
        }
    }
    //generate path until no empty spaces
    while(1){
        std::vector< std::pair<int, int> >empty_spaces;
        std::vector< std::pair<int, int> >nowpath;
        found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(game_map.get_block(i,j,1).get_type()==-1){
                    empty_spaces.push_back(std::make_pair(i,j));
                    found=true;
                }
            }
        }
        if(!found)break;
        int pos=rand()%empty_spaces.size();
        int posx=empty_spaces[pos].first;
        int posy=empty_spaces[pos].second;
        int originx=posx,originy=posy;
        Block block(2);
        game_map.set_block(posx,posy,block,1);
        nowpath.push_back(std::make_pair(posx,posy));
        target_count--;
        while(1){
            std::vector<int>possible_directions;
            visited[posx][posy]=2;
            for(int i=0;i<4;i++){
                int new_x=(posx+dx[i]+n)%n,new_y=(posy+dy[i]+n)%n;
                std::cout<<new_x<<" "<<new_y<<"\n";
                if(game_map.get_block(new_x,new_y,1).get_type()!=3 and visited[new_x][new_y]!=2){
                    if(game_map.get_block(new_x,new_y,1).get_type()==-1)
                        possible_directions.push_back(i);
                    else if(game_map.get_block(new_x,new_y,1).get_type()==2){
                        if(target_count>=0)continue;
                        else possible_directions.push_back(i);
                    }
                    else if(game_map.get_block(new_x,new_y,1).get_type()==0)
                    {
                        int degree=game_map.get_block(new_x,new_y,1).get_degree();
                        if(degree<3)possible_directions.push_back(i);
                    }
                }
            }
            if(possible_directions.size()==0){
                if(posx==originx and posy==originy){
                    game_map.set_block(posx,posy,Block(3),1);
                    break;
                }
                else{
                    Block blk=game_map.get_block(posx,posy,1);
                    blk.set_type(1);
                    game_map.set_block(posx,posy,blk,1);
                    break;
                }
            }
            int direction=possible_directions[rand()%possible_directions.size()];
            int new_x=(posx+dx[direction]+n)%n,new_y=(posy+dy[direction]+n)%n;
            Block cur=game_map.get_block(posx,posy,1),nxt=game_map.get_block(new_x,new_y,1);
            if(cur.get_type()==1)break;
            cur.set_connect_direction(direction,1);
            nxt.set_connect_direction((direction+2)%4,1);
            if(cur.get_type()==-1)cur.set_type(0);
            if(nxt.get_type()==-1 or nxt.get_type()==2)nxt.set_type(0);
            game_map.set_block(posx,posy,cur,1);
            game_map.set_block(new_x,new_y,nxt,1);
            nowpath.push_back(std::make_pair(new_x,new_y));
            posx=new_x;
            posy=new_y;
            if(visited[posx][posy]==1)break; //path merged
        }
        for(int i=0;i<nowpath.size();i++){
            visited[nowpath[i].first][nowpath[i].second]=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Block blk=game_map.get_block(i,j,1);
            int rotation=rand()%4;
            for(int k=0;k<rotation;k++){
                blk.rotate(1);
            }
            game_map.set_block(i,j,blk,0);
        }
    }
    return game_map;
}

void GameMap::set_player(int x, int y){
    playerx=x;
    playery=y;
}