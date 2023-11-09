#include <cstdio>
#include <iostream>
#include <unordered_set>
using namespace std;
int G[201][201] = {0};

int main() {
    int N, M, K, shortestIndex = 0, shortestDis = 0x7fffffff;
    cin >> N >> M;
    for (int i = 0, v = 0, v2 = 0, dis = 0; i < M; i++) {
        scanf("%d %d %d", &v, &v2, &dis);
        G[v][v2] = G[v2][v] = dis;
    }
    cin >> K;
    for (int i = 1, n = 0, v = 0, v2 = 0; i <= K; i++) {
        scanf("%d %d", &n, &v);
        unordered_set<int> cities; // 判断是否访问了每个城市
        int totalDis = 0, start = v; // 记下起点城市
        for (int j = 1; j < n; j++) {
            cities.insert(v);
            scanf("%d", &v2);
            if (G[v][v2] == 0) { // 走不通
                totalDis = -1;
            } else if (totalDis >= 0) {
                totalDis += G[v][v2];
            }
            v = v2;
        }
        if (totalDis < 0) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
        } else if (cities.size() == N && start == v2) { // 每个城市都访问了且回到了起点，无论是否走没走弯路
            if (totalDis < shortestDis) {
                shortestDis = totalDis;
                shortestIndex = i;
            }
            if (n == N + 1) { // 没走弯路
                printf("Path %d: %d (TS simple cycle)\n", i, totalDis);
            } else { // 走弯路
                printf("Path %d: %d (TS cycle)\n", i, totalDis);
            }
        } else { // 没访问所有城市或者没回到起点
            printf("Path %d: %d (Not a TS cycle)\n", i, totalDis);
        }
    }
    printf("Shortest Dist(%d) = %d", shortestIndex, shortestDis);
    return 0;
}