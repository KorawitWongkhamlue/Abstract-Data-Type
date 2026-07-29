//6830300011
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    float value;
    struct Node *next;
};
typedef struct Node *Stack;

//fxss
Stack CreateStack(void);
void Push(float x, Stack S);
void Pop(Stack S);
float Top(Stack S);
int IsEmpty(Stack S);

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

void Push(float x, Stack S){
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
        //
    }else{
        FirstCell = S->next;
        S->next = S->next->next;
        delete(FirstCell);
    }
}


float Top(Stack S){
    return S->next->value;
}

int main(){
    Stack S = NULL;
    S = CreateStack();

    string token;
    while (cin >> token){
        if (token == "."){
            break;
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/"){
            float b = Top(S);
            Pop(S);
            float a = Top(S);
            Pop(S);
            float result;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else result = a/b;

            Push(result,S);
        }
        else{
            float number = stof(token);
            Push(number,S);
        }
    }

    cout << "Ans = " << Top(S) << endl;

    return 0;
}