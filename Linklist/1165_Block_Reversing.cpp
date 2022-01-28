#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int address, data, next;
} origin[100020];

int main( ) {
    int start, N, K;
    cin >> start >> N >> K;
    for( int i = 0, add = 0; i < N; i++ ) {
        scanf( "%d", &add );
        origin[add].address = add;
        scanf( "%d %d", &origin[add].data, &origin[add].next );
    }
    vector<node> list;
    while( start != -1 ) { // 储存在链上的结点
        list.emplace_back( origin[start] );
        start = origin[start].next;
    }
    int blocks = list.size( ) / K, remnants = list.size( ) % K, end = list.size( ) - 1, p;
    if( remnants > 0 ) { // 处理多余的结点
        for( start = blocks * K; start < end; start++ )
            printf( "%05d %d %05d\n", list[start].address, list[start].data, list[start + 1].address );
        printf( "%05d %d %05d\n", list[start].address, list[start].data, list[start - remnants - K + 1].address );
    }
    for( int i = 0; i < blocks; i++ ) { // 分块处理
        start = ( blocks - i - 1 ) * K;
        end = start + K - 1;
        for( p = start; p < end; p++ ) // 处理每块的非最后一个结点
            printf( "%05d %d %05d\n", list[p].address, list[p].data, list[p + 1].address );
        if( i != blocks - 1 ) { // 非首块的最后的结点
            printf( "%05d %d %05d\n", list[p].address, list[p].data, list[start - K].address );
        } else { // 首块的最后一个结点
            printf( "%05d %d -1\n", list[p].address, list[p].data );
        }
    }
    return 0;
}
