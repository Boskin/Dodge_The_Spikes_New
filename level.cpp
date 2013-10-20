#include"level.h"
Level::Level(int num_):num(num_),cleared(false){
    blocks=new Block*[MAX_BLOCKS];
    for(int i=0;i<MAX_BLOCKS;i++)
        blocks[i]=new Block;
    spikes=new Spike*[MAX_SPIKES];
    for(int i=0;i<MAX_SPIKES;i++)
        spikes[i]=new Spike;
    locks=new Lock*[MAX_LOCKS];
    for(int i=0;i<MAX_LOCKS;i++)
        locks[i]=new Lock;
    check_points=new Check_Point*[MAX_CHECK_POINTS];
    for(int i=0;i<MAX_CHECK_POINTS;i++)
        check_points[i]=new Check_Point;
    exits=new Exit*[MAX_EXITS];
    for(int i=0;i<MAX_EXITS;i++)
        exits[i]=new Exit;
    pl=new Player*[1];
    (*pl)=new Player;
    String num_s;
    sprintf(num_s.str,"%d",num);
    num_s.leng=length_of(num_s.str);
    String temp;
    temp="Level ";
    name=temp+num_s;
    file_name=name;
    file_name.remove_char(' ');
}
Level::~Level(){
    delete blocks,spikes,locks,check_points,
           exits,pl;
}
void Level::draw(){
    (*pl)->draw(false);
    for(int i=0;i<MAX_BLOCKS;i++){
        blocks[i]->draw(false);
    }
    for(int i=0;i<MAX_SPIKES;i++){
        spikes[i]->draw(false);
    }
    for(int i=0;i<MAX_LOCKS;i++){
        locks[i]->draw(false);
    }
    for(int i=0;i<MAX_CHECK_POINTS;i++){
        check_points[i]->draw(false);
    }
    for(int i=0;i<MAX_EXITS;i++){
        exits[i]->draw(false);
    }
}
void Level::spike_movements(){
    for(int i=0;i<MAX_SPIKES;i++){
        if(spikes[i]->move(*pl))(*pl)->alive=false;
    }
}
int Level::check_collision(int* coord,int* col){
    for(int i=0;i<MAX_BLOCKS;i++){
        if(blocks[i]->collision(*pl)){
            *coord=*col;
        }
    }
    for(int i=0;i<MAX_SPIKES;i++){
        if(spikes[i]->collision(*pl)){
            return SPIKE_HIT;
        }
    }
    for(int i=0;i<MAX_LOCKS;i++){
        if(locks[i]->collision(*pl)){
            *coord=*col;
        }
    }
    for(int i=0;i<MAX_CHECK_POINTS;i++){
        if(check_points[i]->collision(*pl)){
            (*pl)->start_x=check_points[i]->x;
            (*pl)->start_y=check_points[i]->y;
        }
    }
    for(int i=0;i<MAX_EXITS;i++){
        if(exits[i]->collision(*pl)){
            return EXIT_HIT;
        }
    }
    *col=*coord;
    return 0;
}
void Level::pl_input(){
    (*pl)->dir=0;
    if(key[KEY_UP]){(*pl)->dir=UP;pl_move();}
    if(key[KEY_DOWN]){(*pl)->dir=DOWN;pl_move();}
    if(key[KEY_RIGHT]){(*pl)->dir=RIGHT;pl_move();}
    if(key[KEY_LEFT]){(*pl)->dir=LEFT;pl_move();}
}
void Level::pl_move(){
    int *coord,*col;
    int change;
    switch((*pl)->dir){
        case UP:
        change=-1;
        coord=&(*pl)->y;
        col=&(*pl)->col_y;
        break;
        case DOWN:
        change=1;
        coord=&(*pl)->y;
        col=&(*pl)->col_y;
        break;
        case RIGHT:
        change=1;
        coord=&(*pl)->x;
        col=&(*pl)->col_x;
        break;
        case LEFT:
        change=-1;
        coord=&(*pl)->x;
        col=&(*pl)->col_x;
        break;
        default:
        coord=NULL;
        col=NULL;
    }
    if(coord!=NULL && col!=NULL){
        for(int i=0;i<SPEED;i++){
            *coord+=change;
            switch(this->check_collision(coord,col)){
                case SPIKE_HIT:
                (*pl)->alive=false;
                break;
                case EXIT_HIT:
                cleared=true;
                break;
            }
            if((*pl)->y<SCREEN_TOP)(*pl)->y=SCREEN_TOP;
            if((*pl)->y+PLAYER_LENG_Y>SCREEN_BOTTOM)(*pl)->y=SCREEN_BOTTOM-PLAYER_LENG_Y;
            if((*pl)->x+PLAYER_LENG_X>SCREEN_RIGHT)(*pl)->x=SCREEN_RIGHT-PLAYER_LENG_X;
            if((*pl)->x<SCREEN_LEFT)(*pl)->x=SCREEN_LEFT;
        }
    }
}
void Level::reset(){
    for(int i=0;i<MAX_SPIKES;i++){
        spikes[i]->reset();
    }
    for(int i=0;i<MAX_LOCKS;i++){
        locks[i]->reset();
    }
    for(int i=0;i<MAX_CHECK_POINTS;i++){
        check_points[i]->reset();
    }
    (*pl)->reset();
}
void Level::all_func(){
    this->draw();
    if((*pl)->alive){
        this->pl_input();
        this->spike_movements();
    }else{
        textout_centre_ex(BUFFER,font,
                          "You're hit! Press the space key to try again.",
                          395,295,makecol(255,255,255),-1);
        if(key[KEY_SPACE])this->reset();
    }
}
void Level::export_data(){
    ofstream* out=new ofstream(file_name.str);
    (*pl)->export_data(out);
    for(int i=0;i<MAX_BLOCKS;i++){
        blocks[i]->export_data(out);
    }
    for(int i=0;i<MAX_SPIKES;i++){
        spikes[i]->export_data(out);
    }
    for(int i=0;i<MAX_LOCKS;i++){
        locks[i]->export_data(out);
    }
    for(int i=0;i<MAX_CHECK_POINTS;i++){
        check_points[i]->export_data(out);
    }
    for(int i=0;i<MAX_EXITS;i++){
        exits[i]->export_data(out);
    }
    out->close();
    delete out;
}
void Level::import_data(){
    ifstream* in=new ifstream(file_name.str);
    (*pl)->import_data(in);
    for(int i=0;i<MAX_BLOCKS;i++){
        blocks[i]->import_data(in);
    }
    for(int i=0;i<MAX_SPIKES;i++){
        spikes[i]->import_data(in);
    }
    for(int i=0;i<MAX_LOCKS;i++){
        locks[i]->import_data(in);
    }
    for(int i=0;i<MAX_CHECK_POINTS;i++){
        check_points[i]->import_data(in);
    }
    for(int i=0;i<MAX_EXITS;i++){
        exits[i]->import_data(in);
    }
    in->close();
    delete in;
}
