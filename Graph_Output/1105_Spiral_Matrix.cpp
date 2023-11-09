#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int rows, columns = sqrt(N);
    while (N % columns != 0)
        columns--;
    rows = N / columns;
    vector<vector<int>> ans(rows, vector<int>(columns));
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end(), [](const int &a, const int &b) { return a > b; });
    int rounds = rows / 2 + rows % 2, it = 0; // 轮数，每一轮顺时针填一圈数字，形状如衔尾蛇
    for (int i = 0; i < rounds; i++) {
        for (int j = i; j < columns - i && it < N; j++)
            ans[i][j] = arr[it++];
        for (int j = i + 1; j < rows - i - 1 && it < N; j++)
            ans[j][columns - i - 1] = arr[it++];
        for (int j = columns - i - 1; j > i - 1 && it < N; j--)
            ans[rows - i - 1][j] = arr[it++];
        for (int j = rows - i - 2; j > i && it < N; j--)
            ans[j][i] = arr[it++];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (j > 0)
                printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}