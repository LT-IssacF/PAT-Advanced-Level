#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100020
using namespace std;
int couple[MAX]; // 配偶表
bool come[MAX] = { false }; // 来没来

int main( ) {
    int N, M;
    cin >> N;
    fill( couple, couple + MAX, -1 );
    for( int i = 0, husband = 0, wife = 0; i < N; i++ ) {
        scanf( "%d %d", &husband, &wife );
        couple[husband] = wife;
        couple[wife] = husband;
    }
    cin >> M;
    vector<int> single, guest( M );
    for( int i = 0; i < M; i++ ) {
        scanf( "%d", &guest[i] );
        come[guest[i]] = true;
    }
    for( int i = 0; i < M; i++ )
        if( couple[guest[i]] == -1 || come[couple[guest[i]]] == false ) // 铁打的单身狗或已婚人士的配偶没来
            single.push_back( guest[i] );
    sort( single.begin( ), single.end( ) );
    printf( "%d\n", single.size( ) );
    if( single.size( ) > 0 )
        printf( "%05d", single[0] );
    for( int i = 1; i < single.size( ); i++ )
        printf( " %05d", single[i] );
    return 0;
}
