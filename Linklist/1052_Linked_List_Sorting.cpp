#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node {
    int Address, Data, Next;
    bool Flag; // Flag标记结点是否在链上
    Node( ) {
        Flag = false;
    }
} Temp[100020];

bool cmp( Node a, Node b ) {
    if( !a.Flag || !b.Flag )
        return a.Flag > b.Flag; // 不在链上的排最后
    else
        return a.Data < b.Data;
}

int main( ) {
    int N, head;
    cin >> N >> head;
    for( int i = 0, Temp_Add = 0; i < N; i++ ) {
        cin >> Temp_Add;
        Temp[Temp_Add].Address = Temp_Add;
        cin >> Temp[Temp_Add].Data >> Temp[Temp_Add].Next;
    }
    int p = head, cnt = 0;
    while( p != -1 ) { // 遍历链表，标记哪些结点在链上
        Temp[p].Flag = true;
        p = Temp[p].Next;
        cnt++;
    }
    if( cnt == 0 )
        cout << "0 -1";
    else {
        sort( Temp, Temp + 100020, cmp );
        head = Temp[0].Address;
        for( int i = 0; i < cnt - 1; i++ ) // 更改结点的Next域
            Temp[i].Next = Temp[i + 1].Address;
        Temp[cnt - 1].Next = -1;
        printf( "%d %05d", cnt, Temp[0].Address );
        for( int i = 0; i < cnt; i++ ) {
            if( Temp[i].Next == -1 )
                printf( "%05d %d -1", Temp[i].Address, Temp[i].Data );
            else
                printf( "%05d %d %05d\n", Temp[i].Address, Temp[i].Data, Temp[i].Next );
        }
    }
    return 0;
}
