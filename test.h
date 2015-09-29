#ifndef TEST_H
#define TEST_H
#define C(var)var(var##_)
class Name_Tag{
    public:
    int id;
    String name;
    void print_data();
    Name_Tag(const char* name_,int id_);
};
#endif