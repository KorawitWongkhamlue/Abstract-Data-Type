#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *tree, int x){
    
    if (tree == NULL){
        tree = new struct Node;
        tree->value = x;
        tree->left = tree->right = NULL;
    }
    else{
        if (x < tree->value){
            tree->left = insert(tree->left, x);
        }else{
            tree->right = insert(tree->right, x);
        }
    }
    return tree;
}

void printPre(struct Node *tree){
    if (tree == NULL){
        return;
    }else{
        cout << tree->value << " ";
        printPre(tree->left);
        printPre(tree->right);
    }
    return;
}

int main(){
    struct Node *tree = NULL;
    tree = insert(tree,5);
    tree = insert(tree,8);
    tree = insert(tree,2);
    printPre(tree);
}