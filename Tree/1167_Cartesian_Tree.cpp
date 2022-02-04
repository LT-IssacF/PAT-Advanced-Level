#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 0x3fffffff
using namespace std;
typedef struct BiNode {
    int data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
vector<int> in, ans;
BiTree Insert( int inL, int inR ) { // 从区间内找出最小的值，左边就是左子树，右边就是右子树
    if( inL > inR )
        return NULL;
    int i, min_index, MIN = MAX;
    for( i = inL; i <= inR; i++ ) // 找区间里的最小值
        if( in[i] < MIN ) {
            MIN = in[i];
            min_index = i;
        }
    BiTree T = ( BiTree ) malloc( sizeof( struct BiNode ) );
    T->data = MIN;
    T->lchild = Insert( inL, min_index - 1 );
    T->rchild = Insert( min_index + 1, inR );
    return T;
}
// 太简单了
void BFS( const BiTree &T ) { // 层序遍历
    queue<BiTree> q;
    q.push( T );
    while( !q.empty( ) ) {
        BiTree front = q.front( );
        ans.push_back( front->data );
        q.pop( );
        if( front->lchild )
            q.push( front->lchild );
        if( front->rchild )
            q.push( front->rchild );
    }
}

int main( ) {
    int N;
    cin >> N;
    in.resize( N );
    for( int i = 0; i < N; i++ )
        cin >> in[i];
    BiTree T = Insert( 0, N - 1 );
    BFS( T );
    for( int i = 0; i < N; i++ ) {
        if( i != 0 )
            cout << " ";
        cout << ans[i];
    }
    return 0;
}
