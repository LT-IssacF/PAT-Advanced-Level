#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;
// 和1142_Maximal_Clique那道题一模一样，把题读懂，20分钟AC
int main( ) {
    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> relations( N + 1 );
    for( int i = 0, a = 0, b = 0; i < M; i++ ) {
        scanf( "%d %d", &a, &b );
        relations[a].push_back( b ), relations[b].push_back( a ); // 所有首脑的关系
    }
    cin >> K;
    for( int i = 1, L = 0; i <= K; i++ ) {
        scanf( "%d", &L );
        unordered_set<int> hashTable;
        for( int j = 0, a = 0; j < L; j++ ) {
            scanf( "%d", &a );
            hashTable.insert( a ); // 标记到场的首脑
        }
        bool isClique = true;
        for( const auto &a : hashTable ) { // 检查到场的所有首脑
            int cnt = 0; // 关系计数器
            for( const auto &b : relations[a] )  // 检查当前首脑的所有关系
                if( hashTable.find( b ) != hashTable.end( ) ) // 如果他与在场的其他首脑有关系
                    cnt++;
            if( cnt < L - 1 ) { // 他与在场的某个首脑并没有关系
                isClique = false;
                break;
            }
        }
        if( isClique == true ) { // 在场的首脑各自都是朋友，是否可以再邀请一个所有人的朋友
            int ans = 0;
            for( int j = 1; j <= N; j++ ) { // 从最小的编号开始寻找
                if( hashTable.find( j ) == hashTable.end( ) ) { // 不在场的
                    int cnt = 0;
                    for( const auto &a : relations[j] ) // 遍历他的关系
                        if( hashTable.find( a ) != hashTable.end( ) )
                            cnt++;
                    if( cnt == L ) { // 他与在场的所有首脑都是朋友，可以加入
                        ans = j;
                        break;
                    }
                }
            }
            if( ans > 0 ) {
                printf( "Area %d may invite more people, such as %d.\n", i, ans );
            } else {
                printf( "Area %d is OK.\n", i );
            }
        } else {
            printf( "Area %d needs help.\n", i );
        }
    }
    return 0;
}
