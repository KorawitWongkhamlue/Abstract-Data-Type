#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct record{
    string value;
    struct record *next;
};
typedef struct record *Stack;

//fxs
Stack CreateStack();
void Push(Stack S,string c);
void Pop(Stack S);
string Top(Stack S);
int IsEmpty(Stack S);

Stack CreateStack(){
    Stack S = new struct record;
    if (S == NULL){
        cout << "Error: Out Of Space!" << endl;
    }
    S ->next = NULL;
    return S;
}

void Push(Stack S,string x){
    Stack node = new struct record;
    if (node == NULL){
        cout << "Out Of Space!!"<< endl;
    }
    node->value = x;
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

string Top(Stack S){
    if (IsEmpty(S)){
        cout << "Empty Stack!" << endl;
        return "\0";
    }else{
        return S->next->value;
    }
}

int main(){
    Stack S = NULL;
    Stack Ans = NULL;
    S = CreateStack();
    Ans = CreateStack();
    string token;
    string result = "";

    cout << "Input:\n";
    cin >> token;
    while (token != "."){

        if (token == "."){
            break;
        }
        
        //ถ้า token 
        else if(token == "+" || token ==  "-" || token == "*" || token == "/"){
            //ถ้า stack ว่าง  
            if (IsEmpty(S)){
                Push(S,token);
            }

        //* /
            else if (token == "*" || token == "/"){
                string opened = Top(S);
                //if token is higher
                if(opened == "+" || opened == "-" || opened == "("){
                    Push(S,token);
                }
                //if token is equal
                if(opened == "*" || opened == "/"){
                    result += opened + " ";
                    Pop(S);
                }
            }

        //+ -
            else if (token == "+" || token == "-"){
                string opened = Top(S);
                //token lower/equal
                if (opened == "*" || opened == "/" || opened == "+" || opened == "-"){
                    result += opened + " ";
                    Pop(S);
                    Push(S,token);
                }
                //token higher [ '(' found in stack]
                else if (opened == "("){
                    Push(S,token);
                }
            }
    //()
        }
        else if (token == "("){
            Push(S,token);
        }
        else if (token == ")"){
            string opened = Top(S);
            while (opened != "("){
                result += opened + " ";
                Pop(S);
                opened = Top(S);
            }
            Pop(S);
        }

        else{
            result += token + " ";
        }
        cin >> token;       
    }

    while (!IsEmpty(S)){
        if (Top(S) != "(" || Top(S) != ")"){
            result += Top(S) + " ";
            Pop(S);
        }
        
    }

    cout << "Ans = " << result;
}