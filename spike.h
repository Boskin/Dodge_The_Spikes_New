#ifndef SPIKE_H
#define SPIKE_H
#include"global_constants.h"
class Player;
class Spike{
	public:
	int x,y;
	int start_x,start_y;
	int spd_x,spd_y;
	int start_spd_x,start_spd_y;
	int min_x,min_y;
	int max_x,max_y;
	bool loop;
	void draw(bool editor);
    bool check_placed();
    void place(int* count);
    void space_bar_helper();
    void erase(int* count);
	bool collision(int x1,int y1,int x2,int y2);
	bool collision(Player* pl);
    bool collision();
	bool move(Player* pl);
	void reset();
	void export_data(ofstream* out);
	void import_data(ifstream* in);
	Spike();
};
#endif
