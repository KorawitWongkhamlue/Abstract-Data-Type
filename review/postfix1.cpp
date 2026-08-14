//postfix
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct record{
    float data;
    struct record *next;
};
typedef struct record *Stack;

Stack CreateStack();
void Push(Stack s,float c);
void Pop(Stack s);
float Top(Stack s);
int IsEmpty(Stack s);

Stack CreateStack(){
    Stack s = new struct record;
    if (s == NULL){
        cout << "Out Of Memory";
    }
    else{
        s->next = NULL;
    }
    return s;
}

void Push(Stack s, float c){
    if (s == NULL){
        cout << "Out Of Memory FAHHH";
    }
    else{
        Stack node = new struct record;
        node->data = c;
        node->next = s->next;
        s->next = node;        
    }
}

int IsEmpty(Stack s){
    return s->next == NULL;
}

void Pop(Stack s){
    Stack tmp;
    if (IsEmpty(s)){
        cout << "Empty Stack!";
    }
    else{
        tmp = s->next;
        s->next = tmp->next;
        delete(tmp);
    }
}

float Top(Stack s){
    return s->next->data;
}

int main(){
    Stack s = CreateStack();
    string token;
    float a,b,result;
    cout << "Input : \n";
    
    while (cin >> token){
        if (token == "+" ||token == "-" ||token == "*" ||token == "/"){
            b = Top(s);
            Pop(s);
            a = Top(s);
            Pop(s);
            if (token == "+"){  result = a + b; }
            else if (token == "-"){ result = a - b; }
            else if (token == "*"){ result = a * b; }
            else if (token == "/"){ result = a/b; }
            Push(s,result);
        }
        else if (token =="."){
            break;
        }
        else{
            Push(s,stof(token));
        }
    }

    cout << "Ans = " << result << endl;
}

