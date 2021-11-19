#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct node { // 邻接表
    int data;
    vector<int> child;
};
vector<node> tree;
// 3个额外参数，s当前结点，ans保存结果要引用，depth递归深度
void DFS( int s, double P, double r, double &ans, int depth ) {
    int size = tree[s].child.size( );
    if( size == 0 ) { // 到零售商了
        ans += tree[s].data * ( P * pow( ( 1 + r ), depth ) );
        return;
    }
    for( int i = 0; i < size; i++ ) { // 还在经销商
        DFS( tree[s].child[i], P, r, ans, depth + 1 );
    }
}

int main( ) {
    int N;
    double P, r, ans = 0;
    cin >> N >> P >> r;
    r /= 100; // 对收费率处理
    tree.resize( N );
    for( int i = 0, k = 0; i < N; i++ ) {
        tree[i].data = 0;
        cin >> k;
        if( k != 0 )
            for( int j = 0, child = 0; j < k; j++ ) {
                cin >> child;
                tree[i].child.push_back( child );
            }
        else {
            int amount;
            cin >> amount;
            tree[i].data = amount;
        }
    }
    DFS( 0, P, r, ans, 0 );
    printf( "%.1f", ans );
    return 0;
}