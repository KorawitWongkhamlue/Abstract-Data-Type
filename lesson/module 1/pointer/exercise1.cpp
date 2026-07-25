#include <iostream>
using namespace std;

int main(){

    float a, *ptr;

    a = 3.14;
    ptr = &a;
    cout << *ptr;

    return 0;
}