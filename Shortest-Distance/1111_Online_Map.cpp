#include <iostream>
#include <cstdio>
#include <vector>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, dis, time;
}; // path数组存储路径，pre数组储存前驱，nodeCnt记录最短路径上当前结点的前驱结点个数
vector<vector<node>> G;
vector<int> d, t, dpre, tpre, nodeCnt, dpath, tpath;
vector<bool> visit;
void Dijkstra( const int &N, const int &source, const int &tag ) { // tag标记使用距离还是时间作为优先条件
    fill( t.begin( ), t.end( ), INF );
    fill( visit.begin( ), visit.end( ), false );
    t[source] = 0; // 设置起点
    if( tag == 0 ) { // 距离优先
        fill( d.begin( ), d.end( ), INF );
        d[source] = 0; // 设置起点
        for( int i = 0; i < N; i++ ) {
            int u = -1, MIN = INF;
            for( int j = 0; j < N; j++ )
                if( d[j] < MIN && visit[j] == false ) {
                    u = j;
                    MIN = d[j];
                }
            if( u == -1 )
                break;
            visit[u] = true;
            for( int j = 0, v = 0; j < G[u].size( ); j++ ) {
                v = G[u][j].v;
                if( visit[v] == false ) {
                    if( d[u] + G[u][j].dis < d[v] ) { // 距离更小
                        d[v] = G[u][j].dis + d[u];
                        t[v] = G[u][j].time + t[u];
                        dpre[v] = u; // u是v的前驱
                    } else if( d[u] + G[u][j].dis == d[v] && t[u] + G[u][j].time < t[v] ) {
                        t[v] = G[u][j].time + t[u];
                        dpre[v] = u;
                    } // 距离相等时间更少
                }
            }
        }
    } else { // 时间优先
        nodeCnt[source] = 0; // 设置起点
        for( int i = 0; i < N; i++ ) {
            int u = -1, MIN = INF;
            for( int j = 0; j < N; j++ )
                if( t[j] < MIN && visit[j] == false ) {
                    u = j;
                    MIN = d[j];
                }
            if( u == -1 )
                break;
            visit[u] = true;
            for( int j = 0, v = 0; j < G[u].size( ); j++ ) {
                v = G[u][j].v;
                if( visit[v] == false ) {
                    if( t[u] + G[u][j].time < t[v] ) {
                        t[v] = G[u][j].time + t[u];
                        tpre[v] = u;
                        nodeCnt[v] = nodeCnt[u] + 1;
                    } else if( t[u] + G[u][j].time == t[v] && nodeCnt[u] + 1 < nodeCnt[v] ) {
                        tpre[v] = u;
                        nodeCnt[v] = nodeCnt[u] + 1;
                    } // 以u为前驱结点数会更少
                }
            }
        }
    }
}

void DFS( const int &now, const int &source, const vector<int> &pre, vector<int> &path ) {
    if( now == source ) {
        path.push_back( now );
        return;
    }
    DFS( pre[now], source, pre, path );
    path.push_back( now );
}

void Print( const vector<int> &path ) {
    printf( "%d", path[0] );
    for( int i = 1; i < path.size( ); i++ )
        printf( " -> %d", path[i] );
}

int main( ) {
    int N, M, source, destination;
    cin >> N >> M;
    G.resize( N );
    d.resize( N ), t.resize( N ), dpre.resize( N ), tpre.resize( N ), nodeCnt.resize( N );
    visit.resize( N );
    for( int i = 0, v = 0, v2 = 0, tag = 0, dis = 0, time = 0; i < M; i++ ) {
        scanf( "%d %d %d %d %d", &v, &v2, &tag, &dis, &time );
        G[v].emplace_back( node{ v2, dis, time } );
        if( tag == 0 ) // 单行道
            G[v2].emplace_back( node{ v, dis, time } );
    }
    cin >> source >> destination;
    Dijkstra( N, source, 0 );
    Dijkstra( N, source, 1 );
    DFS( destination, source, dpre, dpath );
    DFS( destination, source, tpre, tpath );
    if( dpath == tpath ) {
        printf( "Distance = %d; Time = %d: ", d[destination], t[destination] );
        Print( dpath );
    } else {
        printf( "Distance = %d: ", d[destination] );
        Print( dpath );
        printf( "\n" );
        printf( "Time = %d: ", t[destination] );
        Print( tpath );
    }
    return 0;
}
