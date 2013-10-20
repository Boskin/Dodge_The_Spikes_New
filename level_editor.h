#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H
#include"global_constants.h"
#include"level.h"
#include"button_element.h"
class Level_Editor{
    public:
    Element_Button<Block> *block_button;
    Element_Button<Spike> *spike_button;
    Element_Button<Lock> *lock_button;
    Element_Button<Check_Point> *check_point_button;
    Element_Button<Exit> *exit_button;
    Element_Button<Player> *player_button;
    Button_Set element_buttons;
    Button save,load;
    Level* level;
    int num;
    void draw();
    void saving_and_loading();
    void edit();
    Level_Editor();
    Level_Editor(int num_);
};
#endif