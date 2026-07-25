#include <iostream>
using namespace std;

int main(){
    
    int i, j;
    for (j=1 ; j <= 5 ; j++){
        cout << j;
    }

    cout << endl ; cout << endl ;

    for (i =1; i <= 5; i++){
        for (j=1 ; j <= 5 ; j++){
        cout << j;
        }

        cout << endl;
    }

    cout << endl ; cout << endl ;

    for (i = 1 ; i <= 5; i++){
        for (j = 1; j <= i; j++){
            cout << j;
            
        }
        cout << endl ;
    }

//ARRAYS------------------------------

    cout << endl;

    int a[5] = {20,15,17,13,8};

    for (int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }


}