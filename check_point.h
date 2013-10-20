#ifndef CHECK_POINT_H
#define CHECK_POINT_H
#include"global_constants.h"
class Player;
class Check_Point{
    public:
    int x,y;
    bool occupied;
    void draw(bool editor);
    bool check_placed();
    void place(int* count);
    void space_bar_helper();
    void erase(int* count);
    bool collision(int x1,int y1,int x2,int y2);
    bool collision(Player* pl);
    bool collision();
    void reset();
    void export_data(ofstream* out);
    void import_data(ifstream* in);
    Check_Point();
};
#endif
