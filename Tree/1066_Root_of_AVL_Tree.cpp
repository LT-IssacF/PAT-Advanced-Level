#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef struct BiNode {
    int data, height;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
int GetHeight(const BiTree &T) {
    return (T == NULL ? 0 : T->height);
}
// 平衡因子
int GetBalance(const BiTree &T) {
    return GetHeight(T->lchild) - GetHeight(T->rchild);
}
// 不要忘了+1
void UpdateHeight(BiTree &T) {
    T->height = max(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
}
// 左旋
void LeftRotation(BiTree &T) {
    BiTree temp = T->rchild;
    T->rchild = temp->lchild;
    temp->lchild = T;
    UpdateHeight(T);
    UpdateHeight(temp);
    T = temp;
}
// 右旋
void RightRotation(BiTree &T) {
    BiTree temp = T->lchild;
    T->lchild = temp->rchild;
    temp->rchild = T;
    UpdateHeight(T);
    UpdateHeight(temp);
    T = temp;
}

void Insert(BiTree &T, const int &key) {
    if (T == NULL) {
        T = (BiTree)malloc(sizeof(BiNode));
        T->data = key, T->height = 1;
        T->lchild = T->rchild = NULL;
        return;
    }
    if (T->data > key) { // 往左边插
        Insert(T->lchild, key);
        UpdateHeight(T);
        if (GetBalance(T) == 2) { // 需要平衡
            if (GetBalance(T->lchild) == 1) { // LL型树
                RightRotation(T); // 一次右旋
            } else if (GetBalance(T->lchild) == -1) { // LR型树
                LeftRotation(T->lchild); // 先对左子树左旋
                RightRotation(T); // 再给自己右旋
            }
        }
    } else { // 往右边插
        Insert(T->rchild, key);
        UpdateHeight(T);
        if (GetBalance(T) == -2) { // 需要平衡
            if (GetBalance(T->rchild) == -1) { // RR型树
                LeftRotation(T); // 一次左旋
            } else if (GetBalance(T->rchild) == 1) { // RL型树
                RightRotation(T->rchild); // 先对右子树右旋
                LeftRotation(T); // 再对自己左旋
            } // LL和LR型树都是左高右低，RR和RL型树是右高左低
        } // LL(2,1)是root的左子树左边高，而LR(2,-1)是root的左子树右边高
    } // 所以LL型一次右旋就可以了，而LR型要先对root的左子树左旋，再对root右旋
} // RR和RL型同理

int main() {
    int N;
    cin >> N;
    BiTree T = NULL;
    for (int i = 0, key = 0; i < N; i++) {
        scanf("%d", &key);
        Insert(T, key);
    }
    cout << T->data;
    return 0;
}