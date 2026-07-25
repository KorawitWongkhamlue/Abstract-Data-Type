#include <iostream>
using namespace std;

void backToFront(int n){
    if (n == 0) return;
    cout << n % 10;
    backToFront(n / 10);
}

void frontToBack(int n){
    if (n ==0) return;
    frontToBack(n /10);
    cout << n % 10;
}

int main(){

    int n;
    cout << "Input : ";
    cin >> n;

    cout << "Output :" << endl;


    cout << "1) ";
    backToFront(n);
    cout << endl;

    cout << "1) ";
    backToFront(n/10);
    cout << endl;

    cout << "3) ";
    frontToBack(n);
    cout << endl;

    cout << "4) ";
    frontToBack(n / 10);
    cout << endl;
}