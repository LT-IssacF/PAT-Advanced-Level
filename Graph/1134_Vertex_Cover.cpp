#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
// 判断图中所有边是否都连在给定的顶点上
int main() {
    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> vertice(N, vector<int>());
    vector<bool> edge(M, false); // 判断连在M个顶点上的边是否是图中全部的边
    for (int i = 0, v = 0, v2 = 0; i < M; i++) {
        scanf("%d %d", &v, &v2);
        vertice[v].push_back(i), vertice[v2].push_back(i);
    } // vertice[v][i] = e表示编号为e的边是连接到顶点v的第i条边，即e属于顶点v
    cin >> K;
    for (int i = 0; i < K; i++) {
        scanf("%d", &N);
        fill(edge.begin(), edge.end(), false);
        for (int j = 0, v = 0; j < N; j++) {
            scanf("%d", &v);
            for (const int &e : vertice[v]) { // 遍历该顶点所有的边
                edge[e] = true;
            }
        }
        bool ans = true;
        for (const bool &j : edge) {
            if (j == false) { // 如果有边没有被包含到
                ans = false;
                break;
            }
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}