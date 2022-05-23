#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main( ) {
    ll N, first = 0, len = 0; // first记录连续因数的起点，len记录长度
    cin >> N;
    ll maxn = sqrt( N ) + 1; // N最大只能被根号N以内的因数整除
    for( ll i = 2, j = 2, product = 1; i <= maxn; i++ ) { // 枚举起点i
        for( j = i, product = 1; j <= maxn; j++ ) {
            product *= j;
            if( N % product != 0 ) // 在能被整除的条件下不断连乘
                break;
        }
        if( j - i > len ) { // j是终点，j - i就是长度，更长的连续因数
            first = i; // 更新起点和长度
            len = j - i;
        }
    }
    if( first == 0 ) { // 如果起点没有变过就说明N没有除1以外的因素即质数
        cout << 1 << endl << N; // 输出他自己
    } else {
        cout << len << endl << first;
        for( int i = 1; i < len; i++ )
            cout << "*" << first + i;
    }
    return 0;
}
