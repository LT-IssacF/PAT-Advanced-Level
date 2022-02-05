#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> vertice;
// 判断图中所有边是否都连在给定的顶点上
int main( ) {
    int N, M, K;
    cin >> N >> M;
    vertice.resize( N );
    for( int i = 0, v1 = 0, v2 = 0; i < M; i++ ) {
        scanf( "%d %d", &v1, &v2 );
        vertice[v1].push_back( i ), vertice[v2].push_back( i );
    } // vertice[v][i] = e表示第e条边是连接到顶点v的第i条边，即e属于顶点v
    cin >> K;
    for( int i = 0, cnt = 0; i < K; i++ ) { // K轮
        scanf( "%d", &cnt ); // 给定cnt个顶点
        vector<bool> hashTable( M, false ); // 判断连在cnt个顶点上的边是否是图中全部的边
        for( int j = 0, v = 0; j < cnt; j++ ) {
            scanf( "%d", &v ); // 顶点v
            for( int k = 0; k < vertice[v].size( ); k++ )
                hashTable[vertice[v][k]] = true; // 标记连在顶点v上的第k条边
        }
        bool flag = true;
        for( int j = 0; j < M; j++ )
            if( hashTable[j] == false ) {
                flag = false;
                break;
            }
        cout << ( flag ? "Yes" : "No" ) << endl;
    }
    return 0;
}
