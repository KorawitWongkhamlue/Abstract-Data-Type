//stack
#include <stdio.h>
#include <iostream>
using namespace std;

struct rec{
    int value;
    struct rec *next;
};

typedef struct rec *Stack;

Stack CreateStack();
void Push(Stack s, int x);
void Pop(Stack s);
int Top(Stack s);
int IsEmpty(Stack s);

Stack CreateStack(){
    Stack s = new struct rec;
    if (s == NULL){
        cout << "Out of Memory!";
    }else{
        s->next = NULL;
    }
    return s;
}

void Push(Stack s, int x){
    if (s == NULL){
        cout << "Out of Memory!!";
        return;
    }
    Stack node = new struct rec;
    node->value = x;
    node->next = s->next;
    s->next = node;
}

int IsEmpty(Stack S){
    return S->next == NULL ;
}

void Pop(Stack s){
    Stack tmp;
    if (IsEmpty(s)){
        cout << "FAHHH EMPTY STACK" << endl;
        return;
    }
    tmp = s->next;
    s->next = tmp->next;
    delete(tmp);
}

int Top(Stack s){
    if (IsEmpty(s)){
        cout << "FAHHH EMPTY STACK" << endl;
        return 0;
    }
    return s->next->value;
}

int menu(){
    int choose;
    cout << "MENUUUUUUUUUU\n";
    cout << "1) Push\n";
    cout << "2) Pop\n";
    cout << "3) Top\n";
    cout << "4) Exit\n";
    cout << "Choose > ";
    cin >> choose;
    return choose;
}

int main(){
    int choose;
    Stack stack = CreateStack();
    do{
        choose = menu();
        switch (choose){
            case 1:{
                int x;
                cout << "Insert number to push: ";
                cin >> x;
                Push(stack,x);
                cout << "Pushed!";
                cout << " ";
                getchar();
                getchar();
                break;
            }
            case 2:
            cout << "Popping...\n";
            Pop(stack);
            cout << "Popped!";
            cout << " ";
            getchar();
            getchar();
            break;
            case 3:
            if (Top(stack) != 0){
                cout << "Top : " << Top(stack);
                cout << " ";
            }
            getchar();
            getchar();
            break;
            case 4: break;
        }

    }while(choose!= 4);
}