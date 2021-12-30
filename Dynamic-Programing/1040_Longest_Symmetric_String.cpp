#include <iostream>
#include <cstdio>
#include <string>
#define MAX 1020
using namespace std;

int main( ) {
    string s;
    getline( cin , s );
    int length = s.length( ), ans = 1;
    bool dp[MAX][MAX] = { false }; // dp[i][j]表示从第i个字符到第j个字符是否是回文字符串
    /* dp[i][j] = { dp[i + 1][j - 1], s[i] == s[j]
                    false, s[i] != s[j] } */
    for( int i = 0; i < length; i++ ) { // 每个字符都是一个长度为1的回文字符串
        dp[i][i] = true;
        if( i < length - 1 ) {
            if( s[i] == s[i + 1] ) { // 检查长度为2的字符串
                dp[i][i + 1] = true;
                ans = 2;
            }
        }
    }
    for( int span = 3; span <= length; span++ ) { // 字符串长度从3开始枚举
        for( int i = 0, j = span - 1; j < length; i++, j++ ) { // 检查s中每个长度为span的字符串
            if( s[i] == s[j] && dp[i + 1][j - 1] ) { // 根据状态转移方程
                dp[i][j] = true;
                ans = span;
            }
        }
    }
    cout << ans;
    return 0;
}
