#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, L;
    cin >> N >> M;
    vector<int> hashTable(N + 1);
    fill(hashTable.begin(), hashTable.end(), -1); // 初始化
    for (int i = 0, tag = 0; i < M; i++) { // 喜欢的颜色映射到哈希表里，并排序
        cin >> tag;
        hashTable[tag] = i;
    }
    cin >> L;
    vector<int> arr;
    for (int i = 0, color = 0; i < L; i++) {
        cin >> color;
        if (hashTable[color] != -1) { // 只记录喜欢的颜色
            arr.push_back(hashTable[color]);
        }
    }
    int cnt = arr.size(), ans = -1;
    vector<int> dp(cnt);
    /* 状态转移方程：dp[i] = max{ dp[j] + 1, 1 } ( j < i, j = 0, 1, 2, ..., i - 1 )
    dp[i] = { dp[j] + 1( arr[j] <= arr[i], j < i );
              1( arr[j] > arr[i], j < i ) } */
    for (int i = 0, j = 0; i < cnt; i++) {
        dp[i] = 1; // 采用的LIS模型，即最长增长子序列
        for (j = 0; j < i; j++) {
            if (arr[j] <= arr[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}