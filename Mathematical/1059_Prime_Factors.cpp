#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct factor {
    int value, cnt;
};
vector<factor> ans;
vector<int> primes;
void FindPrime( const int &border ) {
    for( int i = 2; i <= border; i++ ) {
        bool flag = true;
        for( int j = 2; j <= sqrt( i ); j++ ) {
            if( i % j == 0 ) {
                flag = false;
                break;
            }
        }
        if( flag )
            primes.push_back( i );
    }
}

void FindFactors( int N ) {
    for( int i = 0, cnt = 0; i < primes.size( ) && N > 1; i++ ) {
        cnt = 0;
        while( N % primes[i] == 0 ) {
            cnt++;
            N /= primes[i];
        }
        if( cnt > 0 )
            ans.emplace_back( factor{ primes[i], cnt } );
    }
    if( N != 1 ) // 如果无法被根号N以内的质因子除尽
        ans.emplace_back( factor{ N, 1 } ); // 那么就有一个大于根号N的质因子
}

int main( ) {
    long N;
    scanf( "%ld", &N );
    if( N == 1 ) {
        printf( "1=1" );
    } else {
        FindPrime( sqrt( N ) ); // 64位的数据找32位以内的质数就够了
        FindFactors( N );
        printf( "%ld=%d", N, ans[0].value );
        if( ans[0].cnt > 1 )
            printf( "^%d", ans[0].cnt );
        for( int i = 1; i < ans.size( ); i++ ) {
            printf( "*%d", ans[i].value );
            if( ans[i].cnt > 1 )
                printf( "^%d", ans[i].cnt );
        }
    }
    return 0;
}
