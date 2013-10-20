#include"block.h"
Block::Block():x(-100),y(-100){}
void Block::draw(bool editor){
	draw_sprite(BUFFER,BLOCK_SPRITE,x,y);
}
bool Block::check_placed(){
    return (x>-100);
}
void Block::place(int* count){
    if((*count)<MAX_BLOCKS){
        if(mouse_inbound()){
            x=(mouse_x/PLACE_FACTOR)*PLACE_FACTOR;
            y=(mouse_y/PLACE_FACTOR)*PLACE_FACTOR;
            if(x+BLOCK_LENG_X>SCREEN_RIGHT)
                x=SCREEN_RIGHT-BLOCK_LENG_X;
            if(y+BLOCK_LENG_Y>SCREEN_BOTTOM)
                y=SCREEN_BOTTOM-BLOCK_LENG_Y;
            (*count)++;
        }
    }
}
void Block::space_bar_helper(){}
void Block::erase(int* count){
    x=-100;
    y=-100;
    (*count)--;
}
bool Block::collision(int x1,int y1,int x2,int y2){
	return (x1<x+BLOCK_LENG_X && x2>x &&
	        y1<y+BLOCK_LENG_Y && y2>y);
}
bool Block::collision(){
    return collision(mouse_x,mouse_y,mouse_x,mouse_y);
}
void Block::export_data(ofstream* out){
    *out<<x<<endl<<y<<endl;
}
void Block::import_data(ifstream* in){
    *in>>x;
    *in>>y;
}
