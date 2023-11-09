#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
bool IsSame(const int &N, const int *initial, const int *outcome) {
    for (int i = 0; i < N; i++)
        if (initial[i] != outcome[i])
            return false;
    return true;
}

void Print(const int &N, const int *outcome) {
    printf("%d", outcome[0]);
    for (int i = 1; i < N; i++)
        printf(" %d", outcome[i]);
}

int main() {
    int N, initial[120] = {0}, outcome[120] = {0};
    cin >> N;
    ;
    for (int i = 0; i < N; i++)
        scanf("%d", &initial[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &outcome[i]);
    bool flag = false;
    for (int i = 1, j = 1, MIN = 0; i < N && flag == false; i++) { // 大小为N的数组最多插入N - 1次
        flag = i > 1 && IsSame(N, initial, outcome);
        for (j = i, MIN = initial[i]; j > 0 && initial[j - 1] > MIN; j--)
            initial[j] = initial[j - 1];
        initial[j] = MIN;
    } // 先试插入排序，如果某次插入完了发现相同了，那再进行一次插入就能直接输出了
    if (flag == true) {
        printf("Insertion Sort\n");
        Print(N, initial);
    } else { // 只能是归并排序了
        printf("Merge Sort\n");
        for (int i = 0; i < N; i++)
            initial[i] = outcome[i]; // 利用给的第二个数组直接排序
        for (int pace = 2; flag == false; pace *= 2) { // 步长从2开始
            for (int i = 0; i < N; i += pace) // 给每一块排序
                sort(outcome + i, outcome + min(i + pace, N)); // 注意最后一块
            flag = !IsSame(N, initial, outcome); // 当数组不同时就是结果
        }
        Print(N, outcome);
    }
    return 0;
}