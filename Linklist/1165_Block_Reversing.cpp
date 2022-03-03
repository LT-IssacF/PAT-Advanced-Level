#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int address, data, next;
} list[100020];

int main( ) {
    int start, N, K;
    cin >> start >> N >> K;
    for( int i = 0, add = 0, data = 0, next = 0; i < N; i++ ) {
        scanf( "%d %d %d", &add, &data, &next );
        list[add].address = add, list[add].data = data, list[add].next = next;
    }
    vector<node> ans; // 储存在链上的结点
    for( int p = start; p != -1; p = list[p].next )
        ans.emplace_back( list[p] );
    int blocks = ans.size( ) / K, remnants = ans.size( ) % K;
    if( remnants > 0 ) { // 处理多余的结点
        for( int i = ans.size( ) - remnants; i < ans.size( ) - 1; i++ )
            printf( "%05d %d %05d\n", ans[i].address, ans[i].data, ans[i + 1].address );
        printf( "%05d %d %05d\n", ans[ans.size( ) - 1].address, ans[ans.size( ) - 1].data, ans[( blocks - 1 ) * K].address );
    } // 题目说明至少会有一块，不用考虑不够一块的情况
    for( int i = blocks - 1, j = 0, cnt = 0; i >= 0; i-- ) { // 分块处理
        for( j = i * K, cnt = 0; cnt < K - 1; j++, cnt++ ) // 处理每块的非最后一个结点
            printf( "%05d %d %05d\n", ans[j].address, ans[j].data, ans[j + 1].address );
        if( i > 0 ) { // 非首块的最后的结点
            printf( "%05d %d %05d\n", ans[j].address, ans[j].data, ans[( i - 1 ) * K].address );
        } else { // 首块的最后一个结点
            printf( "%05d %d -1", ans[j].address, ans[j].data );
        }
    }
    return 0;
}
