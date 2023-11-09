#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> ans, temp; // temp暂时保存结果
bool flag = false; // 标记是否已找到结果
void DFS(const int &now, const int &total, const int &N, const int &M, const vector<int> &coins) {
    if (total == M) { // 第一个结果
        ans = temp;
        flag = true;
        return;
    } else if (now == N || total > M || flag) { // 已经到硬币边界或总面值已大于或已有结果
        return;
    }
    temp.push_back(coins[now]); // 由小到大选面值保证结果正确性
    DFS(now + 1, total + coins[now], N, M, coins); // 选这枚硬币
    temp.pop_back();
    DFS(now + 1, total, N, M, coins); // 不选这枚硬币
}

int main() {
    int N, M, sum = 0; // sum的设置纯粹是为了防止最后一个测试点超时
    cin >> N >> M;
    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &coins[i]);
        sum += coins[i];
    }
    if (sum < M) {
        printf("No Solution");
    } else {
        sort(coins.begin(), coins.end()); // 排序保证结果的正确性
        DFS(0, 0, N, M, coins);
        if (ans.size() == 0) {
            printf("No Solution");
        } else {
            printf("%d", ans[0]);
            for (int i = 1; i < ans.size(); i++)
                printf(" %d", ans[i]);
        }
    }
    return 0;
}