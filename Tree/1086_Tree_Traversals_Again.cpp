#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef struct BiNode {
    int data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
vector<int> pre, in, post;
BiTree Insert(const int &preL, const int &preR, const int &inL, const int &inR) {
    if (preL > preR)
        return NULL;
    int i, numLeft;
    for (i = inL; i <= inR; i++)
        if (in[i] == pre[preL]) {
            numLeft = i - inL;
            break;
        }
    BiTree T = (BiTree)malloc(sizeof(BiNode));
    T->data = pre[preL];
    T->lchild = Insert(preL + 1, preL + numLeft, inL, i - 1);
    T->rchild = Insert(preL + numLeft + 1, preR, i + 1, inR);
    return T;
}

void PostOrder(const BiTree &T) {
    if (T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    post.emplace_back(T->data);
}

int main() {
    int N;
    cin >> N;
    stack<int> s;
    string order, push = "Push";
    for (int i = 0, key = 0; i < N * 2; i++) {
        cin >> order;
        if (order == push) {
            scanf("%d", &key);
            pre.push_back(key);
            s.push(key);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    BiTree T = Insert(0, N - 1, 0, N - 1);
    PostOrder(T);
    printf("%d", post[0]);
    for (int i = 1; i < N; i++)
        printf(" %d", post[i]);
    return 0;
}