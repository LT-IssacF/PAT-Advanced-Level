#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> heap, ans;
void DFS( const int &start, const int &root, const int &N ) {
    if( start > N )
        return;
    ans.push_back( heap[start] );
    if( start != root ) {
        vector<int>::iterator it = ans.end( ) - 1; // it指向刚入栈的新元素
        if( heap[0] == 1 ) { // 大顶堆的情况下
            if( *( it - 1 ) < *it ) // 如果子结点的值大于父结点的值那就不是堆
                heap[0] = 0;
        } else if( heap[0] == 2 ) { // 小顶堆亦相同
            if( *( it - 1 ) > *it )
                heap[0] = 0;
        }
    }
    if( start > N / 2 ) { // 叶结点
        printf( "%d", ans[0] );
        for( int i = 1; i < ans.size( ); i++ )
            printf( " %d", ans[i] );
        printf( "\n" );
    }
    DFS( 2 * start + 1, root, N );
    DFS( 2 * start, root, N );
    ans.pop_back( ); // 出栈
} // 右 左 根

int main( ) {
    int N;
    cin >> N;
    heap.resize( N + 1 );
    for( int i = 1; i <= N; i++ )
        scanf( "%d", &heap[i] );
    heap[0] = ( heap[1] >= heap[2] ? 1 : 2 );
    DFS( 1, 1, N );
    cout << ( heap[0] == 0 ? "Not Heap" : ( heap[0] == 1 ) ? "Max Heap" : "Min Heap" );
    return 0;
}
