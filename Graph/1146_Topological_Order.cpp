#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int in_degree; // 入度
    queue<int> out_degree; // 连向的结点
};
bool Check( vector<node> G, const int &N ) {
    bool flag = true;
    for( int i = 0, v1 = 0, v2 = 0; i < N; i++ ) {
        scanf( "%d", &v1 );
        if( G[v1].in_degree != 0 ) {
            flag = false; // 如果当前访问的结点v1的入度不为0就不符合拓扑排序的特点
        } else {
            while( !G[v1].out_degree.empty( ) ) { // 处理v1连向的所有结点
                v2 = G[v1].out_degree.front( );
                G[v1].out_degree.pop( ); // 消除边
                G[v2].in_degree--; // v2的度-1
            }
        }
    }
    return flag;
}

int main( ) {
    int N, M, K;
    cin >> N >> M;
    vector<node> G( N + 1 );
    for( int i = 0, v1 = 0, v2 = 0; i < M; i++ ) {
        scanf( "%d %d", &v1, &v2 );
        G[v1].out_degree.push( v2 );
        G[v2].in_degree++;
    }
    cin >> K;
    bool flag = false;
    for( int i = 0; i < K; i++ )
        if( !Check( G, N ) ) {
            if( flag )
                printf( " " );
            printf( "%d", i );
            flag = true;
        }
    return 0;
}
