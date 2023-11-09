#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct BiNode {
    int data, level;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
int deepest = 0, n1 = 0, n2 = 0;
vector<int> depth;
void Insert(BiTree &T, const int &key) {
    if (!T) {
        T = (BiTree)malloc(sizeof(BiNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        return;
    }
    if (key <= T->data) {
        Insert(T->lchild, key);
    } else {
        Insert(T->rchild, key);
    }
}

void DFS(BiTree &T, const int &level) { // 深度遍历
    if (!T)
        return;
    deepest = max(deepest, level);
    depth[level]++; // 也可以设置一个数组储存各深度的结点个数
    T->level = level;
    DFS(T->lchild, level + 1);
    DFS(T->rchild, level + 1);
}

void BFS(const BiTree &T) { // 广度遍历
    queue<BiTree> q;
    q.push(T);
    while (!q.empty()) {
        BiTree front = q.front();
        q.pop();
        if (front->level == deepest)
            n1++;
        else if (front->level == deepest - 1)
            n2++;
        if (front->lchild)
            q.push(front->lchild);
        if (front->rchild)
            q.push(front->rchild);
    }
}

int main() {
    int N;
    cin >> N;
    BiTree T = NULL;
    for (int i = 0, key = 0; i < N; i++) {
        scanf("%d", &key);
        Insert(T, key);
    }
    depth.resize(N);
    DFS(T, 1);
    // BFS( T );
    cout << depth[deepest] << " + " << depth[deepest - 1] << " = " << depth[deepest] + depth[deepest - 1];
    // cout << n1 << " + " << n2 << " = " << n1 + n2;
    return 0;
}