#include <stdio.h>
#include <iostream>
using namespace std;

struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *tree, int x){
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

void printpre(struct node *tree){
    if (tree == NULL){
        return;
    }else{
        cout << tree->value << " ";
        printpre(tree->left);
        printpre(tree->right);
    }
    return;
}

//Delete Tree : No Child, One Child, Two Children
//use Find Min
struct node *find_min(struct node *tree){
    if (tree == NULL){
        return NULL;
    }
    else{
        if (tree->left == NULL){
            return tree;
        }else{
            return find_min(tree->left);
        }
    }
}

struct node *dTree(struct node *tree, int x){
    struct node *tmp, *child;
    
    //no node
    if (tree == NULL){
        cout << "No Node";
        return NULL;
    }

    else{
        //ขุดเข้าไปหา
        if (x < tree->value){
            tree->left = dTree(tree->left, x);
        }else{
            if (x > tree->value){
                tree->right = dTree(tree->right,x);
            }else{

                //Two Children
                if (tree->left && tree->right){
                    tmp = find_min(tree->right); //หาค่า min right
                    tree->value = tmp->value; //สลับ ค่า min right กับค่า x
                    tree->right = dTree(tree->right, tree->value); //ลบ treeright ที่ถือค่า x
                }
                else{

                //One Child or No Child
                    tmp = tree; 

                    //กำหนด child
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
    }
    return tree;
}

int main(){
    struct node *tree = NULL;
    tree = insert(tree, 10);
    tree = insert(tree, 5);
    tree = insert(tree, 18);
    tree = insert(tree, 2);
    tree = insert(tree, 7);
    tree = insert(tree, 15);
    tree = insert(tree, 29);

    cout << "Before delete: ";
    printpre(tree);
    cout << "\n";
    cout << "After delete: ";
    tree = dTree(tree, 5);
    printpre(tree);
    cout << endl;
}