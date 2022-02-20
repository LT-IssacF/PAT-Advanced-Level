#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 0x7f
using namespace std;
struct node {
    vector<int> children;
} tree[MAX];
vector<vector<int>> path; // 储存所有路径
vector<int> tempPath; // 储存临时路径
void DFS( const int &now, const int &total, const int &S, const vector<int> &weight ) {
    if( tree[now].children.size( ) == 0 ) { // 到达叶结点了
        if( total + weight[now] == S ) { // 如果祖先的权值之和加上自己的等于S
            tempPath.push_back( weight[now] );
            path.emplace_back( tempPath );
            tempPath.pop_back( ); // 回溯
        }
        return;
    }
    tempPath.push_back( weight[now] );
    for( int i = 0; i < tree[now].children.size( ); i++ ) // 深度遍历当前结点的孩子
        DFS( tree[now].children[i], total + weight[now], S, weight );
    tempPath.pop_back( ); // 回溯
}

int main( ) {
    int N, M, S;
    cin >> N >> M >> S;
    vector<int> weight( N );
    for( int i = 0; i < N; i++ )
        scanf( "%d", &weight[i] );
    for( int i = 0, id = 0, K = 0; i < M; i++ ) {
        scanf( "%d %d", &id, &K );
        for( int j = 0, child = 0; j < K; j++ ) {
            scanf( "%d", &child );
            tree[id].children.push_back( child );
        }
        sort( tree[id].children.begin( ), tree[id].children.end( ),
            [weight] ( const int &a, const int &b ) {
            return weight[a] > weight[b];
        } ); // 没输完一个非叶结点就将它的孩子按权值降序排列
    }
    DFS( 0, 0, S, weight );
    sort( path.begin( ), path.end( ), greater<vector<int>>( ) ); // 当一个结点的孩子中有多个孩子权值相等
    for( int i = 0; i < path.size( ); i++ ) { // 而后面的结点又不能保证有序，就会出错，所以要对所有路径集中排序
        printf( "%d", path[i][0] );
        for( int j = 1; j < path[i].size( ); j++ )
            printf( " %d", path[i][j] );
        printf( "\n" );
    }
    return 0;
}
