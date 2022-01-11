#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> G; // 邻接表
vector<bool> visit;
void BFS( const int &start, int &oddgree ) {
    queue<int> q;
    q.push( start );
    visit[start] = true;
    while( !q.empty( ) ) {
        int front = q.front( );
        int degree = G[front].size( );
        if( degree % 2 == 1 )
            oddgree++;
        q.pop( );
        for( int i = 0; i < degree; i++ )
            if( visit[G[front][i]] == false ) {
                q.push( G[front][i] );
                visit[G[front][i]] = true;
            }
    }
}

int main( ) {
    int N, M;
    cin >> N >> M;
    G.resize( N + 1 );
    visit.resize( N + 1 );
    for( int i = 0, v1 = 0, v2 = 0; i < M; i++ ) {
        scanf( "%d %d", &v1, &v2 );
        G[v1].push_back( v2 );
        G[v2].push_back( v1 );
    }
    bool isConnected = true; // 判断图是否连通
    int oddDegree = 0; // 度为奇数的结点个数
    BFS( 1, oddDegree );
    for( int i = 1; i <= N; i++ ) {
        if( visit[i] == false )
            isConnected = false;
        if( i != 1 )
            cout << " ";
        cout << G[i].size( );
    }
    cout << endl;
    if( isConnected && oddDegree == 0 )
        cout << "Eulerian";
    else if( isConnected && oddDegree == 2 )
        cout << "Semi-Eulerian";
    else
        cout << "Non-Eulerian";
    return 0;
}
