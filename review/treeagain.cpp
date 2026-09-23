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

void PrintPre(struct record *tree){
    if (tree == NULL){
        return;
    }
    else{
        cout << tree->value << " ";
        PrintPre(tree->left);
        PrintPre(tree->right);
    }
}