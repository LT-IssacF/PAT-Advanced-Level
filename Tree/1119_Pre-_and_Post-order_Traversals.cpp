#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool flag = true;
void GetIn( vector<int> &in, const vector<int> pre, const vector<int> post, const int &preL, const int &preR, const int &postL, const int &postR ) {
    if( preL == preR ) { // 叶结点
        in.push_back( pre[preL] );
        return;
    }
    if( pre[preL] == post[postR] ) { // 处理根结点
        int i, numLeft; // 左子树的结点个数
        for( i = preL + 1; i <= preR; i++ ) // i从当前根结点的下一个开始
            if( pre[i] == post[postR - 1] ) { // i已经到了当前根结点的右子树，post[postR - 1]是当前根结点的右子树
                numLeft = i - preL - 1; // 在前序中就可以求出左子树的结点个数
                break;
            }
        if( numLeft >= 1 ) { // 左子树有结点就递归处理左子树
            GetIn( in, pre, post, preL + 1, i - 1, postL, postL + numLeft - 1 );
        } else { // 没有左子树，也就是当前根结点只有一棵子树，那么整棵就不唯一
            flag = false;
        }
        in.push_back( pre[preL] ); // 入队当前根结点
        GetIn( in, pre, post, i, preR, postL + numLeft, postR - 1 ); // 处理右子树
    } // 结合中序遍历——左根右的特点递归处理左右子树
} // 前序是根左右，后序是左右根，可以发现如果一个子树只有一个孩子，那么它是不唯一的

int main( ) {
    int N;
    cin >> N;
    vector<int> in, pre( N ), post( N );
    for( int i = 0; i < N; i++ )
        scanf( "%d", &pre[i] );
    for( int i = 0; i < N; i++ )
        scanf( "%d", &post[i] );
    GetIn( in, pre, post, 0, N - 1, 0, N - 1 );
    cout << ( flag ? "Yes" : "No" ) << endl;
    printf( "%d", in[0] );
    for( int i = 1; i < N; i++ )
        printf( " %d", in[i] );
    printf( "\n" );
    return 0;
}
