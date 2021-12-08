#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int Address, Data, Next;
    int Num; // 结点在链表中的序号
    node( ) {
        Num = 0x7fffffff;
    }
} list[100020];

bool cmp( node a, node b ) {
    return a.Num < b.Num;
}

int main( ) {
    int head, N, K;
    cin >> head >> N >> K;
    for( int i = 0, address = 0; i < N; i++ ) {
        cin >> address;
        cin >> list[address].Data >> list[address].Next;
        list[address].Address = address;
    }
    int cnt = 0;
    while( head != -1 ) { // 遍历单链表
        list[head].Num = cnt++;
        head = list[head].Next;
    }
    sort( list, list + 100020, cmp ); // 不在链表上的无效结点排在最后
    int round = cnt / K, remainder = cnt % K; // round为需要逆转的组数，remainder为最后不构成一组的结点
    // 链表结构本身不需要逆转，只需要从每组最后一个结点开始倒着输出一个小组的地址域
    // 直到这个组的第一个结点需要做特殊处理，即最后一个结点的Next域需要根据当前组数判断是否正常输出下个组的最后一个结点的地址域
    for( int i = 0, j = 0, k = 0; i < round; i++ ) {
        for( j = ( i + 1 ) * K - 1; j >= i * K + 1; j-- )
            printf( "%05d %d %05d\n", list[j].Address, list[j].Data, list[j - 1].Address );
        printf( "%05d %d", list[j].Address, list[j].Data );
        if( i < round - 1 ) // 不是最后那组，正常输出逆转小组的下一个小组的最后一个结点的地址域
            printf( " %05d\n", list[( i + 2 ) * K - 1].Address );
        else { // 非常情况
            if( remainder == 0 ) // 正好分完每个组，没有余下的结点
                cout << " -1";
            else { // 余下的不用逆转，从前往后正常输出
                printf( " %05d\n", list[( i + 1 ) * K].Address );
                for( k = ( i + 1 ) * K; k < cnt - 1; k++ )
                    printf( "%05d %d %05d\n", list[k].Address, list[k].Data, list[k + 1].Address );
                printf( "%05d %d -1", list[k].Address, list[k].Data );
            }
        }
    }
    return 0;
}
