#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> coins;
    for (int i = 0, temp = 0; i < N; i++) {
        scanf("%d", &temp);
        coins.push_back(temp);
    }
    sort(coins.begin(), coins.end());
    int left = 0, right = N - 1;
    for (; left <= right;) {
        if (coins[left] + coins[right] > M)
            right--;
        else if (coins[left] + coins[right] < M)
            left++;
        else
            break;
    }
    if (left >= right) // 注意条件
        cout << "No Solution";
    else
        cout << coins[left] << " " << coins[right];
    return 0;
}