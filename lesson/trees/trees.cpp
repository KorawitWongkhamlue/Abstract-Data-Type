#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *tree, int x){

    //no tree yet, less than, more than
    if (tree == NULL){
        tree = new struct node;
        tree->value = x;
        tree->left = NULL;
        tree->right = NULL;
    }
    else{
        if (x < tree->value){
            tree->left = insert(tree->left,x);
        }else if (x > tree->value){
            tree->right = insert(tree->right,x);
        }
    }
    return tree;
}

//pre order
void printpro(struct node *tree){
    if (tree == NULL){
        return;
    }else{
        cout << tree->value << endl;
        printpro(tree->left);
        printpro(tree->right);
    }
    return;
}

void printino(struct node *tree){
    if (tree == NULL){
        return;
    }else{
        printino(tree->left);
        cout << tree->value << endl;
        printino(tree->right);
    }
    return;
}

void printpso(struct node *tree){
    if (tree == NULL){
        return;
    }else{
        printpso(tree->left);
        printpso(tree->right);
        cout << tree->value << endl;
    }
    return;
}

int main(){
    struct node *tree = NULL;
    tree = insert(tree,5);
    tree = insert(tree,8);
    tree = insert(tree,2);
    printpro(tree);
    cout << "\n";
    printino(tree);
    cout << "\n";
    printpso(tree);
}