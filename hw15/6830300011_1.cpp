#include <iostream>

#include <fstream>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <random>
using namespace std;

#define MAXV 100000
#define NB 10000
#define N 3000000

vector<int> bucket[NB];
int a[N];


void createRandomFile(){
    srand(time(0));
    ofstream myfile ("random.dat");

    if (myfile.is_open()){
        for (int i = 0; i < N; i++){
            int r = (rand() << 15) | rand();
            myfile << r % 100000 + 1 << " ";
        }
        myfile.close();
        cout << "Write data Success\n";
    }
    else cout << "Unable to open file\n";
}

void readFile(){
    ifstream readfile("random.dat");
    if (!readfile.is_open()){
        cout << "Unable to open random.dat (create it with menu 1 first)\n";
        return;
    }

    for (int i = 0; i < N; i++){
        readfile >> a[i];
    }
    readfile.close();
}

void writeFile(const char* name){
    ofstream outfile(name);
    if (!outfile.is_open()){
        cout << "Unable to open file\n";
        return;
    }
    for (int i = 0; i < N; i++){
        outfile << a[i] << " ";
    }
    outfile.close();
    cout << "Write " << name << " Success\n";
}

void myswap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void selection_sort(){
    for (int i = 0; i < N-1 ; i++){
        int min = i;
        for (int j = i+1; j < N; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        myswap(a[i],a[min]);
    }
}

void bubble_sort(){
    for (int i = 0; i < N-1; i++){
        for (int j = 0; j < N- 1 - i; j++){
            if (a[j] > a[j+1]){
                myswap(a[j],a[j+1]);
            }
        }
    }
}

void insertion_sort(){

    for (int i = 1; i < N ; i++){
        for (int j = i; j > 0; j--){
            if (a[j] < a[j-1]){
                myswap(a[j-1],a[j]);
            }
            else{break;}
        }
    }
}

int tmp[N];
void merge(int a[],int tmp[], int lpos, int rpos, int rightend){

    int tmppos = lpos;
    int leftend = rpos -1;
    int numelem = rightend - lpos + 1;

    while ( lpos <= leftend && rpos <= rightend){
        if (a[lpos] < a[rpos]){
            tmp[tmppos++] = a[lpos++];
        }else{
            tmp[tmppos++] = a[rpos++];
        }
    }

    while (lpos <= leftend){   
        tmp[tmppos++] = a[lpos++];
    }
    while(rpos <= rightend){
        tmp[tmppos++] = a[rpos++];
    }

    for (int i = 0; i < numelem; i++,rightend--){
        a[rightend] = tmp[rightend];
    }
}


void msort(int a[],int tmp[],int left, int right){
    int center;
    if (left < right){
        center = (left+right)/2;
        msort(a,tmp,left,center);
        msort(a,tmp,center+1,right);
        merge(a,tmp,left,center+1,right);
    }
}

void quick_sort(int left,int right){
    if (left >= right) return;

    int pivot = a[(left+right)/2];
    int i = left, j = right;

    while ( i<= j){
        while (a[i] < pivot){ i++;}
        while (a[j] > pivot){j--;}
        if (i <= j){
            myswap(a[i], a[j]);
            i++;j--;
        }
    }
    quick_sort(left,j);
    quick_sort(i,right);
}

void heapify(int n,int i){
    int largest = i;
    int l = i*2+1;
    int r = i*2+2;
    if (l < n && a[l] > a[i]){
        largest = l;
    }
    if (r < n && a[r] > a[largest]){
        largest = r;
    }

    if (largest != i){
        myswap(a[largest],a[i]);
        heapify(n,largest);
    }
}

void build_heap(){
    for (int i = N/2-1; i >= 0; i--){
        heapify(N,i);
    }
}

void heap_sort(){
    build_heap();
    for (int i = N-1; i > 0; i--){
        myswap(a[0],a[i]);
        heapify(i,0);
    }
}

void bucket_sort(){
    for (int b = 0; b < NB; b++){
        bucket[b].clear();
    }

    for (int i = 0; i < N;i++){
        int idx = (a[i] - 1) / (MAXV / NB);
        bucket[idx].push_back(a[i]);
    }

    int k = 0;
    for (int b = 0; b < NB; b++){
        for (int i = 1; i < (int)bucket[b].size();i++){
            int key = bucket[b][i];
            int j = i-1;
            while ( j >= 0 && bucket[b][j] > key){
                bucket[b][j+1] = bucket[b][j];
                j--;
            }
            bucket[b][j+1] = key;
        }
        for (int x : bucket[b]){
            a[k++] = x;
        }
    }
}

void radix_sort(){
    int maxVal = a[0];
    for (int i = 1; i < N ; i++){
        if (a[i] > maxVal){
            maxVal = a[i];
        }
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10){
        int count[10] = {0}; //ช่วง 0-9

        for (int i = 0; i < N; i++){
            int digit = (a[i] / exp) % 10; //หลักปัจจุบันของ a[i]
            count[digit]++;
        }

        for (int d = 1; d < 10; d++){
            count[d] += count[d-1];
        }

        for (int i = N-1 ; i >= 0; i--){
            int digit = (a[i] / exp) % 10;
            tmp[--count[digit]] = a[i];
        }

        for (int i = 0; i < N; i++){
            a[i] = tmp[i];
        }
    }
}

int menu(){
    int choice;
    cout <<"--------------------------------------------\n";
    cout <<"1) Create Random File       6) Quick Sort\n";
    cout <<"2) Selection Sort           7) Heap Sort\n";
    cout <<"3) Bubble Sort              8) Bucket Sort\n";
    cout <<"4) Insertion Sort           9) Radix Sort\n";
    cout <<"5) Merge Sort               10) Exit\n";
    cout <<"--------------------------------------------\n";
    cout << "Please choose > ";
    cin >> choice;

    return choice;
}

int main(){
    int choice;
    do{
        choice = menu();
        switch (choice)
        {
        case 1:
            createRandomFile();
            break;
        case 2:
            readFile();
            selection_sort();
            writeFile("selection.out");
            //
            break;
        case 3:
            readFile();
            bubble_sort();
            writeFile("bubble.out");
            //
            break;
        case 4:
            readFile();
            insertion_sort();
            writeFile("insertion.out");
            //
            break;
        case 5:
            readFile();
            msort(a,tmp,0,N-1);
            writeFile("merge.out");
            //
            break;
        case 6:
            readFile();
            quick_sort(0, N - 1);
            writeFile("quick.out");
            //
            break;
        case 7:
            readFile();
            heap_sort();
            writeFile("heap.out");
            //
            break;
        case 8:
            readFile();
            bucket_sort();
            writeFile("bucket.out");
            //
            break;
        case 9:
            readFile();
            radix_sort();
            writeFile("radix.out");
            //
            break;
        case 10:
            break;
        }

    }while(choice != 10);
}