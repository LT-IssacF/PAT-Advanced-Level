#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, dis;
    node(const int &v2, const int &dis2) : v(v2), dis(dis2) {}
}; // G[c1][i].v表示c1到其连通的第i个城市(i从0开始)的城市号
// G[c1][i].dis表示c1到其连通的第i个城市的距离，G[c1][i].w表示从c1到其连通的第i个城市可以带上该城市内的w个救援队
vector<vector<node>> G; // 邻接表
vector<int> d, cntOfPath, teamGather, teamOfCity;
// d储存最短路径长度，cntOfPath储存最短路径数量，teamGather储存能带的队伍数量
vector<int> visit; // 访问标记
void Dijkstra(const int &N, const int &start) {
    fill(d.begin(), d.end(), INF);
    fill(cntOfPath.begin(), cntOfPath.end(), 0);
    fill(teamGather.begin(), teamGather.end(), 0);
    fill(visit.begin(), visit.end(), false);
    d[start] = 0; // 赋初值
    cntOfPath[start] = 1;
    teamGather[start] = teamOfCity[start];
    for (int i = 0; i < N; i++) {
        int u = -1, min = INF; // 找离当前城市最近且未访问过的城市
        for (int j = 0; j < N; j++) {
            if (visit[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = true;
        for (int j = 0; j < G[u].size(); j++) {
            int v = G[u][j].v;
            if (visit[v] == false) {
                if (d[u] + G[u][j].dis < d[v]) { // 更新最短路径长度
                    d[v] = d[u] + G[u][j].dis;
                    cntOfPath[v] = cntOfPath[u];
                    teamGather[v] = teamGather[u] + teamOfCity[v];
                } else if (d[u] + G[u][j].dis == d[v]) { // 路径长度相等
                    if (teamGather[u] + teamOfCity[v] > teamGather[v]) { // 且此路径能带的队伍更多
                        teamGather[v] = teamGather[u] + teamOfCity[v];
                    }
                    cntOfPath[v] += cntOfPath[u]; // 更新路径数量
                }
            }
        }
    }
}

int main() {
    int N, M, city1, city2;
    cin >> N >> M >> city1 >> city2;
    G.resize(N);
    d.resize(N);
    cntOfPath.resize(N);
    teamGather.resize(N);
    teamOfCity.resize(N);
    visit.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &teamOfCity[i]); // 城市i自己的救援队数
    for (int i = 0, v1 = 0, v2 = 0, dis = 0; i < M; i++) {
        scanf("%d %d %d", &v1, &v2, &dis);
        G[v1].emplace_back(node(v2, dis));
        G[v2].emplace_back(node(v1, dis));
    }
    Dijkstra(N, city1);
    cout << cntOfPath[city2] << " " << teamGather[city2];
    return 0;
}