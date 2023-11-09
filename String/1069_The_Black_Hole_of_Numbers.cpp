#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    s.insert(0, 4 - s.length(), '0'); // 注意补零操作
    int bigger, smaller, result;
    do {
        sort(s.begin(), s.end(), [](const char &a, const char &b) { return a > b; });
        bigger = stoi(s);
        sort(s.begin(), s.end());
        smaller = stoi(s);
        result = bigger - smaller;
        printf("%04d - %04d = %04d\n", bigger, smaller, result);
        s = to_string(result);
        s.insert(0, 4 - s.length(), '0');
    } while (result != 6174 && result != 0);
    return 0;
}