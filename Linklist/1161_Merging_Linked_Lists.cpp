#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int address, data, next;
} origin[100020];

int main( ) {
    int start, start2, N, p, q;
    cin >> start >> start2 >> N;
    for( int i = 0, add = 0; i < N; i++ ) {
        scanf( "%d", &add );
        origin[add].address = add;
        scanf( "%d %d", &origin[add].data, &origin[add].next );
    }
    vector<node> list, list2, ans; // 从origin中获得较长的链表，再从list2中获得较短的那条
    for( p = start; p != -1; p = origin[p].next )
        list.emplace_back( origin[p] );
    for( q = start2; q != -1; q = origin[q].next )
        list2.emplace_back( origin[q] );
    if( list.size( ) > list2.size( ) ) {
        p = start;
    } else { // 第二条链表比第一条长，就把短的放在list2
        p = start2;
        list2 = list;
    }
    for( q = 0; p != -1; p = origin[p].next ) { // 注意会出现长链表已遍历完但短链表还没有的情况，所以必需要用1+2的模式
        ans.emplace_back( origin[p] ); // 即第一次循环加入第一个长链表的结点，第二次循环加入第二个长链表的结点和一个短链表的结点
        if( ++q % 2 == 0 && !list2.empty( ) ) { // 每加入两个结点就加入一个list2的尾结点
            ans.emplace_back( list2.back( ) );
            list2.pop_back( );
        }
    }
    for( int i = 0; i < ans.size( ) - 1; i++ )
        printf( "%05d %d %05d\n", ans[i].address, ans[i].data, ans[i + 1].address );
    printf( "%05d %d -1", ans.back( ).address, ans.back( ).data );
    return 0;
}
