#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// int main() {
//     int N, cnt = 0, ans = 0;
//     cin >> N;
//     vector<int> pos(N); // pos[i] = j表示i在数组第j个位置上
//     for (int i = 0, value = 0; i < N; i++) {
//         scanf("%d", &value);
//         pos[value] = i;
//         if (value != 0 && pos[value] != value) // 记录除0之外不在自己本位上的数
//             cnt++;
//     }
//     int minimal = 1; // 已调好位置的最小数字
//     while (cnt > 0) {
//         if (pos[0] == 0) { // 0在本位上
//             while (pos[minimal] == minimal) // 找最小不在自己本位上的数
//                 minimal++;
//             swap(pos[0], pos[minimal]); // 与0交换位置
//             ans++;
//         } else { // 正常交换
//             swap(pos[0], pos[pos[0]]);
//             ans++;
//             cnt--;
//         }
//     }
//     cout << ans;
//     return 0;
// }

int main() {
    int N, ans = 0;
    cin >> N;
    vector<int> pos(N);
    for (int i = 0, value = 0; i < N; i++) {
        scanf("%d", &value);
        pos[value] = i; // pos[i] = j表示i在数组第j个位置上
    }
    for (int i = 1; i < N; i++) {
        while (pos[0] != 0) { // 一直交换直到0换到本位为止
            swap(pos[0], pos[pos[0]]);
            ans++;
        } // 0在本位了
        if (i != pos[i]) { // 如果还有数不在自己本位上就和0交换
            swap(pos[0], pos[i]);
            ans++;
        }
    }
    cout << ans;
    return 0;
}