#include <iostream>
#include <cstdio>
#include <vector>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, dis;
    node( const int &v2, const int &dis2 ) : v( v2 ), dis( dis2 ) { }
};
vector<vector<node>> G; // 邻接表
vector<vector<int>> pre; // 记录前驱
vector<int> d, bike, path, tempPath;
vector<bool> visit;
int minBring = INF, minBikeKeepping = INF; // 全局变量最少初始携带车辆和最少剩余车辆
void Dijkstra( const int &start, const int &N ) {
    fill( d.begin( ), d.end( ), INF );
    fill( visit.begin( ), visit.end( ), false );
    d[start] = 0;
    for( int i = 0; i <= N; i++ ) {
        int u = -1, min = INF;
        for( int j = 0; j <= N; j++ )
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
                    d[v] = d[u] + G[u][j].dis;
                    pre[v].clear( ); // 更新最短路径了就要清空前驱
                    pre[v].push_back( u ); // 记下前驱
                } else if( d[u] + G[u][j].dis == d[v] ) {
                    pre[v].push_back( u ); // 最短路径不唯一，即有多个前驱
                }
            }
        }
    }
}

void DFS( const int &now, const int &end ) { // 从indexOfProblemV倒着深度遍历回PBMC
    if( now == end ) { // 递归到边界即PBMC就把这一路的结点计算
        tempPath.push_back( now );
        int bring = 0, bikeKeepping = 0;
        for( int i = tempPath.size( ) - 2, v = 0, need = 0; i >= 0; i-- ) {
            v = tempPath[i];
            if( bike[v] > 0 ) { // 站点车多了
                bikeKeepping += bike[v];
            } else if( bike[v] < 0 ) { // 站点车不够
                need = abs( bike[v] );
                if( bikeKeepping < need ) {
                    bring += need - bikeKeepping;
                    bikeKeepping = 0;
                } else {
                    bikeKeepping -= need;
                }
            }
        }
        if( ( bring < minBring ) || ( bring == minBring && bikeKeepping < minBikeKeepping ) ) {
            path = tempPath;
            minBring = bring, minBikeKeepping = bikeKeepping;
        }
        tempPath.pop_back( ); // 回溯到分叉结点
        return;
    }
    tempPath.push_back( now ); // 加入路径
    for( int i = 0; i < pre[now].size( ); i++ )
        DFS( pre[now][i], end ); // 深度遍历v的前驱
    tempPath.pop_back( ); // 回溯到分叉结点
}

int main( ) {
    int C, N, indexOfProblemV, M;
    cin >> C >> N >> indexOfProblemV >> M;
    G.resize( N + 1 );
    pre.resize( N + 1 );
    d.resize( N + 1 ), bike.resize( N + 1 );
    visit.resize( N + 1 );
    for( int i = 1; i <= N; i++ ) {
        scanf( "%d", &bike[i] );
        bike[i] -= C / 2; // 对车数量做了处理取C / 2为零点，方便计算
    }
    for( int i = 0, v1 = 0, v2 = 0, dis = 0; i < M; i++ ) {
        scanf( "%d %d %d", &v1, &v2, &dis );
        G[v1].emplace_back( node( v2, dis ) );
        G[v2].emplace_back( node( v1, dis ) );
    }
    Dijkstra( 0, N );
    DFS( indexOfProblemV, 0 );
    printf( "%d ", minBring );
    for( int i = path.size( ) - 1; i >= 0; i-- ) {
        if( i != path.size( ) - 1 )
            printf( "->" );
        printf( "%d", path[i] );
    }
    printf( " %d", minBikeKeepping );
    return 0;
}
