#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, minLen = 0x3fffffff;
    cin >> N;
    getchar();
    vector<string> v;
    string str, ans;
    for (int i = 0; i < N; i++) {
        getline(cin, str);
        reverse(str.begin(), str.end()); // 将字符串逆转处理
        v.emplace_back(str);
        if (minLen > str.length()) // 记下最短字符串长度
            minLen = str.length();
    }
    for (int i = 0; i < minLen && v[0][i] == v[1][i]; i++)
        ans += v[0][i]; // 先求出前两个字符串的最短相同后缀
    for (int i = 2, j = 0; i < v.size(); i++) {
        for (j = 0; j < ans.length() && ans[j] == v[i][j]; j++)
            ;
        if (j < minLen) // 缩短相同后缀
            ans.erase(j, ans.length() - j);
    }
    reverse(ans.begin(), ans.end());
    cout << (ans.size() > 0 ? ans : "nai");
    return 0;
}