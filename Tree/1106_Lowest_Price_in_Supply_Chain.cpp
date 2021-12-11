#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> tree;
int minLevel = 0x3fffffff, cnt = 0;
// 深度遍历
void DFS( int retailer, int level ) {
    int size = tree[retailer].size( );
    if( size == 0 ) { // size为0就说明是零售商
        if( level < minLevel ) { // 记录最小经销次数
            minLevel = level;
            cnt = 1; // 经销商个数初始化
        }
        else if( level == minLevel ) // 多个经销商
            cnt++;
        return;
    }
    for( int i = 0; i < size; i++ ) {
        DFS( tree[retailer][i], level + 1 );
    }
}
// 和1090一个类型，不多阐述
int main( ) {
    int N;
    double P, r, price;
    cin >> N >> P >> r;
    tree.resize( N );
    r /= 100;
    for( int i = 0, j = 0, cnt = 0, child = 0; i < N; i++ ) {
        cin >> cnt;
        for( j = 0; j < cnt; j++ ) {
            cin >> child;
            tree[i].push_back( child );
        }
    }
    DFS( 0, 0 );
    price = P * pow( 1 + r, minLevel );
    printf( "%.4f %d", price, cnt );
    return 0;
}
