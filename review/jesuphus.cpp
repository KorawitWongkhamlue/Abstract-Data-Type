//josephus
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
        rear->next = front;
    }
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
    }
}

int main(){
    int n,m;
    cout << "Input N = ";
    cin >> n;
    cout << "Input M = ";
    cin >> m;


    for(int i = 1; i <= n;i++){
        Enqueue(i);
    }

    cout << "eliminated : ";
    while (n > 1){

        for (int i = 0; i < m ; i++){
            int x = front->value;
            Dequeue();
            Enqueue(x);
        }
        //2 3 4 5 1
        cout << front->value << " ";
        Dequeue();
        n--;
    }

    cout << "\n" << "Winner : " << front->value;

}
