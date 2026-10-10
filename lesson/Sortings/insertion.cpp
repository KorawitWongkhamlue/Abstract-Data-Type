#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}


void insertion_sort(int a[],int n){
    //i = ตัวตั้งให้วน j = ตัว loop ถอยหลัง
    for (int i = 1; i<n;i++){
        for (int j = i; j > 0;j--){
            if (a[j] < a[j-1]){
                swap(a[j],a[j-1]);
            }
            else{
                break;
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
    cout << "Insertion Sort: ";
    insertion_sort(a,10);
    show(a,10);
}