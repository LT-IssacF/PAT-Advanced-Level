#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 0x1fffffff
using namespace std;
struct node {
    int address, data, next, order;
    node( ) { // 初始顺序为2 * INF
        order = 2 * MAX;
    }
} list[100020];
bool visit[10020] = { false }; // 相当于哈希表

int main( ) {
    int start, N;
    cin >> start >> N;
    for( int i = 0, a = 0; i < N; i++ ) {
        cin >> a;
        cin >> list[a].data >> list[a].next;
        list[a].address = a;
    }
    int s = start, cnt = 0, validCnt = 0, delNum = MAX; // 要删除的多余重复结点的顺序从MAX开始重新编号
    while( s != -1 ) { // 遍历单链表
        if( visit[abs( list[s].data )] == false ) { // data第一次出现
            list[s].order = ++validCnt; // 标记结点在链表中的顺序
            visit[abs( list[s].data )] = true; // 标记data
        }
        else // 重复的
            list[s].order = ++delNum;
        cnt++; // 在链表上的结点的个数
        s = list[s].next;
    }
    sort( list, list + 100020,
        [] ( node a, node b ) {
            return a.order < b.order;
        } ); // 在链上的结点从1开始排，重复的从INF开始排，不在链上的排在最后
    for( int i = 0; i < cnt; i++ ) { // 仅输出在链上的
        if( i == validCnt - 1 || i == cnt - 1 ) { // 不重复的或重复的的最后一个结点
            printf( "%05d %d -1\n", list[i].address, list[i].data );
        }
        else {
            printf( "%05d %d %05d\n", list[i].address, list[i].data, list[i + 1].address );
        }
    }
    return 0;
}
