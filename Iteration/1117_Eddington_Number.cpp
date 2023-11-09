#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, ans = 0;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end(), [](const int &a, const int &b) { return a > b; });
    // 骑车距离大于等于arr[i]的天数有i + 1天，所以骑车距离大于arr[i] - 1的有i + 1天
    while (ans < N && arr[ans] > ans + 1)
        ans++;
    cout << ans;
    return 0;
} // 10 9 8 8 7 7 7 6 6 3