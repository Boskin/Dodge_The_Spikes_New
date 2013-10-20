#ifndef GLOBAL_CONSTANTS_H
#define GLOBAL_CONSTANTS_H
#include"global_macros.h"
extern BITMAP* BUFFER;
extern BITMAP* PLAYER_SPRITE_ALIVE;
extern BITMAP* PLAYER_SPRITE_DEAD;
extern BITMAP* BLOCK_SPRITE;
extern BITMAP* GREEN_SPIKE_SPRITE;
extern BITMAP* RED_SPIKE_SPRITE;
extern BITMAP* GATE_SPRITE;
extern BITMAP* KEY_SPRITE;
extern BITMAP* CHECK_POINT_SPRITE_VACANT;
extern BITMAP* CHECK_POINT_SPRITE_OCCUPIED;
extern BITMAP* EXIT_SPRITE;
extern BITMAP* CURSOR_SPRITE;
extern Color* blue;
extern Color* red;
extern Color* green;
extern Color* yellow;
extern Color* orange;
extern Color* purple;
extern Color* white;
extern Color* black;
extern bool m_pressed,m_released;
extern int cursor_x,cursor_y;
void init();
void clean_up();
bool mouse_inbound();
void draw_borders();
void mouse_buttons();
void print(int x,int y,Color* col,String s);
#endif
