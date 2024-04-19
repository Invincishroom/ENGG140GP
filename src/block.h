#ifndef BLOCK_H
#define BLOCK_H
class Block{
    public:
        Block(int type);
        Block();
        int get_type();
        void set_type(int type);
        void set_connect_directions(int connect_directions[]);
        void set_connect_direction(int direction, int value);
        int* get_connect_directions();
        int get_connect_direction(int direction);
        int get_degree();
        void rotate(int dir);//0: counterclockwise; 1: clockwise
    private:
        int type; //1: source, 0: pipe, 2: target, 3: void
        int connect_directions[4]={0,0,0,0}; //L, U, R, D
};
    // BLOCK_H
#endif