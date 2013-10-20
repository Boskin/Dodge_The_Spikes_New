#include"level_editor.h"
#define C(var)var(var##_)
Level_Editor::Level_Editor(int num_):C(num){
    level=new Level(num);
    Button *block_t_button,*spike_t_button,
           *lock_t_button,*check_point_t_button,
           *exit_t_button,*player_t_button;
    block_t_button=new Button("Block",
                              TOOL_BUTTON_START_X,TOOL_BUTTON_Y,
                              ELEMENT_PRESSED_COLOR,ELEMENT_RELEASED_COLOR);
    spike_t_button=new Button("Spike",
                              TOOL_BUTTON_START_X+TOOL_BUTTON_SPACE,TOOL_BUTTON_Y,
                              ELEMENT_PRESSED_COLOR,ELEMENT_RELEASED_COLOR);
    lock_t_button=new Button("Lock",
                              TOOL_BUTTON_START_X+2*TOOL_BUTTON_SPACE,TOOL_BUTTON_Y,
                              ELEMENT_PRESSED_COLOR,ELEMENT_RELEASED_COLOR);
    check_point_t_button=new Button("Check_Point",
                              TOOL_BUTTON_START_X+3*TOOL_BUTTON_SPACE,TOOL_BUTTON_Y,
                              ELEMENT_PRESSED_COLOR,ELEMENT_RELEASED_COLOR);
    exit_t_button=new Button("Exit",
                              TOOL_BUTTON_START_X+4*TOOL_BUTTON_SPACE,TOOL_BUTTON_Y,
                              ELEMENT_PRESSED_COLOR,ELEMENT_RELEASED_COLOR);
    player_t_button=new Button("Player",
                              TOOL_BUTTON_START_X+5*TOOL_BUTTON_SPACE,TOOL_BUTTON_Y,
                              ELEMENT_PRESSED_COLOR,ELEMENT_RELEASED_COLOR);
    block_button=new Element_Button<Block>(level->blocks,MAX_BLOCKS,block_t_button);
    spike_button= new Element_Button<Spike>(level->spikes,MAX_SPIKES,spike_t_button);
    lock_button=new Element_Button<Lock>(level->locks,MAX_LOCKS,lock_t_button);
    check_point_button=new Element_Button<Check_Point>(level->check_points,MAX_CHECK_POINTS,
                                           check_point_t_button);
    exit_button=new Element_Button<Exit>(level->exits,MAX_EXITS,exit_t_button);
    player_button=new Element_Button<Player>(level->pl,1,player_t_button);
    Button** b_array=new Button*[6];
    b_array[0]=block_t_button;
    b_array[1]=spike_t_button;
    b_array[2]=lock_t_button;
    b_array[3]=check_point_t_button;
    b_array[4]=exit_t_button;
    b_array[5]=player_t_button;
    element_buttons=Button_Set::make_button_set(b_array,6);
    save=Button::make_button("Save",TOOL_BUTTON_START_X+6*TOOL_BUTTON_SPACE,TOOL_BUTTON_Y,
                             purple,purple);
    load=Button::make_button("Load",TOOL_BUTTON_START_X+7*TOOL_BUTTON_SPACE,TOOL_BUTTON_Y,
                             orange,orange);
}
void Level_Editor::draw(){
    rectfill(BUFFER,player_button->button->x+PLAYER_LENG_X/2-5,
             40,player_button->button->x+PLAYER_LENG_X/2+5,50,makecol(0,0,0));
    for(int i=0;i<(SCREEN_RIGHT-SCREEN_LEFT)/GRID_INTERVAL;i++)
        line(BUFFER,SCREEN_LEFT+i*GRID_INTERVAL,SCREEN_TOP,
             SCREEN_LEFT+i*GRID_INTERVAL,SCREEN_BOTTOM,GRID_COLOR);
    for(int i=0;i<(SCREEN_BOTTOM-SCREEN_TOP)/GRID_INTERVAL;i++)
        line(BUFFER,SCREEN_LEFT,SCREEN_TOP+i*GRID_INTERVAL,
             SCREEN_RIGHT,SCREEN_TOP+i*GRID_INTERVAL,GRID_COLOR);
    if(mouse_inbound())
        rect(BUFFER,cursor_x,cursor_y,
             cursor_x+PLAYER_LENG_X,cursor_y+PLAYER_LENG_Y,
             HIGHLIGHT_COLOR);
}
void Level_Editor::saving_and_loading(){
    if(save.get_active()){
        save.change_button_state();
        level->export_data();
    }
    if(load.get_active()){
        load.change_button_state();
        level->import_data();
        block_button->calc_count();
        spike_button->calc_count();
        lock_button->calc_count();
        check_point_button->calc_count();
        exit_button->calc_count();
    }
}
void Level_Editor::edit(){
    draw();
    block_button->all_func();
    spike_button->all_func();
    lock_button->all_func();
    check_point_button->all_func();
    exit_button->all_func();
    player_button->all_func();
    element_buttons.all_func();
    save.all_func();
    load.all_func();
    saving_and_loading();
}