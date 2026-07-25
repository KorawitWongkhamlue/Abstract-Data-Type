//6830300011
#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};


void print(struct record *head){
    struct record *tmp;
    tmp = head;

    while (tmp != NULL){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }

    cout <<"\n";
}

void printReverse(struct record *head){
    if (head == NULL){
        return;
    }
    printReverse(head->next);
    cout << head->value << " ";
}


//1.
struct record *insert(struct record *head,int data){

    struct record *node, *p;

    //no head, before head, in between, last node
    if (head == NULL){
        head = new struct record;
        head->value = data;
        head->next = NULL;
    }
    else{

        node = new struct record;
        node->value = data;

        //before head
        if (data < head->value){
            node->next = head;
            head = node;
            
        ///in between & last node
        }else{
            p = head;
            while (p != NULL){
                //in between
                if (p->next == NULL){
                    p->next = node;
                    node->next = NULL;
                    break;
                }
                if (data < p->next->value){
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

//2.
struct record *deleteNode(struct record *head,int data){
    struct record *node,*tmpfree, *p;

    //no data, delete head, in between, last node
    node = head;
    if (head == NULL){
        cout << "Empty List!";
    }
    else {
        node = head;
        //delete head
        if (data == head->value){
            tmpfree = head;
            head = head->next;

            free(tmpfree);
        }
        else{
            p = head;
            while ( p != NULL){
                //in between
                if (p->next->value == data){
                    tmpfree = p->next;
                    p->next = tmpfree->next;
                    free(tmpfree);
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

int count(struct record *head){
    struct record *p;
    int count = 0;

    p = head;
    while (p != NULL){
        count++;
        p = p->next;
    }
    return count;
}

//5.
void printHalf(struct record *head){
    struct record *p = head;
    int n = count(head);
    int half = n / 2;
    int i;

    cout << "First = ";
    for (i = 0; i < half; i++){
        cout << p->value << " ";
        p = p->next;
    }

    cout << endl;

    cout << "Second = ";
    while (p != NULL){
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl ;
}

//6.
void find(struct record *head, int data){
    struct record *p = head;
    
    if (head == NULL){
        cout << "Not Found, Empty List!" ;
    }
    else{
        while (p != NULL){
            if (data == p->value){
                cout << "Found" ;
                return;
            }else{
                p = p->next;
            }
        }
        cout << "Not Found" << endl;
    }
}

int menu(){
    
    int choose;
    cout << "=============Menu=============\n";
    cout << " 1) Insert list\n";
    cout << " 2) Delete\n";
    cout << " 3) Print min to max, max to min\n";
    cout << " 4) Count\n";
    cout << " 5) Print first half and second half\n";
    cout << " 6) Find\n";
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
        case 1: cout << "Enter :  ";
                cin >> data;
                head = insert(head,data);
                cout <<"List = ";
                print(head);                    getchar();
                //cin.ignore(1000, '\n');
                getchar();
                break;
        case 2: cout << "Delete : ";
                cin >> data;
                head = deleteNode(head,data);
                cout <<"List = ";
                print(head);
                getchar();
                getchar();
                break;
        case 3: cout << ": ";
                print(head);
                cout << ": ";
                printReverse(head);
                cout << endl;
                getchar();
                getchar();
                break;
        case 4: cout << "Count = " << count(head);
                getchar();
                getchar();
                break;
        case 5: printHalf(head);
                getchar();
                getchar();
                break;
        case 6: cout << "Find : ";
                cin >> data;
                find(head,data);
                getchar();
                getchar();
                break;
        case 0: break;
        }
    }while (choice != 0);
}
