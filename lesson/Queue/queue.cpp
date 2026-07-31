#include <stdio.h>
#include <iostream>
using namespace std;

//queue = linked list ที่ insert ฝั่งขวาสุด/ delete ซ้ายสุด
//data เรียงตามคิว

//node ปกติตาม linked list
struct record{
    int value;
    struct record *next;
};

struct QueueRecord{
    struct record *Front;
    struct record *Rear;
};
typedef QueueRecord *Queue;

//fxs
Queue CreateQueue();
void Enqueue(Queue Q, int x);
void Dequeue(Queue Q);
int IsEmpty(Queue Q);
int Front(Queue Q);

Queue CreateQueue(){
    Queue Q = new QueueRecord;
    Q->Front = NULL;
    Q->Rear = NULL;
    return Q;
}

int IsEmpty(Queue Q){
    return Q->Front == NULL;
}

void Enquque(Queue Q, int x){
    //สร้าง node เหมือนปกติ
    struct record *node = new struct record;
    node->value = x;
    node->next = NULL;

    //กำหนดให้ queue
    if (IsEmpty(Q)){
        Q->Front = node;
        Q->Rear = node;
    }
    else{
        Q->Rear->next = node;
        Q->Rear = node;
    }
}


void Dequeue(Queue Q){
    if (IsEmpty(Q)){
        cout << "Empty Queue" << endl;
    }
    else{
        struct record *tmp = Q->Front;
        Q->Front = Q->Front->next;
        if (Q->Front == NULL){
            Q->Rear = NULL;
        }
        delete(tmp);
    }
}

int Front(Queue Q){
    if(IsEmpty(Q)){
        cout << "Empty Queue!" << endl;
        return 0;
    }
    return Q->Front->value;
}

int main(){
    Queue Q = CreateQueue();

    Enqueue(Q,10);
    Enqueue(Q,20);
    Enqueue(Q,30);

    cout << "Front = " << Front(Q) << endl;   //ควรได้ 10 (ตัวแรกที่เข้ามา)

    Dequeue(Q);
    cout << "After dequeue, Front = " << Front(Q) << endl;   //ควรได้ 20

    Dequeue(Q);
    cout << "After dequeue, Front = " << Front(Q) << endl;   //ควรได้ 30

    Dequeue(Q);
    cout << "IsEmpty? " << IsEmpty(Q) << endl;   //ควรได้ 1 (ว่างแล้ว)

    Dequeue(Q);   //dequeue ตอนว่าง ควรขึ้น "Empty Queue!"

    return 0;
}


