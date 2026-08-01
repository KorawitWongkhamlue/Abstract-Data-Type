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

int enqcount = 0;
int WaitTime = 0;

void Enqueue(int x){
    //ตัวแรก
    if (front == NULL){
        front = new struct record;
        front->value = x;
        front->next = NULL;
        rear = front;
    }else{
        //ต่อ
        Queue node = new struct record;
        node->value = x;
        node->next = NULL;
        rear->next = node;
        rear = node;
    }
    enqcount++;
    WaitTime = WaitTime + 2;
}

int IsEmpty(){
    return front == NULL;
}

void Dequeue(){
    if (IsEmpty()){
        cout << "----------\n";
        cout << "Empty Queue!" << endl;
        cout << "----------\n";
    }
    else{
        Queue tmp = front;
        front = front->next;
        delete(tmp);
        enqcount--;
        WaitTime = WaitTime - 2;
    }
}

int menu(){
    int choose;
    cout << "    Menu\n";
    cout << "1) Enqueue\n";
    cout << "2) Dequeue\n"; 
    cout << "3) Exit\n";
    cout << "     Please choose > ";
    cin  >> choose;

    return choose;
}


int main(){
    int choose, qnum;

    do{
        choose = menu();
        switch (choose)
        {
            case 1: //Enqueue
                qnum = enqcount + 1;
                Enqueue(qnum);
                cout << "----------\n";
                cout << "Queue number " << rear->value << endl;
                cout << "People in Queue = " << enqcount-1 << endl;
                cout << "Waiting time " << WaitTime - 2  << " Mins" << endl;
                cout << "----------\n";
                getchar();
                break;
            case 2: //Dequeue
                if(!IsEmpty()){
                    cout << "----------\n";
                    cout << "Head Queue #1" << endl;
                    cout << "Service #1" << endl;
                    cout << "----------\n";
                    getchar();
                }
                Dequeue();
                break;
            case 3: break;
        }
    }while(choose != 3);

}