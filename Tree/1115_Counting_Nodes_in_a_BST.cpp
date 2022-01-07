#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct BiNode {
    int data, level;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
int deepest = 0, n1 = 0, n2 = 0;
vector<int> depth;
void Insert( BiTree &T, int key ) {
    if( !T ) {
        T = ( BiTree ) malloc( sizeof( struct BiNode ) );
        T->data = key;
        T->lchild = T->rchild = NULL;
    }
    else if( key <= T->data )
        Insert( T->lchild, key );
    else
        Insert( T->rchild, key );
}

void DFS( BiTree &T, int level ) { // 深度遍历
    if( !T )
        return;
    deepest = max( deepest, level );
    depth[level]++; // 也可以设置一个数组储存各深度的结点个数
    T->level = level++;
    DFS( T->lchild, level );
    DFS( T->rchild, level );
}

void BFS( const BiTree &T ) { // 广度遍历
    queue<BiTree> q;
    q.push( T );
    while( !q.empty( ) ) {
        BiTree front = q.front( );
        q.pop( );
        if( front->level == deepest )
            n1++;
        else if( front->level == deepest - 1 )
            n2++;
        if( front->lchild )
            q.push( front->lchild );
        if( front->rchild )
            q.push( front->rchild );
    }
}

int main( ) {
    int N;
    cin >> N;
    BiTree T = NULL;
    for( int i = 0, key = 0; i < N; i++ ) {
        cin >> key;
        Insert( T, key );
    }
    depth.resize( N );
    DFS( T, 1 );
    // BFS( T );
    cout << depth[deepest] << " + " << depth[deepest - 1] << " = " << depth[deepest] + depth[deepest - 1];
    // cout << n1 << " + " << n2 << " = " << n1 + n2;
    return 0;
}
