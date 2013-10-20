#include"spike.h"
Spike::Spike():x(-100),y(-100),start_x(-100),start_y(-100),
               spd_x(0),spd_y(0),start_spd_x(0),start_spd_y(0),
               min_x(-100),min_y(-100),max_x(-100),max_y(-100),loop(false){}
void Spike::draw(bool editor){
    if(spd_x==0 && spd_y==0){
        draw_trans_sprite(BUFFER,RED_SPIKE_SPRITE,x,y);
    }else{
        draw_trans_sprite(BUFFER,GREEN_SPIKE_SPRITE,x,y);
    }
    if(editor && check_placed()){
        rect(BUFFER,x,y,x+SPIKE_LENG_X,y+SPIKE_LENG_Y,HIGHLIGHT_COLOR);
        int x2,y2;
        x2=x==min_x?max_x:min_x;
        y2=y==min_y?max_y:min_y;
        rect(BUFFER,x2,y2,x2+SPIKE_LENG_X,y2+SPIKE_LENG_Y,HIGHLIGHT_COLOR);
        line(BUFFER,
             x+SPIKE_LENG_X/2,y+SPIKE_LENG_Y/2,
             x2+SPIKE_LENG_X/2,y2+SPIKE_LENG_Y/2,
             HIGHLIGHT_COLOR);
    }
}
bool Spike::check_placed(){
    return (x>-100 && min_x>-100 && max_x>-100);
}
void Spike::place(int* count){
    if((*count)<MAX_SPIKES){
        if(mouse_inbound()){
            if(x>-100){
                int m_x=(mouse_x/PLACE_FACTOR)*PLACE_FACTOR;
                int m_y=(mouse_y/PLACE_FACTOR)*PLACE_FACTOR;
                if(abs(m_x-x)==abs(m_y-y) || m_x-x==0 || m_y-y==0){
                    min_x=m_x<x?m_x:x;
                    max_x=m_x>x?m_x:x;
                    min_y=m_y<y?m_y:y;
                    max_y=m_y>y?m_y:y;
                    spd_x=x<max_x?1:-1;
                    spd_x=min_x==max_x?0:spd_x;
                    spd_y=y<max_y?1:-1;
                    spd_y=min_y==max_y?0:spd_y;
                    start_spd_x=spd_x;
                    start_spd_y=spd_y;
                    (*count)++;
                }
            }else{
                x=(mouse_x/PLACE_FACTOR)*PLACE_FACTOR;
                y=(mouse_y/PLACE_FACTOR)*PLACE_FACTOR;
                if(x+SPIKE_LENG_X>SCREEN_RIGHT)
                    x=SCREEN_RIGHT-SPIKE_LENG_X;
                if(y+SPIKE_LENG_Y>SCREEN_BOTTOM)
                    y=SCREEN_BOTTOM-SPIKE_LENG_Y;
                start_x=x;
                start_y=y;
            }
        }
    }
}
void Spike::space_bar_helper(){
    if(x>-100){
        line(BUFFER,x,SCREEN_TOP,x,SCREEN_BOTTOM,HIGHLIGHT_COLOR);
        line(BUFFER,x+SPIKE_LENG_X,SCREEN_TOP,
             x+SPIKE_LENG_X,SCREEN_BOTTOM,HIGHLIGHT_COLOR);
        line(BUFFER,SCREEN_LEFT,y,SCREEN_RIGHT,y,HIGHLIGHT_COLOR);
        line(BUFFER,SCREEN_LEFT,y+SPIKE_LENG_Y,
             SCREEN_RIGHT,y+SPIKE_LENG_Y,HIGHLIGHT_COLOR);
        int temp_x=x,temp_y=y;
        while(temp_x>SCREEN_LEFT && temp_y>SCREEN_TOP){
            putpixel(BUFFER,temp_x,temp_y,HIGHLIGHT_COLOR);
            temp_x--;
            temp_y--;
        }
        temp_x=x;
        temp_y=y;
        while(temp_x<SCREEN_RIGHT && temp_y<SCREEN_BOTTOM){
            putpixel(BUFFER,temp_x,temp_y,HIGHLIGHT_COLOR);
            temp_x++;
            temp_y++;
        }
        temp_x=x+SPIKE_LENG_X;
        temp_y=y;
        while(temp_x>SCREEN_LEFT && temp_y<SCREEN_BOTTOM){
            putpixel(BUFFER,temp_x,temp_y,HIGHLIGHT_COLOR);
            temp_x--;
            temp_y++;
        }
        temp_x=x+SPIKE_LENG_X;
        temp_y=y;
        while(temp_x<SCREEN_RIGHT && temp_y>SCREEN_TOP){
            putpixel(BUFFER,temp_x,temp_y,HIGHLIGHT_COLOR);
            temp_x++;
            temp_y--;
        }
    }
}
void Spike::erase(int* count){
    if(min_x>-100)
        (*count)--;
    x=-100;
    y=-100;
    start_x=-100;
    start_y=-100;
    min_x=-100;
    min_y=-100;
    min_y=-100;
    max_y=-100;
    spd_x=0;
    spd_y=0;
    start_spd_x=0;
    start_spd_y=0;
}
bool Spike::collision(int x1,int y1,int x2,int y2){
	return (x1<x+SPIKE_LENG_X && x2>x &&
            y1<y+SPIKE_LENG_Y && y2>y);
}
bool Spike::collision(){
    return collision(mouse_x,mouse_y,mouse_x,mouse_y);
}
bool Spike::move(Player* pl){
    x+=spd_x;
    y+=spd_y;
    if(x<min_x){
        if(loop){
            x=max_x;
        }else{
            spd_x*=-1;
        }
    }
    if(x>max_x){
        if(loop){
            x=min_x;
        }else{
            spd_x*=-1;
        }
    }
    if(y<min_y){
        if(loop){
            y=max_y;
        }else{
            spd_y*=-1;
        }
    }
    if(y>max_y){
        if(loop){
            y=min_y;
        }else{
            spd_y*=-1;
        }
    }
    return collision(pl);
}
void Spike::reset(){
    x=start_x;
    y=start_y;
    spd_x=start_spd_x;
    spd_y=start_spd_y;
}
void Spike::export_data(ofstream* out){
    *out<<start_x<<endl<<start_y<<endl;
    *out<<start_spd_x<<endl<<start_spd_y<<endl;
    *out<<min_x<<endl<<min_y<<endl;
    *out<<max_x<<endl<<max_y<<endl;
    *out<<loop<<endl;
}
void Spike::import_data(ifstream* in){
    *in>>start_x>>start_y;
    *in>>start_spd_x>>start_spd_y;
    *in>>min_x>>min_y;
    *in>>max_x>>max_y;
    *in>>loop;
    x=start_x;
    y=start_y;
    spd_x=start_spd_x;
    spd_y=start_spd_y;
}
