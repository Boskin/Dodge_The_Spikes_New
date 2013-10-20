#ifndef COLOR_H
#define COLOR_H
class Color{
    public:
    int r,g,b;
    static Color make_color(int r_,int g_,int b_);
    Color();
    Color(int r_,int g_,int b_);
};
#endif