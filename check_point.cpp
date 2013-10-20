#include"check_point.h"
#include<allegro.h>
Check_Point::Check_Point():x(-100),y(-100),occupied(false){}
void Check_Point::draw(bool editor){
    if(!occupied){
        draw_trans_sprite(BUFFER,CHECK_POINT_SPRITE_VACANT,x,y);
    }else{
        draw_trans_sprite(BUFFER,CHECK_POINT_SPRITE_OCCUPIED,x,y);
    }
    if(editor)
        rect(BUFFER,x,y,
             x+CHECK_POINT_LENG_X,
             y+CHECK_POINT_LENG_Y,
             HIGHLIGHT_COLOR);
}
bool Check_Point::check_placed(){
    return (x>-100);
}
void Check_Point::place(int* count){
    if((*count)<MAX_CHECK_POINTS){
        if(mouse_inbound()){
            x=(mouse_x/PLACE_FACTOR)*PLACE_FACTOR;
            y=(mouse_y/PLACE_FACTOR)*PLACE_FACTOR;
            if(x+CHECK_POINT_LENG_X>SCREEN_RIGHT)
                x=SCREEN_LEFT-CHECK_POINT_LENG_X;
            if(y+CHECK_POINT_LENG_Y>SCREEN_BOTTOM)
                y=SCREEN_BOTTOM-CHECK_POINT_LENG_Y;
        }
    }
    (*count)++;
}
void Check_Point::space_bar_helper(){}
void Check_Point::erase(int* count){
    x=-100;
    y=-100;
    (*count)--;
}
bool Check_Point::collision(int x1,int y1,int x2,int y2){
    if(!occupied){
        if(x1<x+CHECK_POINT_LENG_X && x2>x &&
           y1<y+CHECK_POINT_LENG_Y && y2>y){
            return true;
        }
    }
    return false;
}
bool Check_Point::collision(){
    return collision(mouse_x,mouse_y,mouse_x,mouse_y);
}
void Check_Point::reset(){
    occupied=false;
}
void Check_Point::export_data(ofstream* out){
    *out<<x<<endl<<y<<endl;
}
void Check_Point::import_data(ifstream* in){
    *in>>x>>y;
}
