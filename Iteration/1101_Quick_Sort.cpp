#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
// leftBigger[i]表示第i个数左边有没有比它更大的数，rightSmaller同理
int main() {
    int N;
    cin >> N;
    vector<int> arr(N), ans;
    vector<bool> leftBigger(N, false), rightSmaller(N, false); // 边界leftBigger[0]和rightSmaller[N - 1]都为false
    for (int i = 0, MAX = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > MAX) { // 当前数比左边的数都大
            MAX = arr[i]; // leftBigger[i] = false
        } else { // 左边有比当前数更大的数
            leftBigger[i] = true;
        }
    }
    for (int i = N - 1, MIN = 0x7fffffff; i >= 0; i--) {
        if (MIN > arr[i]) { // 当前数比右边的数都小
            MIN = arr[i]; // rightSmaller[i] = false
        } else { // 右边有比当前数更小的数
            rightSmaller[i] = true;
        }
        if (leftBigger[i] == false && rightSmaller[i] == false)
            ans.push_back(arr[i]);
    }
    if (ans.size() == 0) {
        printf("0\n\n");
    } else {
        sort(ans.begin(), ans.end());
        printf("%d\n%d", ans.size(), ans[0]);
        for (int i = 1; i < ans.size(); i++)
            printf(" %d", ans[i]);
    }
    return 0;
}