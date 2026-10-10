#include <iostream>
#include <vector>
#include <list>
using namespace std;

int a[16];
int heapsize = 10;

int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}

int parent(int i){
    return i/2;
}

void heapify(int i){
    int largest = i;
    int l = left(i);
    int r = right(i);

    //largest find
    if (l <= heapsize && a[l] > a[i]){
        largest = l;
    }
    else{
        largest = i;
    }

    if (r <= heapsize && a[r] > a[largest]){
        largest = r;
    }

    if (largest != i){
        int tmp = a[largest];
        a[largest] = a[i];
        a[i] = tmp;
        heapify(largest);
    }
}

void build_heap(int a[]){
    for (int i = heapsize/2; i >= 1; i--){
        heapify(i);
    }
}

void input_arr(){
    a[0] = {0};
    cout << "Input : ";
    for (int i = 1; i <= heapsize; i++){
        cin >> a[i];
    }
    build_heap(a);
}


void print_heap(){
    cout << "Heap : ";
    for (int i = 1; i <= heapsize; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Input : ";
    for (int i = 1 ; i <= heapsize; i++){
        cin >> a[i];
    }

    build_heap(a);
    print_heap();
}

