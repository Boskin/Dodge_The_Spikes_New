#include"exit.h"
Exit::Exit():x(-100),y(-100){}
void Exit::draw(bool editor){
    draw_trans_sprite(BUFFER,EXIT_SPRITE,x,y);
    if(editor)
        rect(BUFFER,x,y,x+EXIT_LENG_X,y+EXIT_LENG_Y,
             HIGHLIGHT_COLOR);
}
bool Exit::check_placed(){
    return (x>-100);
}
void Exit::place(int* count){
    if((*count)<MAX_EXITS){
        if(mouse_inbound()){
            x=(mouse_x/PLACE_FACTOR)*PLACE_FACTOR;
            y=(mouse_y/PLACE_FACTOR)*PLACE_FACTOR;
            if(x+EXIT_LENG_X>SCREEN_RIGHT)
                x=SCREEN_RIGHT-EXIT_LENG_X;
            if(y+EXIT_LENG_Y>SCREEN_BOTTOM)
                y=SCREEN_BOTTOM-EXIT_LENG_Y;
            (*count)++;
        }
    }
}
void Exit::space_bar_helper(){}
void Exit::erase(int* count){
    x=-100;
    y=-100;
    (*count)--;
}
bool Exit::collision(int x1,int y1,int x2,int y2){
    return (x1<x+EXIT_LENG_X && x2>x &&
            y1<y+EXIT_LENG_Y && y2>y);
}
bool Exit::collision(){
    return collision(mouse_x,mouse_y,mouse_x,mouse_y);
}
void Exit::export_data(ofstream* out){
    *out<<x<<endl<<y<<endl;
}
void Exit::import_data(ifstream* in){
    *in>>x>>y;
}
