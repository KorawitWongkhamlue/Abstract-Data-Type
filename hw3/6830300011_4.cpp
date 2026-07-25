#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
    struct record *prev;
};

//insert
struct record *insert(struct record *head, int data){
    struct record *p, *tmp, *node;
    //no head, before head, in between, last node;

    //1.no head:
    if (head == NULL){
        head = new struct record;
        head->value = data;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        
        node = new struct record;
        node->value = data;

        //before head
        if (data < head->value){
            node->prev = NULL;
            node->next = head;
            head->prev = node;
            head = node;
        }
        else{
            //in between
            p = head;
            while (p != NULL){
                if (p->next == NULL){ //last node
                    p->next = node;
                    node->prev = p;
                    node->next = NULL;
                    break;
                }
                else if (data < p->next->value){
                    node->next = p->next;
                    node->prev = p;
                    p->next->prev = node;
                    p->next = node;
                    break;
                }
                else{
                    p = p->next;
                }
            }
        }

    }
    return head;
}

void print(struct record *head){
    struct record *p;
    p = head;
    while (p != NULL){
        cout << p->value << " ";
        p = p->next;
    }

    cout << " ";
}


int menu(){
    
    int choose;
    cout << "========================\n";
    cout << "           MENU  \n";
    cout << "========================\n";
    cout << " 1) Insert\n";
    cout << " 2) Exit\n";
    cout << " Please choose > ";
    cin >> choose;

    return choose;

}



int main(){
    struct record *head = NULL;
    int choice, data;
    do{
        choice = menu();
        switch (choice){
            case 1: cout << "Insert :  ";
                    cin >> data;
                    head = insert(head,data);
                    cout <<"List = ";
                    print(head);                    
                    getchar();
                    //cin.ignore(1000, '\n');
                    getchar();
                    break;
            case 2: break;
        }
    }while (choice != 2);
}