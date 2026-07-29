//6830300011
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Node{
    char value;
    struct Node *next;
};
typedef struct Node *Stack;

//fxs
Stack CreateStack(void);
void Push(char x, Stack S);
void Pop(Stack S);
char Top(Stack S);
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

void Push(char x, Stack S){
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


char Top(Stack S){
    return S->next->value;
}



int main(){
    Stack S = NULL;
    S = CreateStack();

    char c;
    bool error = false;

    cin.get(c);
    //input แล้วเอามา process ต่อ
    while (c != '.' && !error){
        if (c == '(' || c == '{'){
            Push(c, S);
        }
        else if (c ==')' || c == '}'){
            if (IsEmpty(S)){
                cout << "Error : Missing opening" << endl;
                error = true;
            }
            else{
                char opened = Top(S);
                Pop(S);
                if (c == ')' && opened != '('){
                    cout << "Error : Unmatched closing bracket" << endl;
                    error = true;
                }
                else if (c == '}' && opened != '{'){
                    cout << "Error : Unmatched closing bracket" << endl;
                    error = true;
                }
            }
        }
        cin.get(c);
    }

    if (!error && !IsEmpty(S)){
        char remain = Top(S);
        if (remain == '('){
            cout << "Error : Expected ')'" << endl;
        }
        else if (remain == '{'){
            cout << "Error : Expected '}'" << endl;
        }
    }

    return 0;
}