#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int K;
    string s;
    cin >> K >> s;
    unordered_map<char, bool> m;
    for (int i = 0, j = 0; i < s.length(); i++) {
        if (m.find(s[i]) != m.end() && m[s[i]] == false) // 已经出现过的字符且正常的直接跳过
            continue;
        bool continous = true;
        for (j = i + 1; j < s.length() && j < i + K; j++) { // 判断当前字符是否连续
            if (s[j] != s[i]) {
                continous = false;
                break;
            }
        }
        if (j == s.length() && j - i < K) { // 结尾长度不够导致某个字符连续次数不够说明它也是正常的
            continous = false;
        }
        if (m.find(s[i]) == m.end()) { // 该字符第一次出现
            m[s[i]] = continous;
            if (continous == true) // 如果连续次数够了
                i += K - 1; // i跳过检查中间那些连续的字符
        } else if (continous == false) { // 不是第一次出现且连续次数不够
            m[s[i]] = false; // 那说明这个字符是正常的
        } else { // continous == true
            i += K - 1;
        }
    }
    unordered_map<char, bool> hashTable;
    for (int i = 0; i < s.length(); i++) {
        if (m[s[i]] == true) { // 不正常字符
            if (hashTable[s[i]] == false) { // 第一次出现就输出
                printf("%c", s[i]);
                hashTable[s[i]] = true;
            }
            i += K - 1;
        }
    }
    printf("\n");
    for (int i = 0; i < s.length(); i++) {
        printf("%c", s[i]);
        if (m[s[i]] == true) // 如果是不正常的字符那么跳过连续的那些
            i += K - 1;
    }
    return 0;
}