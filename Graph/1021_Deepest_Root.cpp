#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> G;
vector<bool> visit;
int tempDepth = 1; // 记录从每个结点开始深度遍历的最大深度
void DFS(const int &now, const int &depth) {
    if (depth > tempDepth) // 更新高度
        tempDepth = depth;
    visit[now] = true;
    for (int i = 0; i < G[now].size(); i++)
        if (visit[G[now][i]] == false)
            DFS(G[now][i], depth + 1);
}

int DFS_Travels(const int &start, const int &N) {
    int subGraph = 0;
    for (int i = start; i <= N; i++) {
        if (visit[i] == false) {
            DFS(i, 1);
            subGraph++;
        }
    }
    return subGraph;
}

int main() {
    int N;
    cin >> N;
    G.resize(N + 1);
    visit.resize(N + 1);
    for (int i = 1, v1 = 0, v2 = 0; i < N; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    } // N个结点N-1条边，只能是一棵树，除非不是连通图
    int subGraph = DFS_Travels(1, N);
    if (subGraph > 1)
        cout << "Error: " << subGraph << " components";
    else {
        vector<vector<int>> depth(N + 1); // 保存不同深度的根结点，N个结点最大深度为N
        int maxDepth = 1; // 最大深度
        for (int i = 1; i <= N; i++) {
            tempDepth = 1;
            fill(visit.begin(), visit.end(), false);
            DFS(i, 1); // 从结点i开始深度遍历得到以i为根的树的深度
            depth[tempDepth].push_back(i);
            if (tempDepth > maxDepth)
                maxDepth = tempDepth;
        }
        for (int i = 0; i < depth[maxDepth].size(); i++)
            printf("%d\n", depth[maxDepth][i]);
    }
    return 0;
}