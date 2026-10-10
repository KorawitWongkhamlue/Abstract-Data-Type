#include <iostream>
using namespace std;

void selection_sort(int a[], int n){
    
    for (int i = 0; i < n ; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        if (min !=  i){
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
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
    cout << "Selection Sort: ";
    selection_sort(a,10);
    show(a,10);
}