//infix to postfix
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct record{
    string data;
    struct record *next;
};
typedef struct record *Stack;

Stack CreateStack();
void Push(Stack s,string c);
void Pop(Stack s);
string Top(Stack s);
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

void Push(Stack s, string c){
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

string Top(Stack s){
    if (!IsEmpty(s)){
        return s->next->data;
    }
    return "";
}

int main(){

    Stack s = CreateStack();
    string str = " ";
    string input;

    while (cin >> input){
        if ( input == "."){
            break;

        }
        else if (input == "*" || input == "/"){
            string top = Top(s);
            if(top == "*" || top == "/"){
                    str += top + " ";
                    Pop(s);
            }
            else{
                Push(s,input);
            }
        }

        else if (input == "+" || input == "-"){
            string top = Top(s);
            if(top == "+" || top == "-" || top == "*" || top =="/" ){
                str = str + top;
                Pop(s);
                Push(s,input);
            }
            else{
                Push(s,input);
            }
        }else{
            str = str + input;
        }
    }

    if (!IsEmpty(s)){
        while (!IsEmpty(s)){
            string top = Top(s);
            str = str + top;
            Pop(s);
        }
    }

    cout << "Ans =" << str << endl;
}
