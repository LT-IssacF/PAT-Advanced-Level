#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K;
    cin >> K;
    vector<int> arr(K);
    bool flag = false;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        if (arr[i] >= 0)
            flag = true;
    }
    if (!flag) // 序列全为负值
        cout << "0 " << arr[0] << " " << arr[K - 1];
    else { // 状态转移方程：dp[i] = max{ arr[i] + dp[i - 1], arr[i] }
        vector<int> dp(K), start(K); // start数组用以记录最大子序列开始的位置
        fill(start.begin(), start.end(), 0);
        dp[0] = arr[0]; // 边界
        for (int i = 1; i < K; i++) { // 求解dp数组
            if (dp[i - 1] + arr[i] > arr[i]) { // 将第i个元素加入子序列能使和增大
                dp[i] = dp[i - 1] + arr[i];
                start[i] = start[i - 1]; // 它们都有共同的开始元素
            } else { // 第i个元素单独为一个子序列
                dp[i] = arr[i];
                start[i] = i; // 自己位置就是开始的位置
            }
        }
        int endPos = 0;
        for (int i = 1; i < K; i++) {
            if (dp[i] > dp[endPos]) {
                endPos = i;
            }
        }
        cout << dp[endPos] << " " << arr[start[endPos]] << " " << arr[endPos];
    }
    return 0;
}