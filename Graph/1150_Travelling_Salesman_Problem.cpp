#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define MAX 0x3fffffff // 不可达
using namespace std;
int G[202][202] = { 0 }; // 图
vector<bool> hashTable; // 标记城市是否已访问过
void Check( const int &N, const int &now, int &MIN, int &num ) {
    int n, sum = 0;
    bool flag = true; // 标记路径是否能走通
    scanf( "%d", &n ); 
    vector<int> v( n );
    set<int> s; // set的size可以检查是否所有城市都访问过
    for( int i = 0; i < n; i++ ) {
        scanf( "%d", &v[i] );
        s.insert( v[i] );
        if( i != 0 ) {
            sum += G[v[i - 1]][v[i]];
            if( G[v[i - 1]][v[i]] == 0 )
                flag = false;
        }
    }
    if( !flag ) {
        printf( "NA (Not a TS cycle)\n" );
    } else if( v[0] != v[n - 1] || s.size( ) != N ) {
        printf( "%d (Not a TS cycle)\n", sum );
    } else {
        if( MIN > sum ) {
            MIN = sum;
            num = now;
        }
        if( n == N + 1 ) {
            printf( "%d (TS simple cycle)\n", sum );
        } else {
            printf( "%d (TS cycle)\n", sum );
        }
    }
}

int main( ) {
    int N, M, K, MIN = MAX, num = 1;
    cin >> N >> M;
    hashTable.resize( N + 1 );
    for( int i = 0, v1 = 0, v2 = 0, d = 0; i < M; i++ ) {
        scanf( "%d %d %d", &v1, &v2, &d );
        G[v1][v2] = G[v2][v1] = d;
    }
    cin >> K;
    for( int i = 0, temp = 0; i < K; i++ ) {
        fill( hashTable.begin( ), hashTable.end( ), false );
        printf( "Path %d: ", i + 1 );
        Check( N, i + 1, MIN, num );
    }
    printf( "Shortest Dist(%d) = %d", num, MIN );
    return 0;
}
