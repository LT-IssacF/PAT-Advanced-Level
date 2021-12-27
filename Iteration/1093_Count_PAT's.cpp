#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main( ) {
    string s;
    cin >> s;
    int length = s.length( ), rightT = 0, ans = 0; // rightT统计当前字符右边T的个数
    vector<int> leftP( length ); // 统计当前字符左边'P'的个数
    leftP[0] = 0; // 边界
    for( int i = 1; i < length; i++ )
        leftP[i] = ( s[i - 1] == 'P' ) ? leftP[i - 1] + 1 : leftP[i - 1];
    for( int i = length - 1; i >= 0; i-- ) {
        if( s[i] == 'T' )
            rightT++;
        else if( s[i] == 'A' )
            ans = ( ans + leftP[i] * rightT ) % 1000000007;
    }
    cout << ans;
    return 0;
}
