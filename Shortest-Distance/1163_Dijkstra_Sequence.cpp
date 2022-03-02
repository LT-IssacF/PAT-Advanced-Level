#include <iostream>
#include <cstdio>
#include <vector>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, dis;
};
vector<vector<node>> G;
vector<int> d, choices; // choices用来记录每步新找到最近的结点的距离
vector<bool> visit;
void Dijkstra( const int &N, const int &start ) {
    fill( d.begin( ), d.end( ), INF );
    fill( visit.begin( ), visit.end( ), false );
    d[start] = 0;
    for( int i = 0; i < N; i++ ) {
        int u = -1, MIN = INF;
        for( int j = 1; j <= N; j++ )
            if( d[j] < MIN && visit[j] == false ) {
                u = j;
                MIN = d[j];
            }
        if( u == -1 )
            break;
        visit[u] = true;
        choices.push_back( MIN ); // 距离相等的情况下就编号就不一定一样了，所以得用距离来判断
        for( int j = 0, v = 0; j < G[u].size( ); j++ ) {
            v = G[u][j].v;
            if( visit[v] == false && d[u] + G[u][j].dis < d[v] ) {
                d[v] = G[u][j].dis + d[u];
            }
        }
    }
}
// 进行Dijkstra算法时，每一步都会选取一个当前距离起始结点最近且未访问的结点来更新最短距离，本题就是来判断给出的序列是不是求出最短距离的序列
int main( ) {
    int N, M, K;
    cin >> N >> M;
    G.resize( N + 1 );
    d.resize( N + 1 );
    visit.resize( N + 1 );
    for( int i = 0, v = 0, v2 = 0, dis = 0; i < M; i++ ) {
        scanf( "%d %d %d", &v, &v2, &dis );
        G[v].emplace_back( node{ v2, dis } );
        G[v2].emplace_back( node{ v, dis } );
    }
    cin >> K;
    for( int i = 0, start = 0; i < K; i++ ) {
        scanf( "%d", &start );
        choices.clear( );
        Dijkstra( N, start );
        bool ans = true;
        for( int j = 1, v = 0; j < N; j++ ) {
            scanf( "%d", &v );
            if( d[v] != choices[j] ) // 由于可能有多条最短路径，所以要用距离来判断
                ans = false;
        }
        printf( "%s\n", ans ? "Yes" : "No" );
    }
    return 0;
}
