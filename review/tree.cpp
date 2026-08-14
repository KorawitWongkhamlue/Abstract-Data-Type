//tree
#include <stdio.h>
#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *left;
    struct record *right;
};

struct record *insert(struct record *tree, int x){
    if (tree == NULL){
        tree = new struct record;
        tree->value = x;
        tree->left = NULL;
        tree->right = NULL;
    }else{
        if (x < tree->value){
            tree->left = insert(tree->left,x);
        }else if (x > tree->value){
            tree->right = insert(tree->right,x);
        }
    }
    return tree;
}

void PrintPre(struct record *tree){ //rLR
    if (tree == NULL){
        return;
    }
    else{
        cout << tree->value << " ";
        PrintPre(tree->left);
        PrintPre(tree->right);
    }
}

void PrintIn(struct record *tree){ //LrR
    if (tree == NULL){
        return;
    }
    else{
        PrintIn(tree->left);
        cout << tree->value << " ";
        PrintIn(tree->right);
    }
}

void PrintPost(struct record *tree){ //LRr
    if (tree == NULL){
        return;
    }
    else{
        PrintPost(tree->left);
        PrintPost(tree->right);
        cout << tree->value << " ";
    }
}

void PrintMaxMin(struct record *tree){ //LRr
    if (tree == NULL){
        return;
    }
    else{
        PrintMaxMin(tree->right);
        cout << tree->value << " ";
        PrintMaxMin(tree->left);
    }
}

int menu(){
    int choose;
    cout << "=====MENU=====\n";
    cout << "1) Insert\n";
    cout << "2) Print Inorder, Preorder, Postorder\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

int main(){
    int choose;
    struct record *tree = NULL;
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
                PrintPre(tree);
                cout << "\n";
                cout << "Inorder : ";
                PrintIn(tree);
                cout << "\n";
                cout << "Postorder : ";
                PrintPost(tree);
                cout << "\n";
                cout << "Max to min : ";
                PrintMaxMin(tree);
                cout << "\n";
                break;
            case 3:
                break;
        }

    }while(choose!=3);
}
