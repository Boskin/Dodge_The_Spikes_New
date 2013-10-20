#ifndef BUTTON_ELEMENT_H
#define BUTTON_ELEMENT_H
#include"button.h"
template<class Element>
class Element_Button{
    public:
    Button* button;
    Element** elements;
    int element_count,element_max;
    int next_element;
    String element_count_str;
    void draw();
    int find_next_element();
    void active();
    void check_button_state();
    void calc_count();
    void all_func();
    static Element_Button make_element_button(Element** elements_,
                                              int element_max_,Button* button_);
    Element_Button();
    Element_Button(Element** elements_,int element_max_,Button* button_);
};
#include"button_element.cpp"
#endif