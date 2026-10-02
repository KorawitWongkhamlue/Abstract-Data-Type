#include <stdio.h>
#include <iostream>
using namespace std;

struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *tree, int x){
    //no tree
    if (tree == NULL){
        tree = new struct node;
        tree->value = x;
        tree->left = tree->right = NULL;
    }
    else{
        if (x < tree->value){
            tree->left = insert(tree->left, x);
        }else{
            tree->right = insert(tree->right,x);
        }
    }
    return tree;
}

struct node *find_min(struct node *tree){
    if (tree == NULL){
        return NULL;
    }
    else{
        if (tree->left == NULL){
            return tree->left;
        }else{
            return find_min(tree->left);
        }
    }
}

struct node *dTree(struct node *tree, int x){
    struct node *tmp, *child;
    if (tree == NULL){
        cout << "No Tree!" << endl;
        return NULL;
    }else{
        if (x < tree->value){
            tree->left = dTree(tree->left,x);
        }else if (x > tree->value){
            tree->right = dTree(tree->right,x);
        }else{
            //two child
            if (tree->left && tree->right){
                tmp = find_min(tree->right); //หาเลข min
                tree->value = tmp->value; //เอาเลข min มาแทน tree เลย
                tree->right = dTree(tree->right,tree->value); //ลบ tree right
            }
            else{
                tmp = tree;
                if (tree->left == NULL){
                    child = tree->right;
                }
                if (tree->right == NULL){
                    child = tree->left;
                }
                delete(tmp);
                return child;
            }
        }
    }
    return tree;
}


void printIn(struct node *tree){
    if (tree == NULL){
        return;
    }
    else{
        printIn(tree->left);
        cout << tree->value << " ";
        printIn(tree->right);
    }
    return;
}


int main(){
    struct node *tree = NULL;

    tree = insert(tree, 4);
    tree = insert(tree, 5);
    tree = insert(tree, 6);

    cout << "before: ";
    printIn(tree);
    cout << "after: ";
    tree = dTree(tree, 5);
    printIn(tree);

}