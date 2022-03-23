#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main( ){
    int K;
    cin >> K;
    for( int i = 0, N = 0; i < K; i++ ) {
        scanf( "%d", &N );
        vector<int> chessboard( N + 1, -1 );
        set<int> s; // 判断是否有皇后在同一行，题目明确说明不会有在同一列的
        bool ans = true;
        for( int j = 1; j <= N; j++ ) {
            scanf( "%d", &chessboard[j] );
            s.insert( chessboard[j] );
            if( abs( chessboard[j] - chessboard[j - 1] ) == 1 ) // 相邻列皇后在相邻行即在斜对角线上
                ans = false;
        }
        printf( "%s\n", ( s.size( ) == N && ans ) ? "YES" : "NO" );
    }
    return 0;
}
