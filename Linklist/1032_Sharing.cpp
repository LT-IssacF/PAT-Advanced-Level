#include <iostream>
#include <cstdio>
#define MAX 100020
using namespace std;
struct node {
    int next;
    char data;
    bool flag = false;
} list[MAX];

int main( ) {
    int start, start2, N;
    cin >> start >> start2 >> N;
    for( int i = 0, address = 0; i < N; i++ ) {
        scanf( "%d ", &address );
        scanf( "%c %d", &list[address].data, &list[address].next );
        char c = getchar( );
    }
    int p = start;
    while( p != -1 ) { // 遍历第一条链表
        list[p].flag = true; // 标记
        p = list[p].next;
    }
    p = start2;
    while( p != -1 && list[p].flag == false ) {
        p = list[p].next;
    } // 此结点在第一次遍历就标记了说明为结果
    if( p == -1 ) {
        cout << -1;
    } else {
        printf( "%05d", p );
    }
    return 0;
}
