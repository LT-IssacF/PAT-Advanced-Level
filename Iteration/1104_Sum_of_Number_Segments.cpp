#include <cstdio>
#include <iostream>
using namespace std;

// int main() {
//     int N;
//     cin >> N;
//     double value, ans = 0;
//     vector<vector<double>> d(N, vector<double>(1, 0)); // 二维数组，边界为0
//     for (int i = 0; i < N; i++) {
//         scanf("%lf", &value);
//         for (int j = 0; j <= i; j++) // 前n项和
//             d[j].push_back(d[j][i - j] + value);
//     }
//     // 0.1  0.1 + 0.2  0.1 + 0.2 + 0.3  0.1 + 0.2 + 0.3 + 0.4
//     // 0.2  0.2 + 0.3  0.2 + 0.3 + 0.4
//     // 0.3  0.3 + 0.4
//     // 0.4
//     for (const auto &i : d)
//         for (const auto &j : i)
//             ans += j;
//     printf("%.2lf", ans);
//     return 0;
// }

int main() {
    int N;
    cin >> N;
    double value, ans = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%lf", &value);
        ans += value * (i * (N - i + 1));
    } // ans += value * ( 会出现的层数 * ( 每层出现的个数 ) )
    // 0.1  4
    // 0.2  3 + 3
    // 0.3  2 + 2 + 2
    // 0.4  1 + 1 + 1 + 1
    printf("%.2lf", ans);
    return 0;
}