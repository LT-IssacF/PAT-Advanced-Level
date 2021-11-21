#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct node {
    int data;
    vector<int> v;
};
vector<node> G; // 邻接表
set<int> ans; // 如果结点的data符合条件了，set的的大小就是结果

int main( ) {
    int N, M, K;
    cin >> N >> M;
    G.resize( N );
    for( int i = 0, c1 = 0, c2 = 0; i < M; i++ ) {
        cin >> c1 >> c2;
        G[c1].v.push_back( c2 );
        G[c2].v.push_back( c1 );
    }
    cin >> K;
    for( int i = 0, j = 0, temp = 0; i < K; i++ ) { // 要检查i遍
        for( j = 0; j < N; j++ ) { // 依结点次序挨个填入颜色即data
            cin >> temp;
            G[j].data = temp;
            ans.insert( temp ); // 同时记录不相同的颜色
        }
        bool flag = true;
        for( j = 0; j < N; j++ ) {
            int size = G[j].v.size( );
            for( int k = 0, v = 0; k < size; k++ ) {
                v = G[j].v[k];
                if( G[v].data == G[j].data ) { // 如果相邻的两个结点颜色相同则不符合条件
                    flag = false;
                    break;
                }
            }
            if( !flag )
                break;
        }
        if( flag )
            cout << ans.size( ) << "-coloring" << endl;
        else
            cout << "No" << endl;
        ans.clear( ); // 清空数据开始下一遍检查
    }
    return 0;
}