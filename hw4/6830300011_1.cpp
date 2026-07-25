//6830300011
//doubly linked list
#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
    struct record *prev;
};

//insert
struct record *insert(struct record *head, int data){
    struct record *node,*p;
    //no head, first node, in between, last node
    if (head==NULL){
        head = new struct record;
        head->value = data;
        head->next = NULL;
        head->prev = NULL;
    }
    else{

        p = head; //อย่าลืม!!
        node = new struct record;
        node->value = data;

        //first node
        if (data < head->value){
            node->next = head;
            head->prev = node;
            head = node;
            head->prev = NULL;
        }
        else{
            while (p != NULL){
                //last node
                if(p->next == NULL){
                    node->prev = p;
                    p->next = node;
                    node->next = NULL;
                    break; //อย่าลืม!!!!
                }
                //between
                else if(data < p->next->value){
                    node->next = p->next;
                    p->next->prev = node;
                    node->prev = p;
                    p->next = node;
                    break; //อย่าลืม!!!!
                }
                else{
                    p = p->next;
                }
            }
        }
    }

    return head;
}

//delete
struct record *deleteNode(struct record *head, int data){
    struct record *p,*tmp;

    //no data, first node, in between, last node
    if (head == NULL){
        cout << "No List To Delete!";
    }
    else{
        p = head;
        //first node
        if(data == head->value){
            tmp = head;

            //ถ้ามีมากกว่า 1 list ให้ขยีบ head ไปตัวต่อไป
            if (head->next != NULL){
                head = head->next;
                head->prev = NULL;
            }else{
                head = NULL; //กรณี head ตัวเดียว
            }
            free(tmp);
        }
        //between
        else{
            while (p != NULL){
                //last node
                if (p->next == NULL){
                    //ถ้าตัวสุดท้าย data ตรง
                    if (data == p->value){
                        tmp = p;
                        p->prev->next = NULL;
                        p->prev = NULL;
                        free(tmp);
                        break;
                    }else{ //ถ้าตัวสุดท้ายละยังไม่ตรง
                        cout << "Can't delete, No number!!\n";
                        break;
                    }
                }
                //between
                else if(data == p->value){
                    tmp = p;
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    free(tmp);
                    break;
                }
                //no matching number
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
    cout << endl;
}

//3.head to tail, tail to head
void printReverse(struct record *head){
    struct record *p;
    //reach the last node
    p = head;
    while (p != NULL){
        if (p->next == NULL){
            break;
        }else{
            p = p->next;
        }
    }

    //loop from tail -> head
    while (p != NULL){
        cout << p->value << " ";
        p = p->prev;
    }
    cout << endl;

}

int menu(){

    int choose;
    cout << "======================\n";
    cout << "         MENU\n";
    cout << "======================\n";

    cout << "1) Insert\n";
    cout << "2) Delete\n";
    cout << "3) Print head to tail, tail to head\n";
    cout << "4) Exit\n";
    cout << "Please choose> ";
    cin >> choose;

    return choose;
}

int main(){

    struct record *head = NULL;
    int data;
    int choose;
    do{
        choose = menu();
        switch (choose){
            case 1: cout << "Insert : ";
                    cin >> data;
                    head = insert(head,data);
                    cout << "List = ";
                    print(head);
                    getchar();
                    getchar();
                    break;
            case 2: cout << "Delete : ";
                    cin >> data;
                    head = deleteNode(head,data);
                    cout << "List = ";
                    print(head);
                    getchar();
                    getchar();
                    break;
            case 3: print(head);
                    printReverse(head);
                    break;
            case 4: break;
        }
    }while(choose!=4);
}