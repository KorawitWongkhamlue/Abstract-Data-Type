#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

struct node{
    char value;
    struct node *left;
    struct node *right;
};

void printIn(struct node *tree) {
    if (tree == NULL) return;

    // ถ้าไม่ใช่ Leaf Node (แปลว่าเป็น Operator หรือมีลูก) ให้เปิดวงเล็บ
    if (tree->left != NULL || tree->right != NULL) {
        cout << "(";
    }

    printIn(tree->left);        // เดินไปซ้าย
    cout << tree->value << " "; // พิมพ์ Root ตรงกลาง
    printIn(tree->right);       // เดินไปขวา

    // ถ้าเปิดวงเล็บไว้ ก็ปิดวงเล็บเมื่อกลับออกมา
    if (tree->left != NULL || tree->right != NULL) {
        cout << ")";
    }
}

int main(){
    list<struct node *> st;
    struct node *T = NULL;

    char ch;
    cin >> ch;
    while (ch != '.'){
        //operator
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            struct node *rightchild, *leftchild;

            //สร้างโหนดใหม่ในแต่ละรอบ
            struct node *newnode = new struct node;
            newnode->value = ch;

            //Pop 2 ตัวล่าสุดมาเป้นลูก
            rightchild = st.back();
            st.pop_back();
            leftchild = st.back();
            st.pop_back();

            newnode->right = rightchild;
            newnode->left = leftchild;

            st.push_back(newnode);
        }
        else{
            //operand
            struct node *newnode2 = new struct node;
            newnode2->value = ch;
            newnode2->right = newnode2->left = NULL;

            st.push_back(newnode2);
        }

        cin >> ch;
    }

    if (!st.empty()){
        T = st.back();
        cout << "Expression Tree built laew" << endl;

        cout << "Inorder Traversal: ";
        printIn(T);
        cout << endl;
    }

    return 0;
}