#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 0x7fffffff
using namespace std;

int main() {
    int N, M, pos;
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    cin >> M;
    arr.resize(N + M + 2);
    pos = (N + M - 1) / 2;
    for (int i = 1; i <= M; i++)
        scanf("%d", &arr[i + N]);
    arr[N] = arr[N + M + 1] = MAX; // 防止越界
    int i = 0, j = N + 1, cnt = 0;
    while (cnt < pos) {
        if (arr[i] < arr[j]) {
            i++;
        } else {
            j++;
        }
        cnt++;
    }
    cout << (arr[i] < arr[j] ? arr[i] : arr[j]);
    return 0;
}