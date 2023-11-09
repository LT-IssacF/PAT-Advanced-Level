#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int level;
    vector<int> children;
};
int BFS(const int &root, int &breakLevel, vector<node> &tree) {
    queue<int> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (tree[front].level > breakLevel) // 在未访问到零售商之前是不会break的
            break; // 同层的零售商也不会break，如果最早的零售商下一层第一个访问的也是零售商就会break
        if (tree[front].children.size() == 0) { // 最早的零售商
            cnt++;
            breakLevel = tree[front].level;
        }
        for (int i = 0, v = 0; i < tree[front].children.size(); i++) {
            v = tree[front].children[i];
            tree[v].level = tree[front].level + 1; // 更新高度
            q.push(v);
        }
    }
    return cnt;
}
// BFS不用像DFS那样访问所有结点，而是在访问完最早的零售商那一层就break了
int main() {
    int N, cnt, breakLevel = 0x7fffffff; // 初始为最大int
    double P, r;
    cin >> N >> P >> r;
    vector<node> tree(N);
    r /= 100;
    for (int i = 0, K = 0; i < N; i++) {
        scanf("%d", &K);
        for (int j = 0, child = 0; j < K; j++) {
            scanf("%d", &child);
            tree[i].children.push_back(child);
        }
    }
    tree[0].level = 1;
    cnt = BFS(0, breakLevel, tree);
    printf("%.4lf %d", P * pow((1 + r), breakLevel - 1), cnt);
    return 0;
}