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
        //ตัวแรก
        front = new struct record;
        front->value = x;
        front->next = NULL;
        rear = front;
        rear->next = front;
    }else{
        Queue node = new struct record;
        node->value = x;
        rear->next = node;
        rear = node;
        rear->next = front;
    }
}

int IsEmpty(){
    return front == NULL;
}

void Dequeue(){
    if (IsEmpty()){
        cout << "Empty Queue!" << endl;
    }
    else{
        Queue tmp = front;
        front = front->next;
        rear->next = front;
        delete(tmp);
    }
}

void PrintQueue(){
    if (IsEmpty()){
        cout << "Empty Queue!" << endl;
    }else{
        Queue p = front;
        cout << "Queue: ";
        do{
            cout << p->value << " " ;
            p = p->next;
        } while (p != front);
    }
}

int main(){
    Enqueue(10);
    Enqueue(30);
    Enqueue(20);
    Enqueue(10);

    PrintQueue();

    cout << "\n" << "Dequeing 1 queues" << endl;
    Dequeue();
    PrintQueue();

    cout << "\n" << "Dequeing 2 queues" << endl;
    Dequeue();
    Dequeue();
    PrintQueue();
}