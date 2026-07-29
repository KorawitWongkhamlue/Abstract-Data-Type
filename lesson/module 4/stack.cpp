//Stack
//Create Stack, Push, Pop
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Node{
    int value;
    struct Node *next;
};
typedef struct Node *Stack;

//fx ทีจะใช้
int IsEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(Stack S, int x);
void Pop(Stack S);

//สร้างตัวชี้ S
Stack CreateStack(void){
    Stack S = new struct Node;
    if (S == NULL){
        cout << "Out Of Space Jaa!!" << endl;
    }
    S->next = NULL;
    return S;
}

void Push(Stack S, int x){
    Stack TmpCell; //ที่ใส่ node ที่สร้างใหม่ชั่วคราว
    TmpCell = new struct Node;
    if (TmpCell == NULL){
        cout << "Out Of Space Jaa!!" << endl;
    }
    else{
        TmpCell->value = x;
        TmpCell->next = S->next; //เชื่อมกับ node ที่มีอยู่แล้ว
        S->next = TmpCell; //กำหนดให้ tmpcell ล่าสุึดเป็น top 
    }

}

int IsEmpty(Stack S){
    return S->next == NULL;
}

void MakeEmpty(Stack S){
    if (S == NULL){
        cout << "Must use CreateStack First!!" << endl;
    }else{
        while(!IsEmpty(S)){
            Pop(S);
        }
    }
}

int Top(Stack S){
    if (!IsEmpty(S)){
        return S->next->value;
    }
    else{
        cout << "Empty Stack!!!" << endl;
        return 0;
    }
}

void Pop(Stack S){
    Stack FirstCell;
    if(IsEmpty(S)){
        cout << "EMPTY STACK AI SUDDD!!!";
    }
    else{
        FirstCell = S->next;
        S->next = S->next->next;
        delete(FirstCell);
    }
}

int main(){ 
    Stack S = NULL;
    S = CreateStack();
}