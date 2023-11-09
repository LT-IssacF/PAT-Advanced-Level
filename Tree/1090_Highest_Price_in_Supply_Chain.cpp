#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tree;
void DFS(const int &now, const int &depth, int &deepest, int &cnt) {
    if (tree[now].size() == 0) { // 到零售商了
        if (depth > deepest) {
            deepest = depth; // 更新深度
            cnt = 1; // 计数重置
        } else if (depth == deepest) {
            cnt++;
        }
        return;
    }
    for (int i = 0; i < tree[now].size(); i++)
        DFS(tree[now][i], depth + 1, deepest, cnt);
}

int main() {
    int N, root, deepest = 0, cnt = 1;
    double P, r;
    cin >> N >> P >> r;
    tree.resize(N);
    r /= 100;
    for (int i = 0, supplier = 0; i < N; i++) {
        scanf("%d", &supplier);
        if (supplier >= 0) {
            tree[supplier].push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, 1, deepest, cnt);
    printf("%.2f %d", P * pow(1 + r, deepest - 1), cnt);
    return 0;
}