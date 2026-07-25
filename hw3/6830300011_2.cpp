#include <iostream>
using namespace std;

struct record{
    int digit;
    struct record *next;
};

//สร้าง list  เก็บแบบ lsd ทำให้เรียงจากท้ายมากนหน้า
struct record *buildList(string numStr){
    struct record *head = NULL;
    struct record *tail = NULL;
    struct record *node;
    
    //ไล่จากขวาไปซ้ายยย
    for (int i = numStr.length() - 1; i >= 0; i--){
        node = new struct record;
        node->digit = numStr[i] - '0';
        node->next = NULL;

        if (head == NULL){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printReverse(struct record *head){
    if (head == NULL){
        return;
    }else{
        printReverse(head->next);
        cout << head->digit;
    }
}

struct record *add(struct record *p1, struct record *p2){
    struct record *head = NULL, *tail = NULL, *node;
    int carry = 0;

    while (p1 != NULL || p2 != NULL || carry != 0){
        int digit1 = (p1 != NULL) ? p1->digit : 0;
        int digit2 = (p2 != NULL) ? p2->digit : 0;

        int sum = digit1 + digit2 + carry;
        int newDigit = sum % 10;
        carry = sum / 10;

        node = new struct record;
        node->digit = newDigit;
        node->next = NULL;

        if (head == NULL){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            tail = node;
        }

        if (p1 != NULL) p1 = p1->next;
        if (p2 != NULL) p2 = p2->next;
    }

    return head;
}

int menu(){
    
    int choose;
    cout << "========================\n";
    cout << "           MENU  \n";
    cout << "========================\n";
    cout << " 1) Input p1\n";
    cout << " 2) Input p2\n";
    cout << " 3) Add\n";
    cout << " 4) Exit\n";
    cout << " Please choose > ";
    cin >> choose;

    return choose;

}



int main(){
    struct record *p1 = NULL, *p2 = NULL, *result = NULL;
    int choice;
    string input;

    do{
        choice = menu();
        switch (choice){
            case 1: 
                cout << "Input : ";
                cin >> input;
                p1 = buildList(input);
                cout << "P1 = ";
                printReverse(p1);
                cout << endl;
                break;
            case 2:
                cout << "Input : ";
                cin >> input;
                p2 = buildList(input);
                cout << "P2 = ";
                printReverse(p2);
                cout << endl;
                break;
            case 3:
                result = add(p1,p2);
                cout << "Output = ";
                printReverse(result);
                cout << endl;
                break;  
            case 4:
                break;
        }
    }while (choice != 4);

    return 0;
}