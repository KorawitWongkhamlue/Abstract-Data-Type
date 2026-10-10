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

void insert_q(int num){
    if (heapsize >= 15){
        cout << "Full Queue";
        return;
    }

    heapsize++;
    int i = heapsize;
    a[i] = num;

    //กรณี ลูกมีค่ามากกว่าพ่อ
    while ( i > 1 && a[parent(i)] < a[i]){
        int tmp = a[i];
        a[i] = a[parent(i)];
        a[parent(i)] = tmp;
        i = parent(i);
    }
}

void service(){
    if (heapsize < 1){
        cout << "empty!";
        return;
    }

    int max = a[1];
    a[1] = a[heapsize]; //เอาตัวท้ายสุดมาแทนในตำแหน่งแรก
    heapsize--;

    heapify(1);

    cout << "Service : " << max << endl;
}

int menu(){
    int choice;
    cout << "========================\n";
    cout << "          MENU\n";
    cout << "========================\n";
    cout << "1. Input Array\n";
    cout << "2. Print Heap\n";
    cout << "3. Insert Queue\n";
    cout << "4. Service\n";
    cout << "5. Exit\n";
    cout << "  Please Choose >";
    cin >> choice;
    return choice;
}

int main(){
    int choose;
    do{
        choose = menu();
        switch (choose){
            case 1:{
                input_arr();
                break;
                break;
                }
            case 2:{
                print_heap();
                break;
                break;
                }
            case 3:{
                int n;
                cout << "Input : ";
                cin >> n;
                insert_q(n);
                print_heap();
                break;
                break;
            }
            case 4:{
                service();
                print_heap();
                break;
                break;
            }
            case 5:{
                break;
            }
        }
    }while(choose != 5);

    /*
    switch (expression)
    {
    case constant expression:
        /* code 
        break;
    
    default:
        break;
    } */
}

