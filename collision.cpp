#include"player.h"
#include"block.h"
#include"spike.h"
#include"lock.h"
#include"check_point.h"
#include"exit.h"
bool Block::collision(Player* pl){
    return this->collision(pl->x,pl->y,
                           pl->x+PLAYER_LENG_X,
                           pl->y+PLAYER_LENG_Y);
}
bool Spike::collision(Player* pl){
    return this->collision(pl->x,pl->y,
                           pl->x+PLAYER_LENG_X,
                           pl->y+PLAYER_LENG_Y);
}
bool Lock::collision(Player* pl){
    return this->collision(pl->x,pl->y,
                           pl->x+PLAYER_LENG_X,
                           pl->y+PLAYER_LENG_Y);
}
bool Check_Point::collision(Player* pl){
   if(collision(pl->x,pl->y,
                pl->x+PLAYER_LENG_X,
                pl->y+PLAYER_LENG_Y ) && !occupied)occupied=true;
    return occupied;
}
bool Exit::collision(Player* pl){
    return this->collision(pl->x,pl->y,
                           pl->x+PLAYER_LENG_X,
                           pl->y+PLAYER_LENG_Y);
}
