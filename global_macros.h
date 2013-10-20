#include<allegro.h>
#include<fstream>
#include<math.h>
#include"string.h"
#include"color.h"
using std::ofstream;
using std::ifstream;
using std::endl;
#define UP    1
#define DOWN  2
#define RIGHT 3
#define LEFT  4
#define SPEED 5
#define SPIKE_HIT 1
#define EXIT_HIT  2
#define BLOCK_LENG_X       20
#define BLOCK_LENG_Y       20
#define SPIKE_LENG_X       20
#define SPIKE_LENG_Y       20
#define GATE_LENG_X        20
#define GATE_LENG_Y        20
#define KEY_LENG_X         20
#define KEY_LENG_Y         20
#define CHECK_POINT_LENG_X 20
#define CHECK_POINT_LENG_Y 20
#define EXIT_LENG_X        20
#define EXIT_LENG_Y        20
#define PLAYER_LENG_X      20
#define PLAYER_LENG_Y      20
#define BUTTON_LENG_X      20
#define BUTTON_LENG_Y      20
#define SCREEN_LENG_X      800
#define SCREEN_LENG_Y      600
#define SCREEN_TOP    50
#define SCREEN_BOTTOM 600
#define SCREEN_RIGHT  800
#define SCREEN_LEFT   0
#define MAX_BLOCKS       1000
#define MAX_SPIKES       1000
#define MAX_LOCKS        10
#define MAX_CHECK_POINTS 5
#define MAX_EXITS        5
#define PLACE_FACTOR 5
#define TOOL_BUTTON_START_X 10
#define TOOL_BUTTON_Y       0
#define TOOL_BUTTON_SPACE   50
#define GRID_COLOR          makecol(50,50,50)
#define GRID_INTERVAL       20
#define ELEMENT_PRESSED_COLOR green
#define ELEMENT_RELEASED_COLOR red
#define HIGHLIGHT_COLOR makecol(0,255,0)
#define INIT_ELEMENT(ELE,Ele,ele,x,y) \
    Ele* ele##s[MAX_##ELE##S]; \
    for(int i=0;i<MAX_##ELE##S;i++) \
        ele##s[i]=new Ele; \
    Button ele##_t_button(#Ele,x,y, \
                          ELEMENT_PRESSED_COLOR, \
                          ELEMENT_RELEASED_COLOR); \
    Element_Button<Ele> ele##_button(ele##s,MAX_##ELE##S,&ele##_t_button);
