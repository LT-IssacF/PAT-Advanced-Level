#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int SumOfDigits(int key) {
    int ans = 0;
    while (key > 0) {
        ans += key % 10;
        key /= 10;
    }
    return ans;
}

bool IsPrime(const int &key) {
    for (int i = 2; i * i <= key; i++)
        if (key % i == 0)
            return false;
    return true;
}

int gcd(const int &a, const int &b) {
    return b == 0 ? a : gcd(b, a % b);
}

void DFS(const string &s, const int &sum, const int &K, const int &m, vector<pair<int, int>> &ans) {
    if (s.size() == K) { // 凑够K位数字了
        if (sum == m) { // K位数字之和等于m
            int a = stoi(s), b = a + 1, n = SumOfDigits(b), d = gcd(m, n); // a是转为int型的A，b是A + 1，n是b的数位之和，d为a与b的最大公因数
            if (d > 2 && IsPrime(d))
                ans.emplace_back(n, a);
        }
        return;
    } else {
        if (sum + (K - s.size()) * 9 >= m) { // 剪枝，当前已确定的数位之和 + 未确定的数位 * 9（即每位都取最大值9）至少要等于m
            for (char c = '0'; c <= '9'; c++) { // 枚举每一位数字
                if (s.size() > 0 || c > '0') // 首位不能是0
                    DFS(s + c, sum + (c - '0'), K, m, ans);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 1, K = 0, m = 0; i <= N; i++) {
        cin >> K >> m;
        cout << "Case " << i << endl;
        vector<pair<int, int>> ans;
        DFS("", 0, K, m, ans);
        if (ans.size() == 0) {
            cout << "No Solution" << endl;
        } else {
            sort(ans.begin(), ans.end(), [](const auto &a, const auto &b) {
                if (a.first != b.first) {
                    return a.first < b.first;
                } else {
                    return a.second < b.second;
                }
            });
            for (const auto &i : ans)
                printf("%d %d\n", i.first, i.second);
        }
    }
    return 0;
}