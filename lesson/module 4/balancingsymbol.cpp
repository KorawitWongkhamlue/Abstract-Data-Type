/*
ถ้า input ครบ ไม่แสดงอะไร
) ไม่ครบ
} ไม่ครบ
 คู่ไม่ตรง
 ไม่มีเครื่องหมายเปิด
*/

#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

struct record{
    char value;
    struct record *next;
};
typedef struct record *Stack;

//fxs
Stack CreateStack();
void Push(Stack S,char c);
void Pop(Stack S);
char Top(Stack S);
int IsEmpty(Stack S);

Stack CreateStack(){
    Stack S = new struct record;
    if (S == NULL){
        cout << "Error: Out Of Space!" << endl;
    }
    S ->next = NULL;
    return S;
}

void Push(Stack S,char c){
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

char Top(Stack S){
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
    bool error = false;

    //input แบบ: , stop{ = push normally,)} = needs if else shit
    char c;
    cout << "Input: ";
    cin.get(c);
    while (c != '.' && !error){
        //open brackets
        if (c == '(' || c == '{'){
            Push(S,c);
        }else if (c == ')' || c == '}'){
            //check ว่า ) มี ( in stack?, or } have { in stack?
            if (IsEmpty(S)){
                cout << "Error: Missing Opening!" << endl;
                error = 1;
            }else{
                char opened = Top(S);
                Pop(S);
                if (c == ')' && opened != '('){
                    cout << "Error: Unmatched closing bracket!" << endl;
                    error = true;
                }
                else if (c == '}' && opened != '('){
                    cout << "Error: Unmatched closing bracket!" << endl;
                    error = true;
                }
            }
        }
        cin.get(c);
    }

    if (!error && !IsEmpty(S)){
        char remain = Top(S);
        if (remain == '('){
            cout << "Error : Expected ')" << endl;
        }else if (remain == '{'){
            cout << "Error : Expected '}'" << endl;
        }
    }
    return 0;
}

