//stack
#include <iostream>
#include <stdio.h>
using namespace std;

struct record{
    char data;
    struct record *next;
};
typedef struct record *Stack;

Stack CreateStack();
void Push(Stack s,char c);
void Pop(Stack s);
char Top(Stack s);
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

void Push(Stack s, char c){
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

char Top(Stack s){
    return s->next->data;
}

int main(){
    Stack stack = CreateStack();
    char c;
    bool error = false;

    cin.get(c);
    while (c != '.' == !error){
        if (c == '(' || c == '{'){
            Push(stack, c);
        }
        else if (IsEmpty(stack) && (c == ')' || c == '}')){
            error = true;
            cout << "Error: Missing opening";
        }
        else{
            char opened = Top(stack);
            Pop(stack);
            if (c == ')' && opened != '('){
                error = true;
                cout << "Error: Unmatched Closing Bracket" << endl;
            }
            else if ( c == '}' && opened != '{'){
                error = true;
                cout << "Error: Unmatched Closing Bracket" << endl;
            }
           /*else if(c == ')' && opened == '(' || c == '}' && opened == '{'){
                Pop(stack);
            }*/
        }
        cin.get(c);
    }


    //check remaining
    if (!IsEmpty(stack)){
        if(Top(stack) == '('){
            cout << "Error: Expected ')'" << endl;
        }else{
            cout << "Error: Expected '}" << endl;
        }
    }
}
