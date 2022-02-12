#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> G; // 邻接表
vector<bool> visit ; // 访问标记
void DFS( const int &start ) { // 深度遍历单个连通图
    visit[start] = true;
    for( int i = 0; i < G[start].size( ); i++ )
        if( visit[G[start][i]] == false )
            DFS( G[start][i] );
}

int DFS_Travels( const int &city ) { // 获取连通块数
    fill( visit.begin( ), visit.end( ), false ); // 重置访问标记
    visit[city] = true;
    int numOfConnect = 0;
    for( int i = 1; i < G.size( ); i++ )
        if( visit[i] == false ) {
            DFS( i );
            numOfConnect++;
        }
    return numOfConnect;
}
// 假设图G有n个连通块，那么使它们都连通的最简单方法就是给n1到n2一条边，n2到n3一条边……
// 以此类推n个连通块的图最少需要n-1条边才能全都连通，所以题目也就变成了求一个图的连通块数的问题
// 在乎哪个城市就是标记这个城市再去遍历，题解就是得到的连通块数-1
int main( ) {
    int N, M, K;
    cin >> N >> M >> K;
    G.resize( N + 1 );
    visit.resize( N + 1 );
    for( int i = 0, v1 = 0, v2 = 0; i < M; i++ ) {
        scanf( "%d %d", &v1, &v2 );
        G[v1].push_back( v2 );
        G[v2].push_back( v1 );
    }
    for( int i = 0, ans = 0, city = 0; i < K; i++ ) {
        scanf( "%d", &city );
        ans = DFS_Travels( city );
        printf( "%d\n", ans - 1 );
    }
    return 0;
}
