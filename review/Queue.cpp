//Queue
#include <iostream>
#include <stdio.h>
using namespace std;

struct record{
    int value;
    struct record *next;
};
typedef struct record *Queue;

Queue front = NULL;
Queue rear = NULL;

void Enqueue(int x);
void Dequeue();
int IsEmpty();

int count = 0;

void Enqueue(int x){
    if (front == NULL){
        front = new struct record;
        front->value = x;
        front->next = NULL;
        rear = front;
    }else{
        Queue node = new struct record;
        node->value = x;
        rear->next = node;
        rear = node;
        rear->next = NULL;
    }
    count++;
}

int IsEmpty(){
    return front == NULL;
}

void Dequeue(){
    Queue tmp = new struct record;
    if (IsEmpty()){
        cout << "Empty Queue!\n";
        return;
    }
    else{
        //ตัวเดียว
        tmp = front;
        front = front->next;
        delete(tmp);
        count--;
    }
}

int menu(){
    int choose;
    cout << "===MENU===\n";
    cout << "1) Enqueue\n";
    cout << "2) Dequeue\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

int main(){
    int choose;
    int time = 0;
    do{
        choose = menu();
        switch (choose){
            case 1:{
            int x = count+1;
            Enqueue(x);
            cout << "Queue number " << x << endl;
            cout << "People in Queue = " << count-1 << endl;
            cout << "Waiting time " << time << " Mins";
            time += 2;
            getchar();
            getchar();
            break;
            }
            case 2:
            Dequeue();
            if (!IsEmpty()){
                cout << "Head Queue#1\n";
                cout << "Service#1\n";
            }
            if (time > 0){
                time -= 2;
            }
            break;
            case 3:
            break;
            case 4:
            break;

        }
    }while(choose != 3);
}