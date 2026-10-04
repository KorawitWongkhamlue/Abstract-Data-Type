#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
    int value;
    int height;
    struct node *left;
    struct node *right;
};

//หา height
int fheight(struct node *P){
    if (P == NULL){
        return -1;
    }else{
        return P->height;
    }
}

int max(int a, int b){
    if (a > b){ return a; }
    else { return b; }
}

struct node *srright(struct node *k2){
    struct node *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(fheight(k2->left), fheight(k2->right)) + 1;
    k1->height = max(fheight(k1->left), k2->height) + 1;

    return k1;
}

struct node *srleft(struct node *k2){
    struct node *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k2->height = max(fheight(k2->right), fheight(k2->left)) + 1;
    k1->height = max(fheight(k1->right), k2->height) + 1;

    return k1;

}


//db rotation
struct node *dLR(struct node *k3){
    k3->left = srleft(k3->left);
    return srright(k3);
}

struct node *dRL(struct node *k3){
    k3->right = srright(k3->right);
    return srleft(k3);
}


struct node *insert(struct node *tree, int x){
    if (tree == NULL){
        tree = new struct node;
        tree->value = x;
        tree->left = tree->right = NULL;
        tree->height = 0;
    }
    else{
        if (x < tree->value){
            tree->left = insert(tree->left, x);

            //เอียงซ้าย หมุนขวา
            if (fheight(tree->left) - fheight(tree->right) == 2){
                if (x < tree->left->value){
                    //single Rotation
                    tree = srright(tree);
                }else{
                    tree = dLR(tree);
                    //dbRotation
                }
            }
        }
        else if (x > tree->value){
            tree->right = insert(tree->right,x);

            //เอียงขวา หมุนซ้าย
            if (fheight(tree->right) - fheight(tree->left) == 2){
                if (x > tree->right->value){
                    tree = srleft(tree);
                }else{
                    tree = dRL(tree);
                }
            }
        }
    }
    tree->height = max(fheight(tree->left), fheight(tree->right)) + 1;
    return tree;
}

void PrintIn(struct node *tree){
    if (tree == NULL){
        return;
    }else{
        PrintIn(tree->left);
        cout << tree->value << " " ;
        PrintIn(tree->right);
    }
}

int main(){
    struct node *tree = NULL;
    int values[] = {10,8,6,16,14,9,7,15};

    for (int v : values){
        tree = insert(tree, v);
    }

    cout << "Inorder: ";
    PrintIn(tree);
    cout << endl;
    return 0;
}