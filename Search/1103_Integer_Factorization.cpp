#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> values, ans, temp;
int maxSumOfFac = 0;
void DFS(const int &N, const int &K, const int &factor, const int &sum, const int &sumOfFac) {
    if (sum > N || temp.size() > K) {
        return;
    } else if (sum == N) {
        if (temp.size() == K && sumOfFac > maxSumOfFac) {
            ans = temp;
            maxSumOfFac = sumOfFac;
        }
        return;
    } else if (factor > 0) {
        temp.push_back(factor); // 选当前的factor
        DFS(N, K, factor, sum + values[factor], sumOfFac + factor);
        temp.pop_back(); // 回溯
        DFS(N, K, factor - 1, sum, sumOfFac); // 不选
    }
}

int main() {
    int N, K, P;
    cin >> N >> K >> P;
    for (int i = 0, value = 0; value < N; i++) {
        value = pow(i, P);
        values.push_back(value);
    }
    DFS(N, K, values.size() - 1, 0, 0);
    if (ans.size() == 0) {
        printf("Impossible");
    } else {
        printf("%d = %d^%d", N, ans[0], P);
        for (int i = 1; i < K; i++)
            printf(" + %d^%d", ans[i], P);
    }
    return 0;
}
// for(int month = 1; month <= 12; ++month) {
//     for(int day = 1; day <= days[month]; ++day) {
//         date = year + 100 * month + day;
//         for(int i = 0; i < 8; ++i)
//             buff[i] = date % 10, date /= 10;
//         for(int i = 1; i < 7; ++i) {
//             if(buff[i] - buff[i + 1] == 1 && buff[i - 1] - buff[i] == 1) {
//                 ++ans;
//                 break;
//             }
//         }
//     }
// }
// int max(int a, int b) { return a > b ? a : b; }

// int main() {
//     scanf("%d", &n);
//     if(n == 1) putchar('1');
//     else for(int i = 1; i <= n; ++i)
//         printf("%d\n", 2 * max(i - 1, n - i));
// }

// for(int i = 1; i <= max(ma, mb); ++i) {
//     S[i] = (ll)(max(1, max(A[i], B[i])) + 1) * S[i - 1] % p;
//     ans = (ans + (ll)S[i - 1] * (A[i] - B[i]) % p + p) % p;
// }

// for(int i = 1; i <= n; ++i) {
//     for(int j = 1; j <= m; ++j) {
//         scanf("%d", &A[i][j]);
//         A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
//     }
// }

// for(int i = 1; i <= n; i++) { // i, j表示上下边界， l，r表示左右边界
//     for(int j = i; j <= n; j++) {
//         for(int l = 1, r = 1, sum = 0; r <= m; r++) {
//             sum += s[j][r] - s[i - 1][r];
//             while(sum > k) {
//                 sum -= s[j][l] - s[i - 1][l];
//                 l++;
//             }
//             res += r - l + 1;
//         }
//     }
// }

// int n, p = 1000000007, dp[10000010] = {1, 1, 2};
// for(int i = 3; i <= n; ++i) {
//     dp[i] = (2ll * dp[i - 1] + dp[i - 3]) % p;
// }

// struct mine {
//     int x, y, r, i;
// } mines[50010], *sorted_byx[50010], *sorted_byy[50010], **xl, **xr, **yl, **yr;

// inline bool cmp_byx(const mine *m1, const mine *m2) { return m1->x < m2->x; }
// inline bool cmp_byy(const mine *m1, const mine *m2) { return m1->y < m2->y; }
// inline bool mine_on_circle(mine *m, int x, int y, int r) { return (long long)(m->x - x) * (m->x - x) + (long long)(m->y - y) * (m->y - y) <= r * r; }

// std::sort(sorted_byx, sorted_byx + n, cmp_byx);
// std::sort(sorted_byy, sorted_byy + n, cmp_byy);
// for(int i = 0; i < m; ++i) {
//     scanf("%d %d %d", &mines[n].x, &mines[n].y, &mines[n].r);
//     queue.push(n);
//     while(queue.size()) {
//         x = mines[queue.front()].x;
//         y = mines[queue.front()].y;
//         r = mines[queue.front()].r, queue.pop();
//         mines[n].x = x - r, xl = std::lower_bound(sorted_byx, sorted_byx + n, &mines[n], cmp_byx);
//         mines[n].y = y - r, yl = std::lower_bound(sorted_byy, sorted_byy + n, &mines[n], cmp_byy);
//         mines[n].x = x + r + 1, xr = std::upper_bound(sorted_byx, sorted_byx + n, &mines[n], cmp_byx);
//         mines[n].y = y + r + 1, yr = std::upper_bound(sorted_byy, sorted_byy + n, &mines[n], cmp_byy);
//         for(; xl < xr; ++xl)
//             if(!visited[(*xl)->i] && mine_on_circle(*xl, x, y, r))
//                 visited[(*xl)->i] = 1, ++ans, queue.push((*xl)->i);
//         for(; yl < yr; ++yl)
//             if(!visited[(*yl)->i] && mine_on_circle(*yl, x, y, r))
//                 visited[(*yl)->i] = 1, ++ans, queue.push((*yl)->i);
//     }
// }

// int n, m, p = 1000000007, dp[101][101][101] = {0, 0, 1};
// for(int i = 0; i <= n; ++i) {
//     for(int j = 0; j < m; ++j) {
//         for(int k = 1; k <= m; ++k) {
//             if(i && k % 2 == 0) dp[i][j][k] = dp[i - 1][j][k / 2];
//             if(j) dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k + 1]) % p;
//         }
//     }
// }

// struct Node {
//     int l, r;
//     long long h;
//     Node(int l1, int r1, long long h1) : l(l1), r(r1), h(h1) {}
//     inline bool operator<(const Node &n) const { return h == n.h ? l > n.l : h < n.h; }
// };

// std::priority_queue<Node> q;

// while(q.size()) {
//     if(q.top().h == 1) break;
//     Node now = q.top();
//     q.pop();
//     while(q.size() && q.top().h == now.h && q.top().l == now.r + 1)
//         now.r = q.top().r, q.pop();
//     ++ans;
//     now.h = sqrt(now.h / 2 + 1);
//     if(now.h > 1) q.push(now);
// }