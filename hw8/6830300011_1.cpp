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


//find min
struct node *find_min(struct node *tree){
    if (tree==NULL)
        return NULL;
    else{
        if (tree->left == NULL){
            return tree;
        }
        else{
            return (find_min(tree->left));
        }
    }
}

//find max
struct node *find_max(struct node *tree){
    if (tree == NULL)
    return NULL;
    else{
        if (tree->right == NULL){
            return tree;
        }
        else{
            return (find_max(tree->right));
        }
    }
}

//find data
struct node *find_data(struct node *tree, int x){
    if (tree == NULL){
        return NULL;
    }else if (x < tree->value){
        return find_data(tree->left, x);
    }else if (x > tree->value){
        return find_data(tree->right, x);
    }else{
        return tree;
    }
}

//delete tree
struct node *dTree(struct node *tree, int x){
    struct node *tmpcell, *child;
    if (tree == NULL){
        cout << "No Node\n";
    }else{
        if (x < tree->value){
            tree->left = dTree(tree->left,x);
        }else{
            if (x > tree->value){
                tree->right = dTree(tree->right, x);
            }else{
                if (tree->left && tree->right){
                    tmpcell = find_min(tree->right);
                    tree->value = tmpcell->value;
                    tree->right = dTree(tree->right, tree->value);
                }else{
                    tmpcell = tree;
                    if (tree->left == NULL){
                        child = tree->right;
                    }
                    if (tree->right == NULL){
                        child = tree->left;
                    }
                    delete(tmpcell);
                    return child;
                }
            }
        }
    }
    return tree;
}


int menu(){
    int choose;
    cout << "========MENU======\n";
    cout << "1) Insert\n";
    cout << "2) Print Inorder\n";
    cout << "3) Delete\n";
    cout << "4) Find min and max\n";
    cout << "5) Find data\n";
    cout << "6) Exit\n";
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
                cout << "Success!\n";
                break;
            }
            case 2:
                cout << "Inorder : ";
                printIn(tree);
                cout << "\n";
                break;
            case 3:
            {
                int x;
                cout << "Delelete : ";
                cin >> x;
                tree = dTree(tree, x);
                cout << "Success!\n";
                break;
            }
            case 4:
            {
                struct node *mx = find_max(tree);
                struct node *mn = find_min(tree);
                if (mx != NULL) cout << "Max = " << mx->value << "\n";
                if (mn != NULL) cout << "Min = " << mn->value << "\n";
                break;
            }
            case 5:
            {
                int x;
                cout << "Enter number to find : ";
                cin >> x;
                struct node *result = find_data(tree, x);
                if (result != NULL){
                    cout << "Found!\n";
                }else{
                    cout << "Notfound!\n";
                }
                break;
            }
            case 6:
                break;
        }

    }while(choose!=6);
}