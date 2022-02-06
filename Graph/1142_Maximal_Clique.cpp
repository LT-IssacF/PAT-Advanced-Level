#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<vector<int>> G; // 邻接表

int main( ) {
    int N, M, K;
    cin >> N >> M;
    G.resize( N + 1 );
    for( int i = 0, v1 = 0, v2 = 0; i < M; i++ ) {
        scanf( "%d %d", &v1, &v2 );
        G[v1].push_back( v2 );
        G[v2].push_back( v1 );
    }
    cin >> K;
    for( int i = 0, cnt = 0; i < K; i++ ) {
        scanf( "%d", &cnt ); // 给定的clique中结点的数量
        map<int, bool> visit; // 标记提供的clique的结点
        bool isClique = false, isMaximal = true;
        for( int j = 0, v = 0; j < cnt; j++ ) {
            scanf( "%d", &v );
            visit[v] = true; // 标记
        }
        int sumOfEdges = 0; // 给定结点们连向彼此的边的总数
        for( int j = 1; j <= N; j++ )
            if( visit[j] == true ) // 是给定的结点
                for( int k = 0; k < G[j].size( ); k++ ) // 遍历j所有的边
                    if( visit[G[j][k]] == true )
                        sumOfEdges++;
        if( sumOfEdges == cnt * ( cnt - 1 ) ) { // 判断给定的clique是不是完全无向图
            isClique = true;
            for( int j = 1; j <= N; j++ ) { // 开始访问除clique以外图剩下的结点
                int connectToClique = 0; // j连向clique任意结点的边数
                if( visit[j] == false ) { // j是剩下的结点
                    for( int k = 0; k < G[j].size( ); k++ ) { // 遍历j所有的边
                        if( visit[G[j][k]] == true ) // 是连向clique其中某结点的边
                            connectToClique++;
                    }
                    if( connectToClique == cnt ) { // 遍历完j所有的边发现自己与clique所有顶点都有边
                        isMaximal = false; // 那么j也可以是clique的一员即不是Maximal
                        break;
                    }
                }
            }
        }
        cout << ( isClique ? ( isMaximal ? "Yes" : "Not Maximal" ) : "Not a Clique" ) << endl;
    }
    return 0;
}
