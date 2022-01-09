#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define MAX 220
using namespace std;
int G[MAX][MAX] = { 0 };

int main( ) {
    int N, M, K;
    cin >> N >> M;
    for( int i = 0, v1 = 0, v2 = 0; i < M; i++ ) {
        scanf( "%d %d", &v1, &v2 );
        G[v1][v2] = G[v2][v1] = 1;
    }
    cin >> K;
    vector<bool> ans( K );
    for( int i = 0, k = 0; i < K; i++ ) {
        bool flag = true, isCycle = true;
        set<int> s;
        scanf( "%d", &k );
        vector<int> temp( k );
        for( int j = 0; j < k; j++ ) {
            scanf( "%d", &temp[j] );
            s.insert( temp[j] );
        }
        // k必需等于N + 1，集合的大小必需等于N，队列首元素必需等于尾元素，三个条件缺一不可
        if( k != N + 1 || s.size( ) != N || temp[0] != temp[k - 1] )
            flag = false;
        if( flag ) {
            for( int j = 0; j < k - 1; j++ ) // 此外还必需走得通
                if( G[temp[j]][temp[j + 1]] != 1 ) {
                    isCycle = false;
                    break;
                }
        }
        ans[i] = flag && isCycle;
    }
    for( int i = 0; i < K; i++ )
        printf( "%s\n", ans[i] ? "YES" : "NO" );
    return 0;
}
