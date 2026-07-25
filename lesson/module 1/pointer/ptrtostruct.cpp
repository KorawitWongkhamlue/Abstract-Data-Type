#include <iostream>
using namespace std;

struct record{
    int id;
    float grade;
};

int main(){
    struct record std1, std2 ;
    struct record *ptr;

    std1.id = 100;
    std1.grade = 2.75;

    ptr = &std2;
    (*ptr).id = 101;
    ptr->id = 101;
    //std2->grade = 3.18; //ทำไม่ได้
    (*ptr).grade = 3.18;
    ptr->grade = 3.18;
}