#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> values, ans, temp;
int maxSumOfFac = 0;
void DFS( const int &N, const int &K, const int &factor, const int &sum, const int &sumOfFac ) {
    if( sum > N || temp.size( ) > K ) {
        return;
    } else if( sum == N ) {
        if( temp.size( ) == K && sumOfFac > maxSumOfFac ) {
            ans = temp;
            maxSumOfFac = sumOfFac;
        }
        return;
    } else if( factor > 0 ) {
        temp.push_back( factor ); // 选当前的factor
        DFS( N, K, factor, sum + values[factor], sumOfFac + factor );
        temp.pop_back( ); // 回溯
        DFS( N, K, factor - 1, sum, sumOfFac ); // 不选
    }
}

int main( ) {
    int N, K, P;
    cin >> N >> K >> P;
    for( int i = 0, value = 0; value < N; i++ ) {
        value = pow( i, P );
        values.push_back( value );
    }
    DFS( N, K, values.size( ) - 1, 0, 0 );
    if( ans.size( ) == 0 ) {
        printf( "Impossible" );
    } else {
        printf( "%d = %d^%d", N, ans[0], P );
        for( int i = 1; i < K; i++ )
            printf( " + %d^%d", ans[i], P );
    }
    return 0;
}
