//6830300011
#include <iostream>
using namespace std;

struct record{
    int value; //data
    struct record *next;
};

//functions ต่างๆ เช่น insert และ print
struct record *insert(struct record *head, int data){
    struct record *node, *p;

    if (head == NULL){ //ถ้า head ว่าง, สร้างใหม่
        head = new struct record; 
        head->value = data;
        head->next = NULL;
    }
    else{
        node = new struct record;
        node->value = data;
        if (data < head->value){
            node->next = head; //อยุ่ข้างหน้า head ถ้า data ค่าน้อยกว่า
            head = node;
        }
        else{ //กรณีค่ามากกว่า head ต้องแทรกกลาง : ต้องค่อยๆเลื่อนจนกว่าจะหาที่ลงได้
            p = head;
            while (p != NULL){
                if (p->next == NULL){ //ถ้าถึงตัวสุดท้าย
                    p->next = node; //เชื่อมตัวสุดท้ายเข้ากับ node
                    node->next = NULL;
                    break;
                }
                else if (data < p->next->value){
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

//print
void print(struct record *head){
    cout <<"Output : ";
    struct record *tmp;
    tmp = head;

    while (tmp != NULL){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }

    cout <<"\n";
}

//ทำหน้า menu แยกออกมาจาก main เลย (ทำความเข้าใจing)
int menu(){
    
    int choose;
    cout << "=============Menu=============\n";
    cout << " 1) Insert list\n";
    cout << " 2) Print list\n";
    cout << " 3) Exit\n";
    cout << " Please choose > ";
    cin >> choose;

    return choose;

}

int main(){
    struct record *head = NULL;
    int choice, data;

    
    //กำหนดคำสั่งว่าถ้าเลือกเลขอะไรจะไปไหน
    do {
        choice = menu();
        switch(choice) {
            case 1: cout << "Enter :  ";
                    cin >> data;
                    head = insert(head,data);
                    cout << "Success!\n" ;
                    getchar();
                    //cin.ignore(1000, '\n');
                    getchar();
                    break;
            case 2: print(head);
                    getchar();
                    //cin.ignore(1000, '\n');
                    getchar();
                    break;
            case 3: break;
        }
    } while (choice != 3);
}

