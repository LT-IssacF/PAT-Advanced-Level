#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    vector<int> children;
    int product;
};
vector<node> tree;
void DFS(const int &now, const double &r, const double &price, double &ans) {
    if (tree[now].children.size() == 0) { // 到零售商了
        ans += price * tree[now].product;
        return;
    }
    for (const int &v : tree[now].children)
        DFS(v, r, price * (1 + r), ans); // 递归时顺便处理价格
}

int main() {
    int N;
    double P, r, ans = 0;
    cin >> N >> P >> r;
    tree.resize(N);
    r /= 100; // 对收费率处理
    for (int i = 0, value = 0; i < N; i++) {
        scanf("%d", &value);
        for (int j = 0, child = 0; j < value; j++) {
            scanf("%d", &child);
            tree[i].children.push_back(child);
        }
        if (value == 0)
            scanf("%d", &tree[i].product);
    }
    DFS(0, r, P, ans);
    printf("%.1f", ans);
    return 0;
}