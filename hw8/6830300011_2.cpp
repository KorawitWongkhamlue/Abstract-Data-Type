//AVL
//6830300011
#include <iostream>
using namespace std;
 
struct node{
    int value;
    int height;
    struct node *left;
    struct node *right;
};
 
int height(struct node *tree){
    if (tree == NULL)
        return 0;
    return tree->height;
}
 
int maxH(int a, int b){
    return (a > b) ? a : b;
}
 
int getBalance(struct node *tree){
    if (tree == NULL)
        return 0;
    return height(tree->left) - height(tree->right);
}
 
//rotate right (แก้เคส LL)
struct node *rotateRight(struct node *y){
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = maxH(height(y->left), height(y->right)) + 1;
    x->height = maxH(height(x->left), height(x->right)) + 1;
 
    return x;
}
 
//rotate left (แก้เคส RR)
struct node *rotateLeft(struct node *x){
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = maxH(height(x->left), height(x->right)) + 1;
    y->height = maxH(height(y->left), height(y->right)) + 1;
 
    return y;
}
 
struct node *insert(struct node *tree, int x){
    if (tree == NULL){
        tree = new struct node;
        tree->value = x;
        tree->left = tree->right = NULL;
        tree->height = 1;
        return tree;
    }
 
    if (x < tree->value){
        tree->left = insert(tree->left, x);
    }else if (x > tree->value){
        tree->right = insert(tree->right, x);
    }else{
        return tree; //ไม่รับค่าซ้ำ
    }
 
    tree->height = 1 + maxH(height(tree->left), height(tree->right));
 
    int balance = getBalance(tree);
 
    //LL
    if (balance > 1 && x < tree->left->value){
        return rotateRight(tree);
    }
    //RR
    if (balance < -1 && x > tree->right->value){
        return rotateLeft(tree);
    }
    //LR
    if (balance > 1 && x > tree->left->value){
        tree->left = rotateLeft(tree->left);
        return rotateRight(tree);
    }
    //RL
    if (balance < -1 && x < tree->right->value){
        tree->right = rotateRight(tree->right);
        return rotateLeft(tree);
    }
 
    return tree;
}
 
//In Order : LrR
void printIn(struct node *tree){
    if (tree == NULL){
        return;
    }else{
        printIn(tree->left);
        cout << tree->value << " ";
        printIn(tree->right);
    }
}
 
int menu(){
    int choose;
    cout << "==========MENU==========\n";
    cout << "1) Insert\n";
    cout << "2) Print Inoreder\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
 
    return choose;
}
 
int main(){
    int choose;
    struct node *tree = NULL;
    do{
        choose = menu();
        switch (choose){
            case 1:
            {
                int x;
                cout << "Enter : ";
                cin >> x;
                tree = insert(tree, x);
                cout << "Success!\n";
                break;
            }
            case 2:
                cout << "Inorder : ";
                printIn(tree);
                cout << "\n";
                break;
            case 3:
                break;
        }
    }while(choose != 3);
 
    return 0;
}