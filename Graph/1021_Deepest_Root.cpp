#include <iostream>
#include <vector>
#include <cmath>
#define MAX 10020
using namespace std;
vector<vector<int>> G;
bool visit[MAX] = { false };
int tempDepth = -1;

void DFS( int now, int depth ) {
    tempDepth = max( depth, tempDepth ); // 更新高度
    visit[now] = true;
    int size = G[now].size( );
    for( int i = 0; i < size; i++ ) {
        if( visit[G[now][i]] == false )
            DFS( G[now][i], depth + 1 );
    }
}

int DFS_Travels( ) {
    int size = G.size( ), subGraph = 0;
    for( int i = 1; i < size; i++ ) {
        if( visit[i] == false ) {
            DFS( i, 0 );
            subGraph++;
        }
    }
    return subGraph;
}

int main( ) {
    int N;
    cin >> N;
    G.resize( N + 1 );
    for( int i = 1, v = 0, next = 0; i < N; i++ ) {
        cin >> v >> next;
        G[v].push_back( next );
        G[next].push_back( v );
    }
    int subGraph = DFS_Travels( );
    // N个结点N-1条边，只能是一棵树，除非不是连通图
    if( subGraph > 1 )
        cout << "Error: " << subGraph << " components";
    else {
        vector<int> depth;
        depth.resize( N + 1 ); // 记录以i为根的树的高度
        int maxDepth = -1; // 保存最大高度
        for( int i = 1; i < N + 1; i++ ) {
            tempDepth = -1;
            fill( visit, visit + MAX, false );
            DFS( i, 0 ); // 从结点i开始深度遍历得到以i为根的树的高度
            depth[i] = tempDepth;
            maxDepth = max( maxDepth, tempDepth );
        }
        for( int i = 1; i < N + 1; i++ )
            if( depth[i] == maxDepth )
                cout << i << endl;
    }
    return 0;
}