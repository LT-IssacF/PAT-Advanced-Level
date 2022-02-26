#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main( ) {
    int ans = 0;
    string s;
    cin >> s;
    vector<int> leftP( s.length( ), 0 ); // 统计当前字符左边P的个数
    for( int i = 1; i < s.length( ); i++ )
        leftP[i] = s[i - 1] == 'P' ? leftP[i - 1] + 1 : leftP[i - 1];
    for( int i = s.length( ) - 1, rightT = 0; i >= 0; i-- ) // rightT统计当前字符右边T的个数
        if( s[i] == 'A' ) {
            ans = ( ans + leftP[i] * rightT ) % 1000000007;
        } else if( s[i] == 'T' ) {
            rightT++;
        }
    printf( "%d", ans );
    return 0;
}
