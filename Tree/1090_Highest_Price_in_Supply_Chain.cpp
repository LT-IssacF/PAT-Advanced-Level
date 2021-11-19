#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
vector<vector<int>> tree;
// 这题就是供应链那道的青春版
void DFS( int root, int layer, int &maxLevel, int &cnt ) {
    int size = tree[root].size( );
    if( size == 0 ) { // 到零售商了
        if( layer > maxLevel ) { // 经经销商更多的零售商
            maxLevel = layer;
            cnt = 1;
        }
        else if( layer == maxLevel ) { // 不止一个
            cnt++;
        }
        return;
    }
    for( int i = 0; i < size; i++ ) {
        DFS( tree[root][i], layer + 1, maxLevel, cnt );
    }
}

int main( ) {
    int N, root;
    double P, r;
    cin >> N >> P >> r;
    tree.resize( N );
    r /= 100;
    for( int i = 0, father = 0; i < N; i++ ) {
        cin >> father;
        if( father != -1 )
            tree[father].push_back( i );
        else
            root = i;
    }
    int maxLevel = 0, cnt = 0;
    DFS( root, 0, maxLevel, cnt );
    printf( "%.2f %d", P * pow( 1 + r, maxLevel ), cnt );
    return 0;
}