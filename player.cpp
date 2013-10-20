#include"player.h"
Player::Player():x(SCREEN_LEFT),y(SCREEN_TOP),
                 start_x(SCREEN_LEFT),start_y(SCREEN_TOP),
                 col_x(-100),col_y(-100),dir(0),
                 alive(true){}
void Player::draw(bool editor){
    if(alive)draw_trans_sprite(BUFFER,PLAYER_SPRITE_ALIVE,x,y);
    else draw_trans_sprite(BUFFER,PLAYER_SPRITE_DEAD,x,y);
}
bool Player::check_placed(){return false;}
void Player::place(int* count){
    if(mouse_inbound()){
        x=(mouse_x/PLACE_FACTOR)*PLACE_FACTOR;
        y=(mouse_y/PLACE_FACTOR)*PLACE_FACTOR;
        if(x+PLAYER_LENG_X>SCREEN_RIGHT)
            x=SCREEN_RIGHT-PLAYER_LENG_X;
        if(y+PLAYER_LENG_Y>SCREEN_BOTTOM)
            y=SCREEN_BOTTOM-PLAYER_LENG_Y;
        start_x=x;
        start_y=y;
    }
}
void Player::space_bar_helper(){}
void Player::erase(int* count){}
bool Player::collision(){
    return (mouse_x>x && mouse_x<x+PLAYER_LENG_X &&
            mouse_y>y && mouse_y<y+PLAYER_LENG_Y);
}
void Player::reset(){
    x=start_x;
    y=start_y;
    alive=true;
}
void Player::export_data(ofstream* out){
    *out<<start_x<<endl<<start_y<<endl;
}
void Player::import_data(ifstream* in){
    *in>>start_x>>start_y;
    x=start_x;
    y=start_y;
}
