//6830300011
#include <iostream>
using namespace std;

struct record{
    char c;
    struct record *next;
};

//1.
struct record *insert(struct record *head,char value){
    struct record *node = new struct record;
    node->c = value;
    node->next = NULL;

    //new freshy node
    if (head == NULL){
        return node;
    }

    //ต่อ node
    struct record *tmp = head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = node;
    return head;
}

void freeList(struct record *head) {
    while (head != NULL) {
        struct record *temp = head;
        head = head->next;
        delete temp;
    }
}


//2.
void decode(struct record *head){
    if (head == NULL){
        cout << "No secret code entered!" << endl;
        return;
    }

    int len = 0;
    struct record *cur = head;
    while (cur != NULL){
        len++;
        cur = cur->next;
    }

    char *arr = new char[len];
    cur = head;
    for (int i = 0; i < len ; i++){
        arr[i] = cur->c;
        cur = cur->next;
    }

    int oddIdx = 0;
    int evenIdx = (len + 1)/2;

    string decodedStr = "";
    for (int i = 0; i < len; i++){
        if ( i%2 ==0){
            decodedStr += arr[oddIdx++];
        }else {
            decodedStr += arr[evenIdx++];
        }
    }

    cout << "Answer : " << decodedStr << endl;
    delete[] arr;
}

int menu(){
    int choose;
    cout << "==================" << endl;
    cout << "       MENU        " << endl;
    cout << "==================" << endl;
    cout << "1) Input secret code" << endl;
    cout << "2) Decode" << endl;
    cout << "3) Exit"<< endl;
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
        case 1 :{
                string password;
                cout << "Code : ";
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
                getchar();
                getchar();
                break;
        case 3:
                break;
                
    }
    }while (choose != 3);
    return 0;
}