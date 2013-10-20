#include"declarations.h"
#include"level.h"
#include"button.h"
#include"button_element.h"
#include"level_editor.h"
int main(){
    init();
    Button** level_buttons=new Button*[5];
    Level_Editor** level_edit=new Level_Editor*[5];
    for(int i=0;i<5;i++){
        level_edit[i]=new Level_Editor(i);
        level_buttons[i]=new Button(level_edit[i]->level->name.str,
                                    (i+8)*TOOL_BUTTON_SPACE+TOOL_BUTTON_START_X,
                                    TOOL_BUTTON_Y,
                                    yellow,blue);
    }
    Button_Set level_button_set(level_buttons,5);
    while(!key[KEY_ESC]){
        mouse_buttons();
        level_edit[
            level_button_set.get_pressed_button_id()
        ]->edit();
        level_button_set.all_func();
        draw_borders();
        draw_trans_sprite(BUFFER,CURSOR_SPRITE,mouse_x,mouse_y);
        draw_sprite(screen,BUFFER,0,0);
        rectfill(BUFFER,0,0,SCREEN_LENG_X,SCREEN_LENG_Y,makecol(0,0,0));
    }
    return 0;
}
END_OF_MAIN()