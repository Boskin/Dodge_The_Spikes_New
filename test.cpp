#include<iostream>
#include<cstdlib>
#include"string.h"
#include"test.h"
using std::cout;
using std::cin;
using std::endl;
Name_Tag::Name_Tag(const char* name_,int id_):C(id){name=name_;}
void Name_Tag::print_data(){
    cout<<"Name: "<<name.str<<endl;
    cout<<"ID: "<<id<<endl;
}
int main(){
    Name_Tag tag("Boskin Erkocevic",12);
    String sub=tag.name.sub_str(7,15);
    sub.remove_char('c');
    cout<<sub.str<<endl;
    system("pause");
    return 0;
}