#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> sum(N + 1, 0); // sum[i]表示从1到i + 1的顺时针距离
    for (int i = 1, distance = 0, total = 0; i <= N; i++) {
        scanf("%d", &distance);
        total += distance;
        sum[i] = total;
    } // sum[N]表示一圈的距离
    cin >> M;
    for (int i = 0, v1 = 0, v2 = 0; i < M; i++) {
        scanf("%d %d", &v1, &v2);
        printf("%d\n", min(abs(sum[v2 - 1] - sum[v1 - 1]), sum[N] - (abs(sum[v2 - 1] - sum[v1 - 1]))));
    } // 比顺时针距离与逆时针距离谁短
    return 0;
}