#include"lock.h"
Lock::Lock():gate_x(-100),gate_y(-100),
             key_x(-100),key_y(-100),opened(false){}
void Lock::draw(bool editor){
    if(!opened){
        draw_sprite(BUFFER,GATE_SPRITE,gate_x,gate_y);
        draw_trans_sprite(BUFFER,KEY_SPRITE,key_x,key_y);
    }
    if(editor){
        draw_sprite(BUFFER,GATE_SPRITE,gate_x,gate_y);
        draw_trans_sprite(BUFFER,KEY_SPRITE,key_x,key_y);
        rect(BUFFER,gate_x,gate_y,
             gate_x+GATE_LENG_X,gate_y+GATE_LENG_Y,
             HIGHLIGHT_COLOR);
        rect(BUFFER,key_x,key_y,
             key_x+KEY_LENG_X,key_y+KEY_LENG_Y,
             HIGHLIGHT_COLOR);
        if(check_placed())
            line(BUFFER,gate_x+GATE_LENG_X/2,gate_y+GATE_LENG_Y/2,
             key_x+KEY_LENG_X/2,key_y+KEY_LENG_Y/2,HIGHLIGHT_COLOR);
    }
}
bool Lock::check_placed(){
    return (gate_x>-100 && key_x>-100);
}
void Lock::place(int* count){
    if((*count)<MAX_LOCKS){
        if(mouse_inbound()){
            if(key[KEY_SPACE]){
                key_x=(mouse_x/PLACE_FACTOR)*PLACE_FACTOR;
                key_y=(mouse_y/PLACE_FACTOR)*PLACE_FACTOR;
                if(key_x+KEY_LENG_X>SCREEN_RIGHT)
                    key_x=SCREEN_RIGHT-KEY_LENG_X;
                if(key_y+KEY_LENG_Y>SCREEN_BOTTOM)
                    key_y=SCREEN_BOTTOM-KEY_LENG_Y;
            }else{
                gate_x=(mouse_x/PLACE_FACTOR)*PLACE_FACTOR;
                gate_y=(mouse_y/PLACE_FACTOR)*PLACE_FACTOR;
                if(gate_x+GATE_LENG_X>SCREEN_RIGHT)
                    gate_x=SCREEN_RIGHT-GATE_LENG_X;
                if(gate_y+GATE_LENG_Y>SCREEN_BOTTOM)
                    gate_y=SCREEN_BOTTOM-GATE_LENG_Y;
            }
            if(check_placed())(*count)++;
        }
    }
}
void Lock::space_bar_helper(){
    if(key_x>-100)
        line(BUFFER,key_x+KEY_LENG_X/2,key_y+KEY_LENG_Y/2,
             cursor_x+KEY_LENG_X/2,cursor_y+KEY_LENG_Y/2,HIGHLIGHT_COLOR);
    else if(gate_x>-100)
        line(BUFFER,gate_x+GATE_LENG_X/2,gate_y+GATE_LENG_Y/2,
             cursor_x+GATE_LENG_X/2,cursor_y+GATE_LENG_Y/2,HIGHLIGHT_COLOR);
}
void Lock::erase(int* count){
    if(key_x>-100 && gate_x>-100)(*count)--;
    key_x=-100;
    key_y=-100;
    gate_x=-100;
    gate_y=-100;
}
bool Lock::collision(int x1,int y1,int x2,int y2){
    if(!opened){
        if(x1<gate_x+GATE_LENG_X && x2>gate_x &&
           y1<gate_y+GATE_LENG_Y && y2>gate_y)return true;
        if(x1<key_x+KEY_LENG_X && x2>key_x &&
           y1<key_y+KEY_LENG_Y && y2>key_y){
            opened=true;
            return false;
        }
    }
    return false;
}
bool Lock::collision(){
    return collision(mouse_x,mouse_y,mouse_x,mouse_y) ||
           (mouse_x>key_x && mouse_x<key_x+KEY_LENG_X &&
            mouse_y>key_y && mouse_y<key_y+KEY_LENG_Y);
}
void Lock::reset(){
    opened=false;
}
void Lock::export_data(ofstream* out){
    *out<<gate_x<<endl<<gate_y<<endl;
    *out<<key_x<<endl<<key_y<<endl;
}
void Lock::import_data(ifstream* in){
    *in>>gate_x>>gate_y;
    *in>>key_x>>key_y;
}
