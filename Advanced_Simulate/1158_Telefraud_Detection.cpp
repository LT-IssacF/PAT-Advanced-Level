#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
int father[0x3ff] = {0};
int FindFather(int key) {
    int x = key;
    while (key != father[key])
        key = father[key];
    while (x != father[x]) {
        int a = x;
        x = father[x];
        father[a] = key;
    }
    return key;
}

void Union(const int &a, const int &b) {
    int faA = FindFather(a), faB = FindFather(b);
    if (faA < faB) { // 序号小的当父亲
        father[faB] = faA;
    } else if (faA > faB) {
        father[faA] = faB;
    }
}

int main() {
    int K, N, M;
    cin >> K >> N >> M;
    vector<vector<int>> G(N + 1, vector<int>(N + 1, 0)); // 邻接矩阵，用以记录累积的时长
    vector<set<int>> relations(N + 1); // 记录通话记录，减少查找次数
    for (int i = 1, a = 0, b = 0, time = 0; i <= M; i++) {
        scanf("%d %d %d", &a, &b, &time);
        G[a][b] += time;
        relations[a].insert(b);
    }
    vector<int> suspects;
    unordered_map<int, bool> visit; // 标记是否已输出
    for (int i = 1; i <= N; i++) {
        int harassments = 0, callBack = 0;
        for (const auto &j : relations[i]) {
            if (G[i][j] <= 5) { // 骚扰电话
                harassments++;
                if (G[j][i] > 0) // 但是有回拨
                    callBack++;
            }
        }
        if (harassments > K && callBack * 5 <= harassments) {
            suspects.push_back(i);
            visit.insert({i, false});
        }
    }
    if (suspects.size() == 0) {
        printf("None");
    } else {
        for (const auto i : suspects) // 初始化并查集
            father[i] = i;
        for (const auto &i : suspects)
            for (const auto &j : suspects)
                if (i != j && (G[i][j] > 0 && G[j][i] > 0))
                    Union(i, j);
        for (int i = 0; i < suspects.size(); i++)
            if (visit[suspects[i]] == false) {
                visit[suspects[i]] = true;
                printf("%d", suspects[i]);
                for (int j = i + 1; j < suspects.size(); j++)
                    if (visit[suspects[j]] == false && FindFather(suspects[j]) == suspects[i]) {
                        visit[suspects[j]] = true;
                        printf(" %d", suspects[j]);
                    }
                printf("\n");
            }
    }
    return 0;
}