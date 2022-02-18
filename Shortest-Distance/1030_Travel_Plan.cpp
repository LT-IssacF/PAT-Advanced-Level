#include <iostream>
#include <cstdio>
#include <vector>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, dis, cost;
    node( const int &v2, const int &dis2, const int &cost2 ) : v( v2 ), dis( dis2 ), cost( cost2 ) { }
};
vector<vector<node>> G;
vector<int> d, cost, pre; // 因为只有唯一一条路径，所以前驱数组用一维的就行
vector<bool> visit;
void Dijkstra( const int &start, const int &N ) {
    fill( d.begin( ), d.end( ), INF );
    fill( cost.begin( ), cost.end( ), INF );
    fill( visit.begin( ), visit.end( ), false );
    d[start] = cost[start] = 0;
    for( int i = 0; i < N; i++ ) {
        int u = -1, min = INF;
        for( int j = 0; j < N; j++ )
            if( d[j] < min && visit[j] == false ) {
                u = j;
                min = d[j];
            }
        if( u == -1 )
            break;
        visit[u] = true;
        for( int j = 0, v = 0; j < G[u].size( ); j++ ) {
            v = G[u][j].v;
            if( visit[v] == false ) {
                if( d[u] + G[u][j].dis < d[v] ) {
                    d[v] = d[u] + G[u][j].dis; // 更新最短距离
                    cost[v] = cost[u] + G[u][j].cost; // 更新代价
                    pre[v] = u; // 记录前驱
                } else if( d[u] + G[u][j].dis == d[v] && cost[u] + G[u][j].cost < cost[v] ) {
                    cost[v] = cost[u] + G[u][j].cost;
                    pre[v] = u;
                } // 距离等同但代价更少
            }
        }
    }
}

void DFS( const int &start, const int &end ) { // 递归地回溯路径
    if( start == end ) { // 回溯到出发点了
        printf( "%d", start ); // 这一块执行完就开始一层一层解递归了
        return;
    }
    DFS( start, pre[end] );
    printf( " %d", end ); // 由深到浅解递归
}

int main( ) {
    int N, M, S, D;
    cin >> N >> M >> S >> D;
    G.resize( N );
    d.resize( N ), cost.resize( N ), pre.resize( N );
    visit.resize( N );
    for( int i = 0, v1 = 0, v2 = 0, dis = 0, cost = 0; i < M; i++ ) {
        scanf( "%d %d %d %d", &v1, &v2, &dis, &cost );
        G[v1].emplace_back( node( v2, dis, cost ) );
        G[v2].emplace_back( node( v1, dis, cost ) );
    }
    Dijkstra( S, N );
    DFS( S, D );
    printf( " %d %d", d[D], cost[D] );
    return 0;
}
