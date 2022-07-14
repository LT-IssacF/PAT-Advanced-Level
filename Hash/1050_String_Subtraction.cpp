#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 10020
using namespace std;

int main( ) {
    char s1[MAX], s2[MAX];
    cin.getline( s1, MAX - 1 );
    cin.getline( s2, MAX - 1);
    bool hash[128] = { false };
    int length1 = strlen( s1 ), length2 = strlen( s2 );
    for( int i = 0; i < length2; i++ )
        hash[s2[i]] = true;
    for( int i = 0; i < length1; i++ )
        if( hash[s1[i]] == false )
            printf( "%c", s1[i] );
    return 0;
}
