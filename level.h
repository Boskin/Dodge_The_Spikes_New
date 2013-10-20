#ifndef LEVEL_H
#define LEVEL_H
#include"global_constants.h"
#include"block.h"
#include"spike.h"
#include"lock.h"
#include"check_point.h"
#include"exit.h"
#include"player.h"
#include"string.h"
class Level{
    public:
    Player** pl;
    Block** blocks;
    Spike** spikes;
    Lock** locks;
    Check_Point** check_points;
    Exit** exits;
    String name,file_name;
    int num;
    bool cleared;
    void draw();
    void spike_movements();
    void pl_input();
    void pl_move();
    int check_collision(int* coord,int* col);
    void all_func();
    void reset();
    void export_data();
    void import_data();
    Level(int num_);
    ~Level();
};
#endif
