#include"color.h"
#define C(var)var(var##_)
Color::Color():r(255),g(255),b(255){}
Color::Color(int r_,int g_,int b_):C(r),C(g),C(b){}
Color Color::make_color(int r_,int g_,int b_){
    Color ret_val(r_,g_,b_);
    return ret_val;
}