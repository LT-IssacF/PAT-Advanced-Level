#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> relations;
// 和1142_Maximal_Clique那道题一模一样，把题读懂，20分钟AC
int main( ) {
    int N, M, K;
    cin >> N >> M;
    relations.resize( N + 1 );
    for( int i = 0, v1 = 0, v2 = 0; i < M; i++ ) {
        scanf( "%d %d", &v1, &v2 );
        relations[v1].push_back( v2 );
        relations[v2].push_back( v1 );
    }
    cin >> K;
    for( int i = 1, L = 0; i <= K; i++ ) {
        scanf( "%d", &L );
        unordered_map<int, bool> hashTable;
        bool isClique = true;
        int ans = 0;
        for( int j = 0, v = 0; j < L; j++ ) {
            scanf( "%d", &v );
            hashTable[v] = true;
        }
        for( int j = 1; j <= N; j++ )
            if( hashTable[j] == true ) {
                int cnt = 0;
                for( int k = 0; k < relations[j].size( ); k++ )
                    if( hashTable[relations[j][k]] == true )
                        cnt++;
                if( cnt != L - 1 ) {
                    isClique = false;
                    break;
                }
            }
        if( isClique ) {
            for( int j = 1; j <= N; j++ )
                if( hashTable[j] == false ) {
                    int cnt = 0;
                    for( int k = 0; k < relations[j].size( ); k++ )
                        if( hashTable[relations[j][k]] == true )
                            cnt++;
                    if( cnt == L ) {
                        ans = j;
                        break;
                    }
                }
        }
        if( isClique ) {
            if( ans == 0 ) {
                printf( "Area %d is OK.\n", i );
            } else {
                printf( "Area %d may invite more people, such as %d.\n", i, ans );
            }
        } else {
            printf( "Area %d needs help.\n", i );
        }
    }
    return 0;
}
