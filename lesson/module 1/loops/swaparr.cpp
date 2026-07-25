#include <iostream>
using namespace std;

int main(){
    int temp;
    int a[10] = {10,20,30,40,
                50,60,70,80,90,100};

    
    cout << "Before Swap: " << endl;

    for (int i = 0 ; i < 10 ; i++){
        cout << a[i] << " ";
    }

    cout << endl ;

    temp = a[0];
    a[0] = a[9];
    a[9] = temp;

    cout <<"After Swap: " <<endl;

    for (int i = 0 ; i < 10 ; i++){
        cout << a[i] << " ";
    }
}