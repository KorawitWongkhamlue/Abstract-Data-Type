#include <iostream>
#include <vector>
using namespace std;

int a[30] = {0, 42, 15, 89, 4, 23, 77, 56, 12, 99, 31, 65, 8, 44, 27, 51, 83, 19, 36, 73, 90};
int length = 20;
int heapsize = 20;

void heapify(int a[],int i){
    int l = 2*i;
    int r = 2 * i + 1;
    int largest = i;

    if (l <= heapsize && a[l] > a[i]){
        largest = l;
    }
    if (r <= heapsize && a[r] > a[largest]){
        largest = r;
    }

    if (largest != i){
        int tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        heapify(a,largest);
    }
}

void build_heap(int a[]){
    for (int i = length/2; i >= 1 ;i--){
        heapify(a,i);
    }
}

void heap_sort(int a[]){
    build_heap(a);
    for (int i = length; i > 1; i--){
        int tmp =a[1];
        a[1] = a[i];
        a[i] = tmp;
        heapsize--;
        heapify(a,1);
    }
}

int main(){
    heap_sort(a);

    for (int i = 1; i <= length ;i++){
        cout << a[i] << " ";
    }
}