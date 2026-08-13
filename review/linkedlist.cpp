//linked list
#include <iostream>
#include <stdio.h>
using namespace std;

struct record{
    int value;
    struct record *next;
};


//Linked List: head, lower, in between, last
struct record *insert(struct record *head, int x);
struct record *Delete(struct record *head, int x);
void print(struct record *head);
int count(struct record *head);

struct record *insert(struct record *head, int x){
    struct record *p, *node;
    if (head == NULL){
        head = new struct record;
        head->value = x;
        head->next = NULL;
    }else{
        node = new struct record;
        node->value = x;
        //less than
        if (x < head->value){
            node->next = head;
            head = node;
        } //more than
        else{
            p = head;
            while (p != NULL){
                //last
                if (p->next == NULL){
                    p->next = node;
                    node->next = NULL;
                    break;
                }else if (x < p->next->value){
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

struct record *Delete(struct record *head, int x){
    struct record *p,*tmp;
    //head
    if (head == NULL){
        cout << "Empty list!" << endl;
    }else{
        if (x == head->value){
            tmp = head;
            head = head->next;
            delete(tmp);
        }
        else{
            //in a normal list , last node
            p = head;
            while (p->next != NULL){
                if (p->next->value == x){
                    tmp = p->next;
                    p->next = p->next->next;
                    delete(tmp);
                }
                else{
                    p = p->next;
                }
            }
        }
    }

    return head;
}


int menu(){
    int choose;
    cout << "Choose Ai SUDD!!!\n";
    cout << "1) Insert\n";
    cout << "2) Delete\n";
    cout << "3) Print\n";
    cout << "4) Count\n";
    cout << "5) Exit\n";
    cout << "Please Choose > ";
    cin >> choose;
    return choose;
}

void print(struct record *head){
    struct record *p;
    p = head;
    while (p != NULL){
        cout << p->value << " ";
        p = p->next;
    }
}

int count(struct record *head){
    int count = 0;
    struct record *p;
    p = head;
    while (p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}

int main(){
    int choose;
    struct record *head = NULL;

    do{
        choose = menu(); 
        switch (choose){
            case 1:{
                    int x;
                    cout << "Insert value : " ;
                    cin >> x;
                    head = insert(head,x);
                    cout << "Insert success!\n";
                    getchar();
                    getchar();
                    break;
            } 
            case 2:{
                    int x;
                    cout << "Select value to delete: " ;
                    cin >> x;
                    head = Delete(head,x);
                    cout << "Delete successfully!\n";
                    getchar();
                    getchar();
                    break;
            } 
            case 3: print(head);
                    getchar();
                    getchar();
                    break;
            case 4: cout << "Count : ";
                    cout << count(head) << endl;
                    getchar();
                    getchar();
            case 5: break;
        }

    }while(choose != 5);
}