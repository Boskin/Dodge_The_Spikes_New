#ifndef BUTTON_H
#define BUTTON_H
#include"global_constants.h"
#include"string.h"
#include"color.h"
class Button{
    private:
    Color* current_col;
    bool active;
    public:
    int x,y;
    String name;
    Color *pressed,*released;
    bool m_pressed;
    void draw();
    bool collision();
    bool get_active();
    void change_button_state();
    void all_func();
    static Button make_button(const char* name_,int x_,int y_,
                              Color* pressed_,Color* released_);
    Button();
    Button(const char* name_,int x_,int y_,Color* pressed_,Color* released_);
};
class Button_Set{
    private:
    Button* pressed_button;
    int pressed_button_id;
    public:
    Button** buttons;
    int button_count;
    int get_pressed_button_id();
    void draw();
    void check_button_collision();
    void all_func();
    static Button_Set make_button_set(Button** buttons_,int button_count_);
    Button_Set();
    Button_Set(Button** buttons_,int button_count_);
};
#endif