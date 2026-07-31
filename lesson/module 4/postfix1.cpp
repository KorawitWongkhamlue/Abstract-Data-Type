#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct record{
    float value;
    struct record *next;
};
typedef struct record *Stack;

//fxs
Stack CreateStack();
void Push(Stack S,float c);
void Pop(Stack S);
float Top(Stack S);
int IsEmpty(Stack S);

Stack CreateStack(){
    Stack S = new struct record;
    if (S == NULL){
        cout << "Error: Out Of Space!" << endl;
    }
    S ->next = NULL;
    return S;
}

void Push(Stack S,float c){
    Stack node = new struct record;
    if (node == NULL){
        cout << "Out Of Space!!"<< endl;
    }
    node->value = c;
    node->next = S->next;
    S->next = node;
}

int IsEmpty(Stack S){
    return S->next == NULL;
}

void Pop(Stack S){
    if (IsEmpty(S)){
        cout << "Empty Stack!" << endl;
    }else{
        Stack FirstCell = new struct record;
        FirstCell = S->next;
        S->next = S->next->next;
        delete(FirstCell);
    }
}

float Top(Stack S){
    if (IsEmpty(S)){
        cout << "Empty Stack!" << endl;
        return '\0';
    }else{
        return S->next->value;
    }
}



int main(){
    Stack S = NULL;
    S = CreateStack();
    string token;

    cout << "Input: ";
    cin >> token;
    while (token != "."){

        //if else for +-*/
        if(token == "."){
            break;
        }else if(token == "+" || token == "-" || token == "*" || token == "/"){
            float val2 = Top(S);
            Pop(S);
            float val1 = Top(S);
            Pop(S);
            float result;

            if (token == "+"){
                result = val1 + val2;
            }else if (token == "-"){
                result = val1 - val2;
            }else if (token == "*"){
                result = val1 * val2;
            }else{
                result = val1 / val2;
            }
            Push(S,result);
        }
        else{
            float num = stof(token);
            Push(S,num);
        }
        cout << "Input: ";
        cin >> token;
    }

    cout << "Ans = " << Top(S);
}