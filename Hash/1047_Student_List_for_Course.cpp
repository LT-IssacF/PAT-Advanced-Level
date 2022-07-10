#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char name[40020][5] = { '\0' };

int main( ) {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> list( K );
    for( int i = 0, cnt = 0; i < N; i++ ) {
        scanf( "%s %d", &name[i], &cnt );
        for( int j = 0, course = 0; j < cnt; j++ ) {
            scanf( "%d", &course );
            list[course - 1].push_back( i );
        }
    }
    for( int i = 0; i < K; i++ ) {
        printf( "%d %d\n", i + 1, list[i].size( ) );
        sort( list[i].begin( ), list[i].end( ), [] ( const int &a, const int &b ) {
            return strcmp(  name[a], name[b] ) < 0;
        } );
        for( const int &i : list[i] )
            printf( "%s\n", name[i] );
    }
    return 0;
}
