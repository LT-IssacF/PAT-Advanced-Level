#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef struct BiNode {
    int data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
BiTree Insert( const vector<int> &in, const int &inL, const int &inR ) {
    if( inL > inR )
        return NULL;
    int root = inL; // 从区间内找出最小的值，左边就是左子树，右边就是右子树
    for( int i = inL + 1; i <= inR; i++ ) // 找区间里的最小值
        if( in[i] < in[root] )
            root = i;
    BiTree T = ( BiTree ) malloc( sizeof( BiNode ) );
    T->data = in[root];
    T->lchild = Insert( in, inL, root - 1 );
    T->rchild = Insert( in, root + 1, inR );
    return T;
}

void BFS( const BiTree &T, vector<int> &ans ) {
    queue<BiTree> q;
    q.push( T );
    while( !q.empty( ) ) {
        BiTree front = q.front( );
        ans.push_back( front->data );
        q.pop( );
        if( front->lchild != NULL )
            q.push( front->lchild );
        if( front->rchild != NULL )
            q.push( front->rchild );
    }
}

int main( ) {
    int N;
    cin >> N;
    vector<int> in( N ), ans;
    for( int i = 0; i < N; i++ )
        scanf( "%d", &in[i] );
    BiTree T = Insert( in, 0, N - 1 );
    BFS( T, ans );
    printf( "%d", ans[0] );
    for( int i = 1; i < ans.size( ); i++ )
        printf( " %d", ans[i] );
    return 0;
}
