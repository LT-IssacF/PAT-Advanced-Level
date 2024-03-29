#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct BiNode {
    int data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
int pre[32], post[32], in[32]; // 分别保存前序、中序、后序序列
vector<int> ans;
// 由前序和中序序列建树
// BiTree Insert(const int &preL, const int &preR, const int &inL, const int &inR) {
//     if (preL > preR)
//         return NULL;
//     int i, numLeft;
//     for (i = inL; i <= inR; i++)
//         if (in[i] == pre[preL])
//             break;
//     numLeft = i - inL; // 左子树的个数
//     BiTree T = (BiTree)malloc(sizeof(BiNode));
//     T->data = pre[preL];
//     T->lchild = Insert(preL + 1, preL + numLeft, inL, i - 1);
//     T->rchild = Insert(preL + numLeft + 1, preR, i + 1, inR);
//     return T;
// }
// // 由后序和中序序列建树
// BiTree Insert(const int &postL, const int &postR, const int &inL, const int &inR) {
//     if (postL > postR)
//         return NULL;
//     int i, numLeft;
//     for (i = inL; i <= inR; i++)
//         if (in[i] == post[postR])
//             break;
//     numLeft = i - inL;
//     BiTree T = (BiTree)malloc(sizeof(BiNode));
//     T->data = post[postR];
//     T->lchild = Insert(postL, postL + numLeft - 1, inL, i - 1);
//     T->rchild = Insert(postL + numLeft, postR - 1, i + 1, inR);
//     return T;
// }

// void BFS(const BiTree &T) {
//     queue<BiTree> q;
//     q.push(T);
//     BiTree front;
//     while (!q.empty()) {
//         front = q.front();
//         ans.push_back(front->data);
//         q.pop();
//         if (front->lchild != NULL)
//             q.push(front->lchild);
//         if (front->rchild != NULL)
//             q.push(front->rchild);
//     }
// }

// int main() {
//     int N;
//     cin >> N;
//     for (int i = 0; i < N; i++)
//         scanf("%d", &post[i]);
//     for (int i = 0; i < N; i++)
//         scanf("%d", &in[i]);
//     BiTree T = Insert(0, N - 1, 0, N - 1);
//     BFS(T);
//     for (int i = 0; i < ans.size(); i++) {
//         if (i > 0)
//             printf(" ");
//         printf("%d", ans[i]);
//     }
//     return 0;
// }

struct node {
    int lchild, rchild;
} tree[32];
int in[32], post[32];
vector<int> ans;
int Insert(const int &postL, const int &postR, const int &inL, const int &inR) {
    if (postL > postR)
        return -1;
    int i, numLeft;
    for (i = inL; i <= inR; i++)
        if (in[i] == post[postR])
            break;
    numLeft = i - inL;
    tree[post[postR]].lchild = Insert(postL, postL + numLeft - 1, inL, i - 1);
    tree[post[postR]].rchild = Insert(postL + numLeft, postR - 1, i + 1, inR);
    return post[postR];
}

void BFS(const int &root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        if (tree[front].lchild != -1)
            q.push(tree[front].lchild);
        if (tree[front].rchild != -1)
            q.push(tree[front].rchild);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    int root = Insert(0, N - 1, 0, N - 1);
    BFS(root);
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0)
            printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}