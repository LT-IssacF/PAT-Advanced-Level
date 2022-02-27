#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    int data, lchild, rchild;
} tree[0x7f];
int p = 0; // 在in中的索引
void InOrder( const int &now, const vector<int> &in ) {
    if( now == -1 )
        return;
    InOrder( tree[now].lchild, in );
    tree[now].data = in[p++];
    InOrder( tree[now].rchild, in );
} // 二叉搜索树的中序序列是递增序列，利用此性质

void BFS( const int &root, vector<int> &ans ) {
    queue<int> q;
    q.push( root );
    while( !q.empty( ) ) {
        int front = q.front( );
        ans.push_back( tree[front].data );
        q.pop( );
        if( tree[front].lchild >= 0 )
            q.push( tree[front].lchild );
        if( tree[front].rchild >= 0 )
            q.push( tree[front].rchild );
    }
}

int main( ) {
    int N;
    cin >> N;
    for( int i = 0; i < N; i++ )
        scanf( "%d %d", &tree[i].lchild, &tree[i].rchild );
    vector<int> in( N ), ans;
    for( int i = 0; i < N; i++ )
        scanf( "%d", &in[i] );
    sort( in.begin( ), in.end( ) );
    InOrder( 0, in );
    BFS( 0, ans );
    printf( "%d", ans[0] );
    for( int i = 1; i < N; i++ )
        printf( " %d", ans[i] );
    return 0;
}
