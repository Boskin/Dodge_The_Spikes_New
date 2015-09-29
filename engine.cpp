#include<string>
#include<time.h>
#include"declarations.h"
#include"level.h"
int main(){
    std::string hello = "Hello world!";
    init();
    Level* level[5];
    for(int i=0;i<5;i++)
        level[i]=new Level(i);
    int num=0;
    int t,e;
    level[0]->import_data();
	while(!key[KEY_ESC]){
        t=clock();
        level[num]->all_func();
        if(level[num]->cleared){
            num++;
            level[num]->import_data();
            while(!key[KEY_SPACE])
                textout_centre_ex(BUFFER,font,"Press the space bar to continue to the next level.",
                                  SCREEN_LENG_X/2,SCREEN_LENG_Y/2,
                                  makecol(255,255,255),-1);
        }
        draw_borders();
        draw_trans_sprite(BUFFER,CURSOR_SPRITE,mouse_x,mouse_y);
        draw_sprite(screen,BUFFER,0,0);
        rectfill(BUFFER,0,0,SCREEN_LENG_X,SCREEN_LENG_Y,makecol(0,0,0));
        e=clock();
        if(e-t<15)rest(15-(e-t));
	}
    clean_up();
	return 0;
}
END_OF_MAIN()
