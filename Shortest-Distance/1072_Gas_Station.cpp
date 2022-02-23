#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, dis;
};
vector<vector<node>> G;
vector<int> d;
vector<bool> visit;
int stringToInt( char *city, const int &N ) {
    int ans = 0, exponent = 1;
    for( int i = strlen( city ) - 1; i > 0; i--, exponent *= 10 )
        ans += ( city[i] - '0' ) * exponent;
    ans += ( city[0] == 'G' ? N : ( city[0] - '0' ) * exponent ); // 候选地接着居民最后编号
    return ans;
}

void Dijkstra( const int &start, const int &NM ) {
    fill( d.begin( ), d.end( ), INF );
    fill( visit.begin( ), visit.end( ), false );
    d[start] = 0;
    for( int i = 1; i <= NM; i++ ) {
        int u = -1, MIN = INF;
        for( int j = 1; j <= NM; j++ )
            if( d[j] < MIN && visit[j] == false ) {
                u = j;
                MIN = d[j];
            }
        if( u == -1 )
            break;
        visit[u] = true;
        for( int j = 0, v = 0; j < G[u].size( ); j++ ) {
            v = G[u][j].v;
            if( visit[v] == false && d[u] + G[u][j].dis < d[v] )
                d[v] = d[u] + G[u][j].dis;
        }
    }
}

int main( ) {
    int N, M, K, D;
    cin >> N >> M >> K >> D;
    G.resize( N + M + 1 );
    d.resize( N + M + 1 );
    visit.resize( N + M + 1 );
    char city1[5] = { '\0' }, city2[5] = { '\0' };
    for( int i = 0, c1 = 0, c2 = 0, dis = 0; i < K; i++ ) {
        scanf( "%s %s %d", city1, city2, &dis );
        c1 = stringToInt( city1, N ), c2 = stringToInt( city2, N );
        G[c1].emplace_back( node{ c2, dis } );
        G[c2].emplace_back( node{ c1, dis } );
    }
    int ans = 0, minDis = 0, minAvgDis = INF;
    for( int i = 0; i < M; i++ ) { // 枚举每个候选地
        Dijkstra( N + i + 1, N + M ); // 已获得从此候选地到各个居民的最短距离
        int dis = INF, avgDis = 0; // 离最近的居民的距离
        bool flag = true;
        for( int j = 1; j <= N; j++ ) {
            if( d[j] > D ) { // 有居民超出范围，放弃此候选地
                flag = false;
                break;
            }
            if( d[j] < dis )
                dis = d[j];
            avgDis += d[j];
        }
        if( !flag )
            continue;
        if( dis > minDis ) { // 候选地距离最近的居民要尽可能远
            ans = i + 1;
            minDis = dis;
            minAvgDis = avgDis;
        } else if( dis == minDis && avgDis < minAvgDis ) { // 距离一样就使平均距离最近
            ans = i + 1;
            minAvgDis = avgDis;
        }
    }
    if( ans == 0 ) {
        printf( "No Solution" );
    } else {
        printf( "G%d\n%d.0 %.1f", ans, minDis, 1.0 * minAvgDis / N );
    }
    return 0;
}
