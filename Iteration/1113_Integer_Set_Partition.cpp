#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
// 智商检测题
int main() {
    int N, ans1, ans2;
    cin >> N;
    vector<int> arr(N), sum(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    sum[0] = arr[0];
    for (int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + arr[i];
    ans1 = N % 2 == 0 ? 0 : 1;
    ans2 = sum[N - 1] - 2 * sum[N / 2 - 1];
    cout << ans1 << " " << ans2;
    return 0;
}