#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef struct RBNode {
    bool color; // false: red, true: black
    int data;
    struct RBNode *lchild, *rchild, *parent;
} RBNode, *RBTree;
bool IsLeafNode(const RBTree &T) {
    return (T->lchild == NULL && T->rchild == NULL);
}

void LeftRotation(RBTree &T) {
    RBTree temp = T->rchild;
    T->rchild = temp->lchild;
    temp->lchild = T;
    // 变色
    T = temp;
}

void RightRotation(RBTree &T) {
    RBTree temp = T->lchild;
    T->lchild = temp->rchild;
    temp->rchild = T;
    // 变色
    T = temp;
}

void Insert(RBTree &T, RBTree &pre, const int &key) {
    if (T == NULL) {
        T = (RBTree)malloc(sizeof(RBNode));
        T->data = key, T->color = false;
        T->lchild = T->rchild = NULL;
        T->parent = pre;
        return;
    }
    if (T->data < key) {
        Insert(T->lchild, T, key);
        if (!IsLeafNode(T) && T->color == false) {
            if (T->rchild != NULL && T->rchild->color == false) {
                LeftRotation(T);
                RightRotation(T->parent);
            }
        }
    } else {
        Insert(T->rchild, T, key);
    }
}

int main() {}