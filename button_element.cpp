#include"button_element.h"
#include<cstdlib>
#define C(var)var(var##_)
template<class Element>
Element_Button<Element>::Element_Button():element_count(0),next_element(0){}
template<class Element>
Element_Button<Element>::Element_Button(Element** elements_,int element_max_,Button* button_):
C(elements),C(element_max),C(button),element_count(0),next_element(0){}
template<class Element>
Element_Button<Element> Element_Button<Element>::make_element_button(Element** elements_,
                                   int element_max_,Button* button_){
    Element_Button<Element> ret_val(elements_,element_max_,button_);
    return ret_val;
}
template<class Element>
int Element_Button<Element>::find_next_element(){
    for(int i=0;i<element_max;i++){
        if(!elements[i]->check_placed())return i;
    }
    return -1;
}
template<class Element>
void Element_Button<Element>::draw(){
    for(int i=0;i<element_max;i++){
        elements[i]->draw(button->get_active());
    }
    button->draw();
    sprintf(element_count_str.str,"%d",element_count);
    print(button->x+BUTTON_LENG_X/2,SCREEN_TOP-10,
          element_count<element_max?white:red,
          element_count_str.str);
}
template<class Element>
void Element_Button<Element>::check_button_state(){
    button->collision();
}
template<class Element>
void Element_Button<Element>::active(){
    static int temp_count;
    if(button->get_active()){
        if(m_released && mouse_inbound()){
            if(next_element!=-1){
                temp_count=element_count;
                elements[next_element]->place(&element_count);
                if(element_count!=temp_count)
                    next_element=find_next_element();
                temp_count=element_count;
            }
        }
        if(key[KEY_SPACE])
            elements[next_element]->space_bar_helper();
        if(mouse_b&2){
            for(int i=0;i<element_max;i++){
                if(elements[i]->collision()){
                    elements[i]->erase(&element_count);
                    temp_count=element_count;
                    next_element=i;
                }
            }
        }
    }
}
template<class Element>
void Element_Button<Element>::calc_count(){
    element_count=0;
    for(int i=0;i<element_max;i++){
        if(elements[i]->check_placed())element_count++;
    }
    for(int i=0;i<element_max;i++){
        if(!elements[i]->check_placed()){
            next_element=i;
            return;
        }
    }
}
template<class Element>
void Element_Button<Element>::all_func(){
    draw();
    active();
}