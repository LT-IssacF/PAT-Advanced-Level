#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, p, cnt = 0;
    cin >> N >> p;
    vector<long long> seq(N);
    for (int k = 0; k < N; k++)
        scanf("%d", &seq[k]);
    sort(seq.begin(), seq.end());
    // i，j枚举左右端点，seq[i]作为m，seq[j]作为M
    for (int i = 0, j = 0; i + cnt < N; i++) {
        j = i + cnt; // j不回溯，如例子中第一轮循环完cnt为8，那么第二轮开始j应枚举为9
        while (j < N && seq[i] * p >= seq[j]) { // 第二轮循环只有当seq[1]*p>=seq[9]时长度才能比第一轮的8大
            cnt++;
            j++;
        }
    }
    cout << cnt;
    return 0;
}