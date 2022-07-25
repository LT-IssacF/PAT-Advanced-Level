#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool IsPrime( const int &M ) {
    if( M < 2 )
        return false;
    for( int i = 2; i * i <= M; i++ )
        if( M % i == 0 )
            return false;
    return true;
}

int main( ) {
    int M, N;
    cin >> M >> N;
    while( !IsPrime( M ) )
        M++;
    vector<int> hashTable( M, 0 ), ans( N, -1 );
    for( int i = 0, key = 0, pos = 0; i < N; i++ ) {
        scanf( "%d", &key );
        for( int j = 0, pos = 0; j < M; j++ ) {
            pos = ( key + j * j ) % M; // 平方探测
            if( hashTable[pos] == 0 ) {
                hashTable[pos] = 1;
                ans[i] = pos;
                break;
            }
        }
    }
    printf( "%d", ans[0] );
    for( int i = 1; i < N; i++ )
        if( ans[i] < 0 ) {
            printf( " -" );
        } else {
            printf( " %d", ans[i] );
        }
    return 0;
}
