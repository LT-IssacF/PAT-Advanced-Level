#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 0xf
using namespace std;
struct node {
    int lchild, rchild;
} tree[MAX];
bool hashTable[MAX] = { false }; // 找根用的
vector<int> level, in;
// 字符转整型
int CharToInt( char s ) {
    if( s == '-' )
        return -1;
    hashTable[( s - '0' )] = true;
    return s - '0';
}
// 没出现过就是根
int FindRoot( int N ) {
    for( int i = 0; i < N; i++ )
        if( hashTable[i] == false )
            return i;
    return -1;
}
// 利用后序遍历的性质可以对一个二叉树左右调换
void PostOrder( int root ) {
    if( root == -1 )
        return;
    PostOrder( tree[root].lchild );
    PostOrder( tree[root].rchild );
    swap( tree[root].lchild, tree[root].rchild );
}

void BFS( int root ) {
    queue<int> q;
    q.push( root );
    while( !q.empty( ) ) {
        root = q.front( );
        level.push_back( root );
        q.pop( );
        if( tree[root].lchild != -1 )
            q.push( tree[root].lchild );
        if( tree[root].rchild != -1 )
            q.push( tree[root].rchild );
    }
}

void InOrder( int root ) {
    if( root == -1 )
        return;
    InOrder( tree[root].lchild );
    in.push_back( root );
    InOrder( tree[root].rchild );
}

int main( ) {
    int N;
    cin >> N;
    for( int i = 0; i < N; i++ ) {
        char left, right;
        scanf( "%*c%c %c", &left, &right );
        tree[i].lchild = CharToInt( left );
        tree[i].rchild = CharToInt( right );
    }
    int root = FindRoot( N );
    PostOrder( root );
    BFS( root );
    InOrder( root );
    cout << level[0];
    for( int i = 1; i < N; i++ )
        cout << " " << level[i];
    cout << '\n' << in[0];
    for( int i = 1; i < N; i++ )
        cout << " " << in[i];
    return 0;
}