#include"button.h"
#define C(var)var(var##_)
Button::Button():x(-100),y(-100),name("default"){}
Button::Button(const char* name_,int x_,int y_,Color* pressed_,Color* released_):
C(x),C(y),C(pressed),C(released),m_pressed(false),active(false){name=name_;current_col=released;}
Button Button::make_button(const char* name_,int x_,int y_,Color* pressed_,Color* released_){
    Button ret_val(name_,x_,y_,pressed_,released_);
    return ret_val;
}
void Button::draw(){
    rectfill(BUFFER,x,y,x+BUTTON_LENG_X,y+BUTTON_LENG_Y,
             makecol(current_col->r,current_col->g,current_col->b));
    /*textout_centre_ex(BUFFER,font,name.str,
	x+BUTTON_LENG_X/2,y+BUTTON_LENG_Y+10,
	makecol(current_col->r,current_col->g,current_col->b),-1);*/
    print(x+BUTTON_LENG_X/2,y+BUTTON_LENG_Y/2+11,
          current_col,name);
}
bool Button::collision(){
    if(m_released && mouse_x>x && mouse_y>y &&
       mouse_x<x+BUTTON_LENG_X && mouse_y<y+BUTTON_LENG_Y){
        change_button_state();
        return true;
    }
    return false;
}
bool Button::get_active(){return active;}
void Button::change_button_state(){
    active=!active;
    current_col=active?pressed:released;
}
void Button::all_func(){
    draw();
    collision();
}
Button_Set::Button_Set(Button** buttons_,int button_count_):C(buttons),C(button_count),pressed_button_id(0){
    buttons[0]->change_button_state();
    pressed_button=buttons[0];
}
Button_Set::Button_Set(){}
Button_Set Button_Set::make_button_set(Button** buttons_,int button_count_){
    Button_Set ret_val(buttons_,button_count_);
    return ret_val;
}
void Button_Set::draw(){
    for(int i=0;i<button_count;i++){
        buttons[i]->draw();
    }
}
int Button_Set::get_pressed_button_id(){
    return pressed_button_id;
}
void Button_Set::check_button_collision(){
    for(int i=0;i<button_count;i++){
        if(buttons[i]->collision()){
            pressed_button=buttons[i];
            pressed_button_id=i;
            for(int j=0;j<button_count;j++){
                if(j!=i){
                    if(buttons[j]->get_active())
                        buttons[j]->change_button_state();
                }
            }
        }
    }
}
void Button_Set::all_func(){
    draw();
    check_button_collision();
}