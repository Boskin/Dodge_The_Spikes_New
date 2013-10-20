#include"global_constants.h"
void init(){
    allegro_init();
	set_color_depth(32);
    set_alpha_blender();
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,SCREEN_LENG_X,SCREEN_LENG_Y,0,0);
	install_keyboard();
    install_mouse();
    BUFFER=create_bitmap(SCREEN_LENG_X,SCREEN_LENG_Y);
    PLAYER_SPRITE_ALIVE=load_tga("img/Player.tga",NULL);
    PLAYER_SPRITE_DEAD=load_tga("img/Explosion.tga",NULL);
    BLOCK_SPRITE=load_tga("img/Block.tga",NULL);
    GREEN_SPIKE_SPRITE=load_tga("img/Green_Spike.tga",NULL);
    RED_SPIKE_SPRITE=load_tga("img/Red_Spike.tga",NULL);
    GATE_SPRITE=load_tga("img/Gate.tga",NULL);
    KEY_SPRITE=load_tga("img/Key.tga",NULL);
    CHECK_POINT_SPRITE_VACANT=load_tga("img/Check_Point_Vacant.tga",NULL);
    CHECK_POINT_SPRITE_OCCUPIED=load_tga("img/Check_Point_Occupied.tga",NULL);
    EXIT_SPRITE=load_tga("img/Exit.tga",NULL);
    CURSOR_SPRITE=load_tga("img/Cursor.tga",NULL);
    blue=new Color(0,0,255);
    red=new Color(255,0,0);
    green=new Color(0,255,0);
    yellow=new Color(255,255,0);
    orange=new Color(255,100,0);
    purple=new Color(155,0,155);
    black=new Color(0,0,0);
    white=new Color(255,255,255);
    m_pressed=false;
    m_released=false;
}
void clean_up(){
    delete BLOCK_SPRITE;
    delete RED_SPIKE_SPRITE,GREEN_SPIKE_SPRITE;
    delete GATE_SPRITE,KEY_SPRITE;
    delete blue,red,green,yellow,orange,
    purple,black,white;
}
bool mouse_inbound(){
    return (mouse_x>=SCREEN_LEFT && mouse_x<=SCREEN_RIGHT &&
            mouse_y>=SCREEN_TOP && mouse_y<=SCREEN_BOTTOM);
}
void draw_borders(){
    line(BUFFER,SCREEN_LEFT,SCREEN_TOP,SCREEN_RIGHT-1,SCREEN_TOP,makecol(0,255,0));
    line(BUFFER,SCREEN_LEFT,SCREEN_TOP,SCREEN_LEFT,SCREEN_BOTTOM-1,makecol(0,255,0));
    line(BUFFER,SCREEN_LEFT,SCREEN_BOTTOM-1,SCREEN_RIGHT-1,SCREEN_BOTTOM-1,makecol(0,255,0));
    line(BUFFER,SCREEN_RIGHT-1,SCREEN_TOP,SCREEN_RIGHT-1,SCREEN_BOTTOM-1,makecol(0,255,0));
}
void mouse_buttons(){
    m_released=false;
    if(mouse_b&1)m_pressed=true;
    if(m_pressed && !mouse_b&1){
        m_released=true;
        m_pressed=false;
    }
    cursor_x=mouse_x/PLACE_FACTOR*PLACE_FACTOR;
    cursor_y=mouse_y/PLACE_FACTOR*PLACE_FACTOR;
}
void print(int x,int y,Color* col,String s){
    int num=s.leng;
    if(num>6){
        s.remove_char('_');
        String frag;
        for(int i=0;i<num;i+=5){
            frag=s.sub_str(i,((i+4)<(num-1))?i+4:num-1);
            textout_centre_ex(BUFFER,font,frag.str,
                              x,y+i*2,makecol(col->r,col->g,col->b),-1);
        }
    }else{
        textout_centre_ex(BUFFER,font,s.str,x,y,
                          makecol(col->r,col->g,col->b),-1);
    }
}
