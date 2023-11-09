// #include <iostream>
// #include <vector>
// #define INF 0x3fffffff
// using namespace std;
// struct node {
//     int v, length, time;
// } temp;
// vector<vector<node>> G;
// vector<int> d, t, dPath, tPath, dpre, tpre, nodeCnt;
// vector<bool> visit;
// // Path数组存储路径，pre数组储存前驱，nodeCnt记录最短路径上当前结点的前驱结点个数
// void Dijkstra(int N, int source, int tag) { // tag标记使用距离还是时间作为优先条件
//     fill(visit.begin(), visit.end(), false);
//     fill(t.begin(), t.end(), INF);
//     if (!tag) { // 距离优先
//         fill(d.begin(), d.end(), INF);
//         d[source] = 0, t[source] = 0; // 设置起点
//         for (int i = 0; i < N; i++) { // 找未访问过且距离最小的结点
//             int u = -1, min = INF;
//             for (int j = 0; j < N; j++) {
//                 if (visit[j] == false && d[j] < min) {
//                     u = j;
//                     min = d[j];
//                 }
//             }
//             if (u == -1)
//                 break;
//             visit[u] = true;
//             int size = G[u].size();
//             for (int j = 0, v = 0; j < size; j++) {
//                 v = G[u][j].v;
//                 if (visit[v] == false) {
//                     if (d[u] + G[u][j].length < d[v]) { // 距离更小
//                         d[v] = d[u] + G[u][j].length;
//                         t[v] = t[u] + G[u][j].time;
//                         dpre[v] = u; // u是v的前驱
//                     } else if (d[u] + G[u][j].length == d[v]) { // 距离相等
//                         if (t[u] + G[u][j].time < t[v]) { // 时间更少
//                             t[v] = t[u] + G[u][j].time;
//                             dpre[v] = u;
//                         }
//                     }
//                 }
//             }
//         }
//     } else { // 时间优先
//         t[source] = 0, nodeCnt[source] = 0;
//         for (int i = 0; i < N; i++) {
//             int u = -1, min = INF;
//             for (int j = 0; j < N; j++) {
//                 if (visit[j] == false && d[j] < min) {
//                     u = j;
//                     min = d[j];
//                 }
//             }
//             if (u == -1)
//                 break;
//             visit[u] = true;
//             int size = G[u].size();
//             for (int j = 0; j < size; j++) {
//                 int v = G[u][j].v;
//                 if (t[u] + G[u][j].time < t[v]) { // 时间更少
//                     t[v] = t[u] + G[u][j].time;
//                     tpre[v] = u;
//                     nodeCnt[v] = nodeCnt[u] + 1; // 结点数+1
//                 } else if (t[u] + G[u][j].time == t[v]) { // 时间相同
//                     if (nodeCnt[u] + 1 < nodeCnt[v]) { // 以u为前驱结点数会更少
//                         tpre[v] = u;
//                         nodeCnt[v] = nodeCnt[u] + 1;
//                     }
//                 }
//             }
//         }
//     }
// }

// void DFSdPath(int source, int destination) {
//     if (destination != source) {
//         DFSdPath(source, dpre[destination]);
//         dPath.push_back(destination);
//         return;
//     }
//     dPath.push_back(source);
// }

// void DFStPath(int source, int destination) {
//     if (destination != source) {
//         DFStPath(source, tpre[destination]);
//         tPath.push_back(destination);
//         return;
//     }
//     tPath.push_back(source);
// }

// int main() {
//     int N, M, source, destination;
//     cin >> N >> M;
//     G.resize(N);
//     d.resize(N);
//     t.resize(N);
//     dpre.resize(N);
//     tpre.resize(N);
//     nodeCnt.resize(N);
//     visit.resize(N);
//     for (int i = 0, v1 = 0, v2 = 0, tag = 0; i < M; i++) {
//         cin >> v1 >> v2 >> tag >> temp.length >> temp.time;
//         temp.v = v2;
//         G[v1].emplace_back(temp);
//         if (!tag) { // 双行道
//             temp.v = v1;
//             G[v2].emplace_back(temp);
//         }
//     }
//     cin >> source >> destination;
//     Dijkstra(N, source, 0);
//     DFSdPath(source, destination);
//     Dijkstra(N, source, 1);
//     DFStPath(source, destination);
//     if (dPath == tPath) {
//         cout << "Distance = " << d[destination] << "; Time = " << t[destination] << ": " << tPath[0];
//         int size = tPath.size();
//         for (int i = 1; i < size; i++)
//             cout << " -> " << tPath[i];
//     } else {
//         cout << "Distance = " << d[destination] << ": " << dPath[0];
//         int size = dPath.size();
//         for (int i = 1; i < size; i++)
//             cout << " -> " << dPath[i];
//         cout << endl << "Time = " << t[destination] << ": " << tPath[0];
//         size = tPath.size();
//         for (int i = 1; i < size; i++)
//             cout << " -> " << tPath[i];
//     }
//     return 0;
// }

#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, dis, time;
}; // path数组存储路径，pre数组储存前驱，nodeCnt记录最短路径上当前结点的前驱结点个数
vector<vector<node>> G;
vector<int> d, t, dpre, tpre, nodeCnt, dpath, tpath;
vector<bool> visit;
void Dijkstra(const int &N, const int &source, const int &tag) { // tag标记使用距离还是时间作为优先条件
    fill(t.begin(), t.end(), INF);
    fill(visit.begin(), visit.end(), false);
    t[source] = 0; // 设置起点
    if (tag == 0) { // 距离优先
        fill(d.begin(), d.end(), INF);
        d[source] = 0; // 设置起点
        for (int i = 0; i < N; i++) {
            int u = -1, MIN = INF;
            for (int j = 0; j < N; j++)
                if (d[j] < MIN && visit[j] == false) {
                    u = j;
                    MIN = d[j];
                }
            if (u == -1)
                break;
            visit[u] = true;
            for (int j = 0, v = 0; j < G[u].size(); j++) {
                v = G[u][j].v;
                if (visit[v] == false) {
                    if (d[u] + G[u][j].dis < d[v]) { // 距离更小
                        d[v] = G[u][j].dis + d[u];
                        t[v] = G[u][j].time + t[u];
                        dpre[v] = u; // u是v的前驱
                    } else if (d[u] + G[u][j].dis == d[v] && t[u] + G[u][j].time < t[v]) {
                        t[v] = G[u][j].time + t[u];
                        dpre[v] = u;
                    } // 距离相等时间更少
                }
            }
        }
    } else { // 时间优先
        nodeCnt[source] = 0; // 设置起点
        for (int i = 0; i < N; i++) {
            int u = -1, MIN = INF;
            for (int j = 0; j < N; j++)
                if (t[j] < MIN && visit[j] == false) {
                    u = j;
                    MIN = d[j];
                }
            if (u == -1)
                break;
            visit[u] = true;
            for (int j = 0, v = 0; j < G[u].size(); j++) {
                v = G[u][j].v;
                if (visit[v] == false) {
                    if (t[u] + G[u][j].time < t[v]) {
                        t[v] = G[u][j].time + t[u];
                        tpre[v] = u;
                        nodeCnt[v] = nodeCnt[u] + 1;
                    } else if (t[u] + G[u][j].time == t[v] && nodeCnt[u] + 1 < nodeCnt[v]) {
                        tpre[v] = u;
                        nodeCnt[v] = nodeCnt[u] + 1;
                    } // 以u为前驱结点数会更少
                }
            }
        }
    }
}

void DFS(const int &now, const int &source, const vector<int> &pre, vector<int> &path) {
    if (now == source) {
        path.push_back(now);
        return;
    }
    DFS(pre[now], source, pre, path);
    path.push_back(now);
}

void Print(const vector<int> &path) {
    printf("%d", path[0]);
    for (int i = 1; i < path.size(); i++)
        printf(" -> %d", path[i]);
}

int main() {
    int N, M, source, destination;
    cin >> N >> M;
    G.resize(N);
    d.resize(N), t.resize(N), dpre.resize(N), tpre.resize(N), nodeCnt.resize(N);
    visit.resize(N);
    for (int i = 0, v = 0, v2 = 0, tag = 0, dis = 0, time = 0; i < M; i++) {
        scanf("%d %d %d %d %d", &v, &v2, &tag, &dis, &time);
        G[v].emplace_back(node{v2, dis, time});
        if (tag == 0) // 单行道
            G[v2].emplace_back(node{v, dis, time});
    }
    cin >> source >> destination;
    Dijkstra(N, source, 0);
    Dijkstra(N, source, 1);
    DFS(destination, source, dpre, dpath);
    DFS(destination, source, tpre, tpath);
    if (dpath == tpath) {
        printf("Distance = %d; Time = %d: ", d[destination], t[destination]);
        Print(dpath);
    } else {
        printf("Distance = %d: ", d[destination]);
        Print(dpath);
        printf("\n");
        printf("Time = %d: ", t[destination]);
        Print(tpath);
    }
    return 0;
}