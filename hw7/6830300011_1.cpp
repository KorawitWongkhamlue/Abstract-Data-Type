//treesss มาๆๆๆ
//6830300011
#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *tree,int x){
    if (tree == NULL){
        tree = new struct node;
        tree->value = x;
        tree->left = tree->right = NULL;
    }else{
        if (x < tree->value){
            tree->left = insert(tree->left,x);
        }else if (x > tree->value){
            tree->right = insert(tree->right,x);
        }
    }
    return tree;
}

//Pre Order : rLR
void printPre(struct node *tree){
    if (tree == NULL){
        return;
    }else{
        cout << tree->value << " ";
        printPre(tree->left);
        printPre(tree->right);
    }
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

//Post Order : LRr
void printPost(struct node *tree){
    if (tree == NULL){
        return;
    }else{
        printPost(tree->left);
        printPost(tree->right);
        cout << tree->value << " ";
    }
}

//max to min
void printMaxtomin(struct node *tree){
    if (tree == NULL){
        return;
    }else{
        printMaxtomin(tree->right);
        cout << tree->value << " ";
        printMaxtomin(tree->left);
    }
}



int menu(){
    int choose;
    cout << "========MENU======\n";
    cout << "1) Insert\n";
    cout << "2) Print Inorder, Preorder, Postorder, Max to min\n";
    cout << "3) Exit\n";
    cout << "   Please choose > ";
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
                tree = insert(tree,x);
                cout << "Success!";
                getchar();
                getchar();
                break;
            }
            case 2:
                cout << "Preorder : ";
                printPre(tree);
                cout << "\n";
                cout << "Inorder : ";
                printIn(tree);
                cout << "\n";
                cout << "Postorder : ";
                printPost(tree);
                cout << "\n";
                cout << "Max to min : ";
                printMaxtomin(tree);
                cout << "\n";
                break;
            case 3:
                break;
        }

    }while(choose!=3);
}