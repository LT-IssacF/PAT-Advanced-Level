#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
struct node {
    int color; // 结点的颜色
    vector<int> v; // 与结点连通的结点
};

int main() {
    int N, M, K;
    cin >> N >> M;
    vector<node> G(N); // 邻接表
    for (int i = 0, v1 = 0, v2 = 0; i < M; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1].v.push_back(v2);
        G[v2].v.push_back(v1);
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        unordered_set<int> coloring; // 储存不同的颜色
        for (int j = 0, color = 0; j < N; j++) {
            scanf("%d", &color);
            G[j].color = color;
            coloring.insert(color);
        }
        bool flag = true; // 判断连通的两个结点是否是相同的颜色
        for (int j = 0; j < N && flag == true; j++) { // 判断每个结点
            for (const int v1 : G[j].v) { // 遍历此结点所有连通的结点
                if (G[j].color == G[v1].color) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true) {
            printf("%d-coloring\n", coloring.size());
        } else {
            printf("No\n");
        }
    }
    return 0;
}