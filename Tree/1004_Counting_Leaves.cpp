#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 0xff
using namespace std;
struct node { // 邻接表
    int layer;
    vector<int> child;
} tree[MAX];
vector<int> ans;

void BFS(const int &root) {
    queue<int> q;
    q.push(root);
    tree[root].layer = 1;
    int nowLayer = tree[root].layer, cnt = 0;
    while (!q.empty()) {
        int front = q.front();
        if (nowLayer != tree[front].layer) { // 已经到下一层
            ans.push_back(cnt); // 保存叶子结点个数
            nowLayer = tree[front].layer; // 更新信息
            cnt = 0;
        }
        q.pop();
        if (tree[front].child.size() == 0) { // 叶子结点+1
            cnt++;
        } else {
            for (int i = 0; i < tree[front].child.size(); i++) {
                tree[tree[front].child[i]].layer = nowLayer + 1;
                q.push(tree[front].child[i]);
            }
        }
    }
    ans.push_back(cnt); // 保存最后一层的叶子结点个数
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0, id = 0, K = 0; i < M; i++) {
        scanf("%d %d", &id, &K);
        tree[id].child.resize(K);
        for (int j = 0; j < K; j++)
            scanf("%d", &tree[id].child[j]);
    }
    BFS(1);
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
    return 0;
}