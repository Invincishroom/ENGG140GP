#include<bits/stdc++.h>
#include "block.h"
Block::Block(){
    this->type=-1;
    for(int i=0;i<4;i++)
        connect_directions[i]=0;
    }
Block::Block(int type){
    this->type=type;
    for(int i=0;i<4;i++){
        connect_directions[i]=0;
    }
};
int Block::get_type(){
    return type;
};
void Block::set_type(int type){
    this->type=type;
};
void Block::set_connect_directions(int connect_directions[]){
    for(int i=0;i<4;i++){
        this->connect_directions[i]=connect_directions[i];
    }
};
void Block::rotate(int dir){
    int temp[4];
    for(int i=0;i<4;i++){
        temp[i]=connect_directions[i];
    }
    if(dir==0){
        for(int i=0;i<4;i++){
            connect_directions[i]=temp[(i+1)%4];
        }
    }
    else{
        for(int i=0;i<4;i++){
            connect_directions[i]=temp[(i+3)%4];
        }
    }
}
void Block::set_connect_direction(int direction, int value){
    connect_directions[direction]=value;
}
int* Block::get_connect_directions(){
    return connect_directions;
}
int Block::get_connect_direction(int direction){
    return connect_directions[direction];
}
int Block::get_degree(){
    int degree=0;
    for(int i=0;i<4;i++){
        if(connect_directions[i]==1)degree++;
    }
    return degree;
}