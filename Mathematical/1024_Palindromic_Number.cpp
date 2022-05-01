#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 0xff
using namespace std;
struct bign {
    int d[MAX] = { 0 }, len = 0;
};
bign Change( const char *str ) {
    bign a;
    for( int i = strlen( str ) - 1; i >= 0; i-- )
        a.d[a.len++] = str[i] - '0';
    return a;
}

void Add( bign &a ) {
    bign b = a;
    int carry = 0;
    for( int i = 0; i < a.len; i++ ) {
        carry += a.d[i] + b.d[b.len - i - 1];
        a.d[i] = carry % 10;
        carry /= 10;
    }
    if( carry > 0 )
        a.d[a.len++] = carry;
}

bool Judge( const bign &a ) {
    for( int i = 0, j = a.len - 1; i < j; i++, j-- )
        if( a.d[i] != a.d[j] )
            return false;
    return true;
}

int main( ) {
    char N[12] = { '\0' };
    int K, i = 0;
    scanf( "%s %d", N, &K );
    bign a = Change( N );;
    while( i < K && !Judge( a ) ) {
        Add( a );
        i++;
    }
    for( int i = a.len - 1; i >= 0; i-- )
        printf( "%d", a.d[i] );
    cout << endl << i;
    return 0;
}
