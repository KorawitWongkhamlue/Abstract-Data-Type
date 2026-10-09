#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int length;
int heapsize = 10;
int A[30] = {0, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

int left(int i){
    return i*2;
}

int right(int i ){
    return i*2 + 1;
}

int parent(int i)
{    return i/2;  }



void heapify(int i){
    int largest;
    int l = left(i);
    int r = right(i);

    if (l <= heapsize && A[l] > A[i]){ //เทียบ i กับ left
        largest = l;
    }else{
        largest = i;
    }

    if (r <= heapsize && A[r] > A[largest]){ //เอามาเทียบต่อกับ r
        largest = r;
    }

    //ถ้า i ไม่ใช่ตัวที่ใหญ่สุด (i ไม่ได้ใหย่สุด)
    if (largest != i){ //สลับค่าโหนดนั้นๆ
        int tmp = A[largest];
        A[largest] = A[i];
        A[i] = tmp;
        heapify(largest); //recursive เพื่อเช็คว่ามันตรงตามหลักไหม+
    }
}

void Build_heap(int A[]){
    length = heapsize;
    for (int i = length/2; i >= 1 ; i--){
        heapify(i);
    }
}

void heap_sort(int A[]){
    Build_heap(A);

    for (int i = length ; i >= 2; i--){
        int tmp = A[1];
        A[1] = A[i];
        A[i] = tmp;

        heapsize--;
        heapify(1);
    }
}

void heap_insert(int A[], int key){ //เพิ่มค่า
    heapsize = heapsize +1;
    int i = heapsize;

    while (i > 1 && A[parent(i)] < key){
        A[i] = A[parent(i)];
        i = parent(i);
    }
    A[i] = key;
}

int Maximum(){
    return A[1];
}

int Extract_max(int A[]){ //ดึงค่ามากสุดออกมา

    int max = A[1];
    A[1] = A[heapsize]; //เอาตัวสุดท้ายไว้ที่ root
    heapsize = heapsize -1;
    heapity(1);

    return max_val;
}

int main(){
    Build_heap(A);
    heap_sort(A);

    for(int i= 1; i<=10; i++){
        cout << A[i] << " ";
    }
}