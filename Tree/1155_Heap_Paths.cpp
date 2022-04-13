#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void DFS( const int &N, const int &now, vector<int> &heap, vector<int> &path ) {
    if( now > N ) { // 越界
        return;
    } else {
        path.push_back( heap[now] );
        if( heap[0] > 0 && path.size() >= 2 ) { // 待路径长度大于等于2且之前依旧符合堆的性质再判断
            int last = path.back( ), secondLast = *( path.end( ) - 2 );
            heap[0] = heap[0] == 1 ? ( secondLast >= last ? 1 : 0 ) : ( secondLast < last ? 2 : 0 );
        }
        if( now > N / 2 ) { // 叶结点就输出整条路径
            printf( "%d", path[0] );
            for( int i = 1; i < path.size(); i++ )
                printf( " %d", path[i] );
            printf( "\n" );
        }
        DFS( N, now * 2 + 1, heap, path );
        DFS( N, now * 2, heap, path );
        path.pop_back( ); // 出栈
    } // 根 右 左
}

int main( ) {
    int N;
    cin >> N;
    vector<int> path, heap( N + 1, 0 );
    for( int i = 1; i <= N; i++ )
        scanf( "%d", &heap[i] );
    heap[0] = heap[1] >= heap[2] ? 1 : 2; // 先根据根结点和它孩子的大小关系判断是否是堆
    DFS( N, 1, heap, path );
    cout << ( heap[0] > 0 ? ( heap[0] == 1 ? "Max Heap" : "Min Heap" ) : "Not Heap" );
    return 0;
}
