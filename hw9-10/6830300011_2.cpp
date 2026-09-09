//avl tree 6830300011
#include <iostream>
using namespace std;

struct node{
    int value;
    int height;
    node *left;
    node *right;
};

int fheight(node *P){
    if (P == NULL){
        return -1;
    }
    else{
        return P->height;
    }
}

int maxVal(int a, int b){
    return (a > b) ? a : b;
}

node *srright(node *k2){
    node *k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = maxVal(fheight(k2->left), fheight(k2->right)) + 1;
    k1->height = maxVal(fheight(k1->left), k2->height) + 1;
    return k1;
}

node *srleft(node *k1){
    node *k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = maxVal(fheight(k1->left), fheight(k1->right)) + 1;
    k2->height = maxVal(k1->height, fheight(k2->right)) + 1;
    return k2;
}

node *dLR(node *k3){
    k3->left = srleft(k3->left);
    return srright(k3);
}

node *dRL(node *k1){
    k1->right = srright(k1->right);
    return srleft(k1);
}

node *insert(int x, node *T){
    if (T == NULL){
        T = new node;
        T->value = x;
        T->left = T->right = NULL;
        T->height = 0;
    }
    else if ( x < T->value){
        T->left = insert(x, T->left);
        if (fheight(T->left) - fheight(T->right) == 2) {
            if (x < T->left->value)
                T = srright(T);
            else
                T = dLR(T);
        }
    }
    else if (x > T->value) {
        T->right = insert(x, T->right);
        if (fheight(T->right) - fheight(T->left) == 2) {
            if (x > T->right->value)
                T = srleft(T);
            else
                T = dRL(T);
        }
    }

    T->height = maxVal(fheight(T->left), fheight(T->right)) + 1;
    return T;
}

void inorder(node *T){
    if (T!=NULL){
        inorder(T->left);
        cout << T->value << " ";
        inorder (T->right);
    }
}

int main(){
    node *tree = NULL;
    int choice, x;

    while (true) {
        cout << "\n===========MENU==========\n";
        cout << "1) Insert\n";
        cout << "2) Print Inoreder\n";
        cout << "3) Exit\n";
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
                return 0;
        }
    }
    return 0;

}