//decode
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct record{
    char data;
    struct record *next;
};

struct record *insert(struct record *head, char c){
    struct record *p, *node;
    if (head == NULL){
        head = new struct record;
        head->data = c;
        head->next = NULL;
    }
    else{
        node = new struct record;
        node->data = c;
        p = head;
        while (p!=NULL){
            if (p->next == NULL){ //ตัวท้าย
                //เอามาต่อ
                p->next = node;
                node->next = NULL;
                break;
            }else{
                p = p->next;
            }
        }
    }
    return head;
}

void freeList(struct record *head){
    struct record *p,*tmp;
    if (head == NULL){
        return;
    }
    else{
        p = head;
        while (p!=NULL){
            tmp = p;
            p = p->next;
            delete(tmp);
        }
    }
}

void decode(struct record *head){
    if (head == NULL){
        cout << "Cannot Decode: No Input Provided";
        return;
    }

    //นับจำนวนใน linked list
    int count = 0;
    struct record *p = head;
    while (p!=NULL){
        count++;
        p = p->next;
    }

    char arrodd[(count+1)/2];
    char arreven[(count)/2];

    p = head;
    
    //assign
    for (int i = 0; i < (count+1)/2; i++){
        arrodd[i] = p->data;
        p = p->next;
    }
    
    for (int i = 0; i < count/2;i++){
        arreven[i] = p->data;
        p = p->next;
    }

    //print
    for (int i = 0; i < count; i++){
        if (i % 2 == 0){
            cout << arrodd[i/2];
        }else{
            cout << arreven[i/2];
        }
    }
}  

int menu(){
    int choose;
    cout << "==MENU==\n";
    cout << "1) Insert Code\n" ;
    cout << "2) Decode\n";
    cout << "3)Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

int main(){
    struct record *head = NULL;
    int choose;
    do{
        choose = menu();
        switch (choose){
            case 1:{
                string password;
                cout << "Input Password : ";
                cin >> password;

                freeList(head);
                head = NULL;

                for (int i = 0; i < password.length(); i++){
                    head = insert(head,password[i]);
                }
                getchar();
                break;
            }

            case 2:
            decode(head);
            break;

            case 3:break;

        }
    }while(choose!=3);
}