#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
struct node {
    int data, lchild, rchild, parent, depth;
} tree[0x3ff]; // max <= 10^3
bool isFull = true;

int Insert( const int &inL, const int &inR, const int &postL, const int &postR, const vector<int> &in, const vector<int> &post, const int &depth ) {
    if( inL > inR )
        return -1;
    int i, numLeft, now = post[postR];
    for( i = inL; i <= inR; i++ )
        if( in[i] == post[postR] ) {
            numLeft = i - inL;
            break;
        }
    tree[now].data = now, tree[now].depth = depth;
    tree[now].lchild = Insert( inL, i - 1, postL, postL + numLeft - 1, in, post, depth + 1 );
    tree[now].rchild = Insert( i + 1, inR, postL + numLeft, postR - 1, in, post, depth + 1 );
    if( tree[now].lchild >= 0 )
        tree[tree[now].lchild].parent = now;
    if( tree[now].rchild >= 0 )
        tree[tree[now].rchild].parent = now;
    if( ( tree[now].lchild >= 0 && tree[now].rchild < 0 ) || tree[now].lchild < 0 && tree[now].rchild >= 0 )
        isFull = false; // 国外的满二叉树定义只要求每个非叶节点都有俩孩子就行
    return now;
}

int main( ) {
    int N, M, root;
    cin >> N;
    vector<int> post( N ), in( N );
    for( int i = 0; i < N; i++ )
        scanf( "%d", &post[i] );
    for( int i = 0; i < N; i++ )
        scanf( "%d", &in[i] );
    root = Insert( 0, N - 1, 0, N - 1, in, post, 1 );
    tree[root].parent = -1;
    cin >> M;
    getchar( );
    for( int i = 0, a = 0, b = 0; i < M; i++ ) {
        string s;
        bool ans;
        getline( cin, s );
        if( s.find( "root", 9 ) != string::npos ) {
            sscanf( s.c_str( ), "%d is the root", &a );
            ans = root == a;
        } else if( s.find( "siblings", 12 ) != string::npos ) { // siblings的意思是兄弟
            sscanf( s.c_str( ), "%d and %d are siblings", &a, &b );
            ans = tree[a].parent == tree[b].parent;
        } else if( s.find( "parent", 9 ) != string::npos ) {
            sscanf( s.c_str( ), "%d is the parent of %d", &a, &b );
            ans = a == tree[b].parent;
        } else if( s.find( "left", 9 ) != string::npos ) {
            sscanf( s.c_str( ), "%d is the left child of %d", &a, &b );
            ans = a == tree[b].lchild;
        } else if( s.find( "right", 9 ) != string::npos ) {
            sscanf( s.c_str( ), "%d is the right child of %d", &a, &b );
            ans = a == tree[b].rchild;
        } else if( s.find( "same", 20 ) != string::npos ) {
            sscanf( s.c_str( ), "%d and %d are on the same level", &a, &b );
            ans = tree[a].depth == tree[b].depth;
        } else {
            ans = isFull;
        }
        printf( "%s\n", ans ? "Yes" : "No" );
    }
    return 0;
}
