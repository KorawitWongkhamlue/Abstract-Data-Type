//Josephus Problem
//6830300011
#include <stdio.h>
#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};
typedef struct record *Queue;

Queue front = NULL;
Queue rear = NULL;

//fxs
void Enqueue(int x);
void Dequeue();
int IsEmpty();

void Enqueue(int x){
    if (front == NULL){
        front = new struct record;
        front->value = x;
        front->next = front;
        rear = front;
    }else{
        Queue node = new struct record;
        node->value = x;
        rear->next = node;
        rear = node;
        node->next = front;
    }
}

int IsEmpty(){
    return front == NULL;
}

void Dequeue(){
    if (IsEmpty()){
        cout << "Empty Queue!" << endl;
    }else{
        Queue tmp = front;
        front = front->next;
        delete(tmp);
    }
}

int main(){
    int n,m;
    cout << "Input Total Players: ";
    cin >> n;
    cout << "Input Passes: ";
    cin >> m;

    //enqueue โดย label แต่ละคิวอิงตาม i
    for (int i = 1 ; i <= n; i++){
        Enqueue(i);
    }

    cout << "Eliminate : ";
    while (n > 1){
        
        for (int i = 0; i < m; i++){ //loop ให้หัวแถวไปต่อท้าย m ครั้ง
                                    //ทำให้อี m+1 อยู่หน้าสุด แล้วจะโดน dequeue
            int x = front->value;
            Dequeue();
            Enqueue(x);
        }
        cout << front->value << " ";
        Dequeue();
        n--;
    }
    cout << "\n" << "Winner : " << front->value << endl;
}