// #include <cstdio>
// #include <iostream>
// #include <string>
// #define MAX 0x7f
// using namespace std;
// struct bign {
//     int d[MAX] = {0}, len = 0;
//     bool positive = true;
// }; // 默认为正数0
// bign Change(const string &t) {
//     bign ans;
//     int end = 0;
//     if (t[0] == '-') { // 负数
//         ans.positive = false;
//         end++;
//     }
//     for (int i = t.length() - 1; i >= end; i--) {
//         ans.d[ans.len++] = t[i] - '0';
//     }
//     return ans;
// }

// bign Add(const bign &a, const bign &b) {
//     bign ans;
//     int carry = 0;
//     for (int i = 0, temp = 0; i < a.len || i < b.len; i++) {
//         temp = a.d[i] + b.d[i] + carry;
//         ans.d[ans.len++] = temp % 10;
//         carry /= 10;
//     }
//     if (carry != 0)
//         ans.d[ans.len++] = carry;
//     return ans;
// }

// bign Minus(bign &a, bign &b) {
//     bign ans;
//     for (int i = 0; i < a.len || i < b.len; i++) {
//         if (a.d[i] < b.d[i]) {
//             a.d[i] += 10;
//             a.d[i - 1]--;
//         }
//         ans.d[ans.len++] = a.d[i] - b.d[i];
//     }
//     while (ans.d[ans.len - 1] == 0 && ans.len > 1) {
//         ans.len--;
//     }
//     return ans;
// }
//   // 比较绝对值
// int Compare(const bign &a, const bign &b) {
//     if (a.len > b.len) {
//         return 1;
//     } else if (a.len < b.len) {
//         return -1;
//     } else {
//         for (int i = a.len - 1; i >= 0; i--) { // 注意是从高位往低位比
//             if (a.d[i] > b.d[i]) {
//                 return 1;
//             } else if (a.d[i] < b.d[i]) {
//                 return -1;
//             }
//         }
//         return 0;
//     }
// }

// int main() {
//     int T;
//     cin >> T;
//     for (int i = 1; i <= T; i++) {
//         string ta, tb, tc;
//         cin >> ta >> tb >> tc;
//         bign a = Change(ta), b = Change(tb), c = Change(tc), ans;
//         if (a.positive == b.positive) { // 两数符号相同
//             ans = Add(a, b);
//             if (!a.positive) { // 两个负数相加
//                 ans.positive = false;
//             }
//         } else { // 两数符号不同
//             if (Compare(a, b) == 1) { // a的绝对值大于b
//                 ans = Minus(a, b);
//                 if (!a.positive) { // 结果是负的
//                     ans.positive = false;
//                 }
//             } else if (Compare(a, b) == -1) { // b的绝对值大于a
//                 ans = Minus(b, a);
//                 if (!b.positive) { // 结果是负的
//                     ans.positive = false;
//                 }
//             }
//         }
//         printf("Case #%d: ", i);
//         if (ans.positive == c.positive) { // 符号相同
//             if (ans.positive) { // 都是正数则正常比
//                 cout << (Compare(ans, c) == 1 ? "true" : "false") << endl;
//             } else { // 负数相比绝对值大的反而小
//                 cout << (Compare(ans, c) == -1 ? "true" : "false") << endl;
//             }
//         } else { // 符号不同
//             cout << (ans.positive ? "true" : "false") << endl;
//         }
//     }
//     return 0;
// }

#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if (a > 0 && b > 0 && sum < 0) {
            printf("Case #%d: true\n", i + 1);
        } else if (a < 0 && b < 0 && sum >= 0) {
            printf("Case #%d: false\n", i + 1);
        } else if (sum > c) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}