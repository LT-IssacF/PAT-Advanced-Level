#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 0x1fffffff
using namespace std;
struct node {
    int v, dis;
};
vector<vector<node>> G; // 邻接表
int Matrix[1020][1020]; // 邻接矩阵
vector<int> d, choices; // choices用来记录每步新找到最近的结点编号
vector<bool> visit;
void Dijkstra( int N, int start ) {
    fill( d.begin( ), d.end( ), MAX );
    choices.clear( );
    fill( visit.begin( ), visit.end( ), false );
    d[start] = 0;
    for( int i = 1; i <= N; i++ ) {
        int u = -1, min = MAX;
        for( int j = 1; j <= N; j++ ) {
            if( d[j] < min && visit[j] == false ) {
                u = j;
                min = d[j];
            }
        }
        if( u == -1 )
            break;
        choices.push_back( min ); // 距离相等的情况下就编号优先了，所以得用距离来判断
        visit[u] = true;
        for( int j = 0, v = 0; j < G[u].size( ); j++ ) {
            v = G[u][j].v;
            if( visit[v] == false && d[u] + G[u][j].dis < d[v] ) {
                d[v] = d[u] + G[u][j].dis;
            }
        }
    }
}
// 进行Dijkstra算法时，每一步都会选取一个当前距离起始结点最近且未访问的结点来更新最短距离，本题就是来判断给出的序列是不是求出最短距离的序列
int main( ) {
    int N, M, K;
    cin >> N >> M;
    G.resize( N + 1 );
    memset( Matrix, MAX, 1020 * 1020 );
    d.resize( N + 1 );
    visit.resize( N + 1 );
    for( int i = 0, v1 = 0, v2 = 0, dis = 0; i < M; i++ ) {
        scanf( "%d %d %d", &v1, &v2, &dis );
        G[v1].emplace_back( node{ v2, dis } );
        G[v2].emplace_back( node{ v1, dis } );
        Matrix[v1][v2] = Matrix[v2][v1] = dis;
    }
    cin >> K;
    for( int i = 0; i < K; i++ ) {
        vector<int> path( N );
        bool ans = true;
        scanf( "%d", &path[0] );
        Dijkstra( N, path[0] );
        for( int j = 1; j < N; j++ ) {
            scanf( "%d", &path[j] );
            if( d[path[j]] != choices[j] ) // 由于可能有多条最短路径，所以要用距离来判断
                ans = false;
        }
        cout << ( ans ? "Yes" : "No" ) << endl;
    }
    return 0;
}
