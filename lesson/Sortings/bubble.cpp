#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void bubble_sort(int a[],int n){
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}


void show(int a[], int n){
    for (int i = 0; i < n ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[10] =  {67, 3, 84, 29, 51, 90, 17, 44, 76, 38};
    
    cout << "Normal Array: ";
    show(a,10);
    cout << "Bubble Sort: ";
    bubble_sort(a,10);
    show(a,10);
}