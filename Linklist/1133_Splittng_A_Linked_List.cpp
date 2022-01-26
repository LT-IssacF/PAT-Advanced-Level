#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int data, next;
} list[100020];
// 整个链表的结构应该是( <0, 0 ~ K, K< )
int main( ) {
    int start, N, K;
    cin >> start >> N >> K;
    for( int i = 0, address = 0, data = 0, next = 0; i < N; i++ ) {
        scanf( "%d %d %d", &address, &data, &next );
        list[address].data = data, list[address].next = next;
    }
    vector<vector<int>> v( 3 ); // 分别保存3部分
    for( int p = start; p != -1; p = list[p].next ) {
        if( list[p].data < 0 )
            v[0].push_back( p );
        else if( list[p].data >= 0 && list[p].data <= K )
            v[1].push_back( p );
        else
            v[2].push_back( p );
    }
    bool isHead = true;
    for( int i = 0; i < 3; i++ ) {
        for( int j = 0; j < v[i].size( ); j++ ) {
            if( isHead ) {
                printf( "%05d %d ", v[i][j], list[v[i][j]].data );
                isHead = false;
            }
            else
                printf( "%05d\n%05d %d ", v[i][j], v[i][j], list[v[i][j]].data );
        }
    }
    cout << -1;
    return 0;
} // 柳神真的太强了
