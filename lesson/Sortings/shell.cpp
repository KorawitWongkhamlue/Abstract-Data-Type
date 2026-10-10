#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}


void shell_sort(int a[],int n){

    fot (int gap = n/2; gap > 0; gap/= 2){
        for (int i = gap; i < n; i++){
            int tmp = a[i];
            int j;
            for (j = i; j >= gap && a[j-gap] > tmp; j -=gap){
                a[j] = a[j-gap];
            }
            a[j] = tmp;
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
    cout << "Shell Sort: ";
    shell_sort(a,10);
    show(a,10);
}