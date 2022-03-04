#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int data, lchild, rchild;
};
vector<node> tree;
void PostOrder( const int &root, const int &start ) {
    if( start == 0 )
        return;
    PostOrder( root, tree[start].lchild );
    PostOrder( root, tree[start].rchild );
    cout << tree[start].data << ( start == root ? "\n" : " " );
}

int main( ) {
    int M, N;
    cin >> M >> N;
    vector<int> arr( N + 1 );
    tree.resize( N + 1 );
    for( int i = 0, j = 1, key = 0; i < M; i++ ) {
        for( j = 1; j <= N; j++ ) {
            scanf( "%d", &arr[j] );
            tree[j].data = arr[j];
        }
        arr[0] = arr[1] >= arr[2] ? 1 : 2; // arr[0] = 1大顶堆，2小顶堆
        for( j = 1, key = 0; j <= N / 2; j++ ) { // arr[N / 2]是最后一个父结点，堆的性质
            key = arr[2 * j]; // 先令key为父结点的左孩子的值
            if( arr[0] == 1 ) { // 大顶堆
                if( 2 * j + 1 <= N && key < arr[2 * j + 1] ) // 如果右孩子存在且右孩子的值更大
                    key = arr[2 * j + 1];
                if( arr[j] < key ) // 一旦出现孩子的值比父结点的还大就不是大顶堆
                    arr[0] = 0;
            } else { // 小顶堆亦同理
                if( 2 * j + 1 <= N && key > arr[2 * j + 1] )
                    key = arr[2 * j + 1];
                if( arr[j] >= key )
                    arr[0] = 0;
            }
            tree[j].lchild = 2 * j; // 顺便把树建了
            if( 2 * j + 1 <= N )
                tree[j].rchild = 2 * j + 1;
        }
        cout << ( arr[0] == 0 ? "Not Heap" : ( arr[0] == 1 ? "Max Heap" : "Min Heap" ) ) << endl;
        PostOrder( 1, 1 );
    }
    return 0;
}
