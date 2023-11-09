#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void DFS(vector<int> &depth, const vector<vector<int>> &tree, const int &now, const int &height) {
    depth[height]++;
    for (int i = 0; i < tree[now].size(); i++)
        DFS(depth, tree, tree[now][i], height + 1);
}

int main() {
    int N, M, ans = 0, height = 0;
    cin >> N >> M;
    vector<vector<int>> tree(N + 1);
    vector<int> depth(N + 1, 0); // 存储每代人的人数
    for (int i = 0, key = 0, K = 0; i < M; i++) {
        scanf("%d %d", &key, &K);
        for (int j = 0, child = 0; j < K; j++) {
            scanf("%d", &child);
            tree[key].push_back(child);
        }
    }
    DFS(depth, tree, 1, 1);
    for (int i = 1; i <= N && depth[i] > 0; i++)
        if (depth[i] > ans) {
            ans = depth[i];
            height = i;
        }
    printf("%d %d", ans, height);
    return 0;
}