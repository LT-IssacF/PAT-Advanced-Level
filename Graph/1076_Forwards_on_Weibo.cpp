#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int v, level;
};
vector<vector<node>> G; // G[i][j].v表示i的第j个粉丝是v
vector<bool> visit;
int BFS(const int &up, const int &L) {
    queue<node> q;
    q.push(node{up, 0});
    visit[up] = true;
    int ans = 0;
    while (!q.empty()) {
        node front = q.front();
        q.pop();
        if (front.level > L)
            break;
        ans++;
        for (int i = 0, v = 0; i < G[front.v].size(); i++) {
            v = G[front.v][i].v;
            if (visit[v] == false) {
                visit[v] = true; // 因为图中可能有环，为了避免将一个结点多次入队，所以必须在入队时就修改标记
                q.push(node{v, front.level + 1});
            }
        }
    }
    return ans;
}

int main() {
    int N, L, K;
    cin >> N >> L;
    G.resize(N + 1);
    visit.resize(N + 1);
    for (int i = 1, cnt = 0; i <= N; i++) {
        scanf("%d", &cnt);
        for (int j = 0, up = 0; j < cnt; j++) {
            scanf("%d", &up);
            G[up].emplace_back(node{i, 0});
        }
    }
    cin >> K;
    for (int i = 0, up = 0, ans = 0; i < K; i++) {
        fill(visit.begin(), visit.end(), false);
        scanf("%d", &up);
        ans = BFS(up, L);
        printf("%d\n", ans - 1); // 减去up自己
    }
    return 0;
}