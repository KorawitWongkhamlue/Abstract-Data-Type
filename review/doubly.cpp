//doubly linked list
#include <stdio.h>
#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *prev;
    struct record *next;
};

//insert delete print
struct record *insert(struct record *head, int x){
    struct record *p, *node;
    if (head == NULL){
        head = new struct record;
        head->value = x;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        node = new struct record;
        node->value = x;
        if (x < head->value){
            node->next = head;
            head->prev = node;
            head = node;
            head->prev = NULL;
        }
        else{
            p = head;
            while (p!= NULL){
                if (p->next == NULL){
                    p->next = node;
                    node->prev = p;
                    node->next = NULL;
                    break;
                }
                else if(x < p->next->value){
                    node->next = p->next;
                    p->next->prev = node;
                    p->next = node;
                    node->prev = p;
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

struct record *DeleteNode(struct record *head,int x){
    struct record *p,*tmp;
    if (head == NULL){
        cout << "Empty List!!" << endl;
    }
    else{
        if (x == head->value){
            tmp = head;
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            }
            delete(tmp);
        }
        else{
            p = head;
            while (p!=NULL){
                if(x == p->next->value){
                    tmp = p->next;
                    if (tmp->next != NULL){
                        p->next = tmp->next; //in between
                        tmp->next->prev = p;
                    }else{
                        p->next = NULL;
                    }
                    delete(tmp);
                    break;
                }
                else{
                    p = p->next;
                }
            }
        }

    }
    cout << "Delete Successfully";
    return head;
}

void print(struct record *head){
    struct record *p;
    if (head == NULL){
        return;
    }
    else{
        p = head;
        while (p!=NULL){
            cout << p->value << " ";
            p = p->next;
        }
    }
}

int menu(){
    int choose;
    cout << "=====MENU=====\n";
    cout << "1). Insert\n";
    cout << "2). Delete\n";
    cout << "3). Print\n";
    cout << "4). Exit\n";
    cout << "Please Choose > ";
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
                int x;
                cout << "Insert : ";
                cin >> x;
                head = insert(head,x);
                cout << "Insert Successfully!";
                getchar();
                getchar();
                break;
            }
            case 2:{
            int x;
                cout << "Select Number to Delete : ";
                cin >> x;
                head = DeleteNode(head,x);
                getchar();
                getchar();
                break;
            }
            case 3:
                print(head);
                getchar();
                getchar();
                break;
            case 4:break;
        }

    }while(choose!=4);
}

