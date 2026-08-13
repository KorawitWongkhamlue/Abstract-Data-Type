//circular linked list
#include <iostream>
#include <stdio.h>
using namespace std;

struct record{
    int value;
    struct record *next;
};

struct record *insert(struct record *head, int x){
    struct record *p, *node;
    if (head == NULL){
        head = new struct record;
        head->value = x;
        head->next = head;
    }
    else{
        node = new struct record;
        node->value = x;
        p = head;

        if (x < head->value){
            p = head;
            while (p->next != head){
                p = p->next;
            }
            tail = p;
            node->next = head;
            tail->next = node;
            head = node;
        }
        else if (p->next == head){
            head->next = node;
            node->next = head;
        }
        else{
            p = head->next;
            while (p != head){
                if (p->next == head){
                    node->next = head;
                    p->next = node;
                    break;
                }
                else if(x < p->next->value){
                    node->next = p->next;
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

struct record *DeleteNode(struct record *head, int x){
    struct record *p, *tmp;
    if (head == NULL){
        cout << "Empty List!!!" << endl ;
    }
    else{
        if (x == head->value){
            tmp = head;
            if (head->next != head){
                head = head->next;
            }
            delete(tmp);
        }
        else{
            p = head;
            if (x == p->next->value){
                tmp = p->next;
                p->next = tmp->next;
                delete(tmp);
            }
            else{
                p = head->next;
                while (p != head){
                    if (x == p->next->value){
                        tmp = p->next;
                        p->next = tmp->next;
                        delete(tmp);
                        break;
                    }
                }
            }
            
        }
    }

    return head;
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
            case 2: break;/*:{
            int x;
                cout << "Select Number to Delete : ";
                cin >> x;
                head = DeleteNode(head,x);
                getchar();
                getchar();
                break;
            }*/
            case 3:break;
                /*print(head);
                getchar();
                getchar();
                break;*/
            case 4: break;
        }
    }while(choose!=4);
}
