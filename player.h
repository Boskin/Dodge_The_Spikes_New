#ifndef PLAYER_H
#define PLAYER_H
#include"global_constants.h"
class Player{
    public:
    int x,y;
    int col_x,col_y;
    int start_x,start_y;
    int dir;
    bool alive;
    void draw(bool editor);
    bool check_placed();
    void place(int* count);
    void space_bar_helper();
    void erase(int* count);
    bool collision();
    void reset();
    void export_data(ofstream* out);
    void import_data(ifstream* in);
    Player();
};
#endif
