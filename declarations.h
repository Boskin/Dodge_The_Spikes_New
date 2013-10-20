#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include"global_macros.h"
BITMAP* BUFFER;
BITMAP* PLAYER_SPRITE_ALIVE;
BITMAP* PLAYER_SPRITE_DEAD;
BITMAP* BLOCK_SPRITE;
BITMAP* GREEN_SPIKE_SPRITE;
BITMAP* RED_SPIKE_SPRITE;
BITMAP* GATE_SPRITE;
BITMAP* KEY_SPRITE;
BITMAP* CHECK_POINT_SPRITE_VACANT;
BITMAP* CHECK_POINT_SPRITE_OCCUPIED;
BITMAP* EXIT_SPRITE;
BITMAP* CURSOR_SPRITE;
Color* blue;
Color* red;
Color* green;
Color* yellow;
Color* orange;
Color* purple;
Color* white;
Color* black;
bool m_pressed,m_released;
int cursor_x,cursor_y;
void init();
void clean_up();
bool mouse_inbound();
void draw_borders();
void mouse_buttons();
void print(int x,int y,Color* col,String s);
#endif
