#include <iostream>
#include <stdio.h>
#include <string.h>

struct Node{
    char value;
    struct Node *next;
};
typedef struct Node *Stack;

//fx
Stack CreateStack(void);
void Push(Stack S, char c);
void Pop(Stack S);
char Top(Stack S);
int IsEmpty(Stack S);

Stack CreateStack(void){
    Stack S = new struct Node;
    if (S == NULL){
        cout << "Out of Space ja" << endl;
    }
    S->next = NULL;
    return S;
}

void Push(Stack S, char c){
    Stack TmpCell = NULL;

    if (TmpCell == NULL){
        cout << "Out of Space ja" << endl;
    }
    TmpCell->value = c;
    TmpCell->next = S->next;
    S->next = TmpCell;
}

int IsEmpty(){
    return S->next == NULL;
}

void Pop(Stack S){
    Stack FirstCell = new Struct Node;

    if (IsEmpty(S))
    FirstCell = S->next;
    S->next = S->next->next;
    delete(FirstCell);
}

char Top(S){
    if (!IsEmpty(S)){
        return S->next->value;
    }
}


int main(){
    Stack S = NULL;
    S = CreateStack();
    bool error = false;

    //4 conditions: ')' ไม่ครบ, '}' ไม่ครบ, คู่ไม่ตรง, ไม่มีเครื่องหมายเปิด
    cin.get(c)
    while (c != '.' && !error){
        //input open bracket
        if (c == '(' || c == '{'){
            Push(S,c);
        }
        else{
            //checkempty
            if(IsEmpty){
                cout << "Error : Missing opening" << endl;
                error = true;
            }else{
                char opened = Top(S);
                Pop(S);
                if (c = ')' && opened != '{'){

                }
            }
        }
    }
}