#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef struct BiNode {
    int data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
vector<int> pre, in, post;
bool flag = false; // 标记后序的第一个值已输入，可用来提前结束递归
BiTree Insert(const int &preL, const int &preR, const int &inL, const int &inR) {
    if (preL > preR || flag) // 本来就是空子树或是要提前结束建子树
        return NULL;
    int numLeft, i;
    for (i = inL; i <= inR; i++)
        if (in[i] == pre[preL])
            break;
    numLeft = i - inL;
    BiTree T = (BiTree)malloc(sizeof(BiNode));
    T->data = pre[preL];
    T->lchild = Insert(preL + 1, preL + numLeft, inL, i - 1);
    T->rchild = Insert(preL + numLeft + 1, preR, i + 1, inR);
    post.push_back(T->data); // 能执行到这一步就是要的结果了
    flag = true;
    return T;
}

int main() {
    int N;
    cin >> N;
    pre.resize(N), in.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    BiTree T = Insert(0, N - 1, 0, N - 1);
    cout << post[0];
    return 0;
}