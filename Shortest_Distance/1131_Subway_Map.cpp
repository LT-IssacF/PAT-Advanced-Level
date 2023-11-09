#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<vector<int>> station(10000, vector<int>());
unordered_map<int, int> line;
unordered_map<int, bool> visit;
vector<int> tmpStop, ansStop;
int minStopCnt = 0x7fffffff, minTransferCnt = 0x7fffffff;
int GetTransferCnt() {
    int ans = -1;
    for (int i = 1, pre = 0, now = 0, preLine = 0, nowLine = 0; i < tmpStop.size(); i++) {
        pre = tmpStop[i - 1], now = tmpStop[i], nowLine = line[pre * 10000 + now];
        if (nowLine != preLine) {
            ans++;
            preLine = nowLine;
        }
    }
    return ans;
}

void DFS(const int &now, const int &dest, const int &stopCnt) {
    if (now != dest) {
        if (stopCnt < minStopCnt) {
            visit[now] = true;
            tmpStop.push_back(now);
            for (const int &i : station[now]) {
                if (visit[i] == false) {
                    DFS(i, dest, stopCnt + 1);
                }
            }
            visit[tmpStop.back()] = false;
            tmpStop.pop_back();
        }
    } else {
        if (stopCnt < minStopCnt) {
            ansStop = tmpStop;
            ansStop.push_back(now);
            minStopCnt = stopCnt;
            minTransferCnt = GetTransferCnt();
        } else if (stopCnt == minStopCnt) {
            int transferCnt = GetTransferCnt();
            if (transferCnt < minTransferCnt) {
                ansStop = tmpStop;
                ansStop.push_back(now);
                minTransferCnt = transferCnt;
            }
        }
    }
}

int main() {
    int N, K;
    cin >> N;
    for (int i = 1, M = 0, pre = 0; i <= N; i++) {
        scanf("%d %d", &M, &pre);
        for (int j = 1, now = 0; j < M; j++) {
            scanf("%d", &now);
            station[pre].push_back(now), station[now].push_back(pre);
            line[pre * 10000 + now] = line[now * 10000 + pre] = i;
            pre = now;
        }
    }
    cin >> K;
    for (int i = 0, j = 1, start = 0, dest = 0, preLine = 0, nowLine = 0; i < K; i++) {
        scanf("%d %d", &start, &dest);
        tmpStop.clear(), ansStop.clear();
        visit.clear();
        minStopCnt = 0x7fffffff, minTransferCnt = 0x7fffffff;
        DFS(start, dest, 1);
        cout << minStopCnt - 1 << endl;
        preLine = line[ansStop[0] * 10000 + ansStop[1]];
        for (j = 1; j < ansStop.size(); j++) {
            nowLine = line[ansStop[j] * 10000 + ansStop[j - 1]];
            if (preLine != nowLine) {
                printf("Take Line#%d from %d to %d.\n", preLine, start, ansStop[j - 1]);
                preLine = nowLine;
                start = ansStop[j - 1];
            }
        }
        printf("Take Line#%d from %d to %d.\n", nowLine, start, ansStop[j - 1]);
    }
    return 0;
}