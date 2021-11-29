#include <iostream>
#include <cstdio>
using namespace std;
// 静态链表类
struct Node {
    int Next;
    char Data;
    bool Flag; // 用来标记结点是否在链上
    Node( ) {
        Flag = false;
    }
} Temp[100020]; // 下标作为本结点的地址

int main( ) {
    int A_start, B_start, N;
    cin >> A_start >> B_start >> N;
    int Address = 0, next = 0;
    char data = '0';
    for( int i = 0; i < N; i++ ) {
        scanf( "%d %c %d", &Address, &data, &next );
        Temp[Address].Data = data;
        Temp[Address].Next = next;
    }
    int p = A_start;
    while( p != -1 ) { // 单遍历第一条链表
        Temp[p].Flag = true;
        p = Temp[p].Next;
    }
    for( p = B_start; p != -1; p = Temp[p].Next )
        if( Temp[p].Flag == true ) // 此结点在第一次遍历就标记了说明为结果
            break;
    if( p != -1 )
        printf( "%05d", p );
    else
        cout << "-1";
    return 0;
}
