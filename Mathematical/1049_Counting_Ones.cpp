#include <iostream>
using namespace std;

int main( ) {
    int N, ans = 0;
    cin >> N;
    for( int exponent = 1, left = 0, now = 0, right = 0; N / exponent != 0; exponent *= 10 ) {
        left = N / exponent / 10; // 当前处理位左边高位的数
        now = N / exponent % 10; // 当前处理位的数
        right = N % exponent; // 当前处理位右边低位的数
        if( now == 0 ) { // 左边高位的数可以取从0~left-1共left个数，now取1，右边低位的数可以取从0到exponent-1共exponent个数
            ans += left * exponent;
        } else if( now == 1 ) { // 先计算左边高位取从0~left-1共left个数的情况，方法同上，再加上左边高位取left的情况，此时右边低位可以取1+right个数（因为now取1，right取任何数都可以）
            ans += left * exponent + ( 1 + right );
        } else { // 左边高位可以取从0~left共left+1个数，now取1，右边低位可以取从0到exponent-1共exponent个数
            ans += ( left + 1 ) * exponent;
        } // now > 1
    }
    cout << ans;
    return 0;
}
