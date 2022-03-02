#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX 0xf
using namespace std;
struct node {
    int lchild, rchild;
} tree[MAX];
vector<int> in, level;
void BFS( const int &root ) {
    queue<int> q;
    q.push( root );
    while( !q.empty( ) ) {
        int front = q.front( );
        level.push_back( front );
        q.pop( );
        if( tree[front].lchild >= 0 )
            q.push( tree[front].lchild );
        if( tree[front].rchild >= 0 )
            q.push( tree[front].rchild );
    }
}
 // 利用后序遍历的性质可以对一个二叉树左右调换
void PostOrder( const int &now ) {
    if( now < 0 )
        return;
    PostOrder( tree[now].lchild );
    PostOrder( tree[now].rchild );
    swap( tree[now].lchild, tree[now].rchild );
}

void InOrder( const int &now ) {
    if( now < 0 )
        return;
    InOrder( tree[now].lchild );
    in.push_back( now );
    InOrder( tree[now].rchild );
}

void Print( const int &N, const vector<int> &sequence ) {
    printf( "%d", sequence[0] );
    for( int i = 1; i < N; i++ )
        printf( " %d", sequence[i] );
    printf( "\n" );
}

int main( ) {
    int N, root;
    cin >> N;
    vector<bool> hashTable( N, false );
    for( int i = 0, l = 0, r = 0; i < N; i++ ) {
        getchar( );
        scanf( "%c %c", &l, &r );
        if( l != 45 ) {
            tree[i].lchild = l - 48;
            hashTable[l - 48] = true;
        } else {
            tree[i].lchild = -1;
        }
        if( r != 45 ) {
            tree[i].rchild = r - 48;
            hashTable[r - 48] = true;
        } else {
            tree[i].rchild = -1;
        }
    }
    for( int i = 0; i < N; i++ )
        if( hashTable[i] == false ) {
            root = i;
            break;
        }
    PostOrder( root );
    BFS( root );
    Print( N, level );
    InOrder( root );
    Print( N, in );
    return 0;
}
