//binary search tree 6830300011
#include <iostream>
using namespace std;

struct node{
    int value;
    node *left;
    node *right;
};

node *newNode(int x) {
    node *T = new node;
    T->value = x;
    T->left = T->right = NULL;
    return T;
}

node *insert(int x, node *T){
    if (T == NULL){
        T = newNode(x);
    }
    else if (x < T->value){
        T->left = insert(x, T->left);
    }else if (x > T->value){
        T->right = insert(x, T->right);
    }
    return T;
}

void inorder(node *T){
    if (T != NULL) {
        inorder(T->left);
        cout << T->value << " ";
        inorder(T->right);
    }
}

node *findMin(node *T){
    if ( T == NULL ) return NULL;
    while (T->left != NULL){
        T = T->left;
    }
    return T;
}

node *findMax(node *T){
    if ( T == NULL ) return NULL;
    while (T->right != NULL){
        T = T->right;
    }
    return T;
}

bool findData(int x, node *T){
    if ( T == NULL ){
        return false;
    }
    if (x == T->value){
        return true;
    }
    if (x < T->value){
        return findData(x,T->left);
    }
    return findData(x,T->right);
}

node *deleteNode(int x, node *T){
    node *tmp;
    if ( T == NULL){
        cout << "Data not found" << endl;
        return T;
    }

    if (x < T->value){
        T->left = deleteNode(x, T->left);
    }
    else if ( x > T->value){
        T ->right = deleteNode(x, T->right);
    }
    else if (T->left && T->right){
        tmp = findMin(T->right);
        T->value = tmp->value;
        T->right = deleteNode(T->value, T->right);
    }
    else{
        tmp = T;
        if (T->left == NULL){
            T = T->right;
        }
        else if (T->right == NULL){
            T = T->left;
        }
        delete tmp;
    }
    return T;
}

int main(){
    node *tree = NULL;
    int choice, x;
    node *p;

    while (true) {
        cout << "\n========MENU======\n";
        cout << "1) Insert\n";
        cout << "2) Print Inorder\n";
        cout << "3) Delete\n";
        cout << "4) Find min and max\n";
        cout << "5) Find data\n";
        cout << "6) Exit\n";
        cout << "Please choose > ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter : ";
                cin >> x;
                tree = insert(x, tree);
                cout << "Success!\n";
                break;

            case 2:
                cout << "Inorder : ";
                inorder(tree);
                cout << "\n";
                break;

            case 3:
                cout << "Delete : ";
                cin >> x;
                tree = deleteNode(x, tree);
                cout << "Success!\n";
                break;

            case 4:
                if (tree == NULL) {
                    cout << "Tree ว่าง\n";
                } else {
                    p = findMax(tree);
                    cout << "Max = " << p->value << "\n";
                    p = findMin(tree);
                    cout << "Min = " << p->value << "\n";
                }
                break;

            case 5:
                cout << "Enter number to find : ";
                cin >> x;
                if (findData(x, tree))
                    cout << "Found!\n";
                else
                    cout << "Notfound!\n";
                break;

            case 6:
                return 0;
        }
    }
    return 0;
}