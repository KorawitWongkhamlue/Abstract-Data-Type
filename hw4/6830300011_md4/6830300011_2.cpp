//6830300011
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Node{
    int value;
    struct Node *next;
};
typedef struct Node *Stack;

//fx
Stack CreateStack(void);
void Push(int x, Stack S);
void Pop(Stack S);
int Top(Stack S);
int IsEmpty(Stack S);
void MakeEmpty(Stack s);

int IsEmpty(Stack S){
    return S->next == NULL; //return เงื่อนไขว่า 0 หรือ 1
}

Stack CreateStack(void){
    Stack S = new struct Node;
    if (S == NULL){
        cout << "Out Of Space!!"<< endl;
    }
    S->next = NULL;
    return S;
}

void Push(int x, Stack S){
    Stack TmpCell = new struct Node;
    
    if (TmpCell == NULL){
        cout << "Out Of Space!!"<< endl;
    }
    TmpCell->value = x;
    TmpCell->next = S->next;
    S->next = TmpCell;
}



void Pop(Stack S){
    Stack FirstCell = new struct Node;

    if (IsEmpty(S)){
        cout << "stack underflow" << endl;
    }else{
        FirstCell = S->next;
        S->next = S->next->next;
        delete(FirstCell);
    }
}

void MakeEmpty(Stack S){
    if (S == NULL){
        cout << "Must Create Stack First!" << endl;
    }else{
        while(!IsEmpty(S)){
            Pop(S);
        }
    }
}

int Top(Stack S){
    if (!IsEmpty(S)){
        return S->next->value;
    }else{
        cout << "Empty Stack!";
        return 0;
    }
}

int menu(){
    int choose;
    cout << "=============\n";
    cout << "    MENU\n";
    cout << "=============\n";
    cout << "1)Push\n";
    cout << "2)Pop\n";
    cout << "3)Top\n";
    cout << "4)Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}


int main(){
    Stack S = NULL;
    S = CreateStack();
    int choose = 0;
    do{
        choose = menu();
        switch (choose){
            case 1: int x;
                    cout << "Push : ";
                    cin >> x;
                    Push(x,S);
                    cout << "Top = " << Top(S);
                    getchar();
                    getchar();
                    break;
                    
            case 2: 
                    if (!IsEmpty(S)){ //ถ้าไม่ว่าง
                        cout << "Top = " << Top(S) << endl;
                        Pop(S);
                        cout << "Pop success!";
                    }else{
                        Pop(S);
                    }
                    getchar();
                    getchar();
                    break;
            case 3: if (!IsEmpty(S)) cout << "Top = " << Top(S) << endl;
                    else Top(S);
                    getchar();
                    getchar();
                    break;
            case 4: break;
        }
    }while(choose!=4);
}
