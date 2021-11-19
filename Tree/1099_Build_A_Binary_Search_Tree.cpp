#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 0x7f
using namespace std;
struct node {
    int data, left, right;
} tree[MAX];
vector<int> in, level;
// 跟1064一个思路，利用中序遍历是关键
// 二叉搜索树的中序序列就是递增序列，利用此性质
void InOrder( int root, int &key ) {
    if( root == -1 )
        return;
    InOrder( tree[root].left, key );
    tree[root].data = in[key++];
    InOrder( tree[root].right, key );
}

void LayerOrder( int root ) {
    queue<int> q;
    q.push( root );
    while( !q.empty( ) ) {
        root = q.front( );
        level.push_back( tree[root].data );
        q.pop( );
        if( tree[root].left != -1 )
            q.push( tree[root].left );
        if( tree[root].right != -1 )
            q.push( tree[root].right );
    }
}

int main( ) {
    int N;
    cin >> N;
    for( int i = 0, tempLeft = 0, tempRight = 0; i < N; i++ ) {
        cin >> tempLeft >> tempRight;
        tree[i].left = tempLeft;
        tree[i].right = tempRight;
    }
    for( int i = 0, temp = 0; i < N; i++ ) {
        cin >> temp;
        in.push_back( temp );
    }
    sort( in.begin( ), in.end( ) );
    int key = 0;
    InOrder( 0, key );
    LayerOrder( 0 );
    cout << level[0];
    for( int i = 1; i < N; i++ )
        cout << " " << level[i];
    return 0;
}