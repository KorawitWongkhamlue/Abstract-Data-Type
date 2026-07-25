#include <iostream>
using namespace std;

int fibo(int n){
    if (n == 0) {
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return fibo(n-1) + fibo(n-2);
}

int main(){
    for (int i = 0; i <= 19; i++){
        cout << "F(" << i << ") = " << fibo(i) << endl;
    }
}