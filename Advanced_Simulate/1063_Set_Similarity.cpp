#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main( ) {
    int N, K;
    cin >> N;
    vector<set<int>> sets( N );
    for( int i = 0, M = 0; i < N; i++ ) {
        scanf( "%d", &M );
        for( int j = 0, value = 0; j < M; j++ ) {
            scanf( "%d", &value );
            sets[i].insert( value );
        }
    }
    cin >> K;
    for( int i = 0, set1 = 0, set2 = 0, unionSize = 0, mergeSize = 0; i < K; i++ ) {
        scanf( "%d %d", &set1, &set2 );
        set1--, set2--; // 下标问题
        unionSize = sets[set1].size( ) + sets[set2].size( ), mergeSize = 0;
        for( const auto &it : sets[set1] ) // 枚举第一个集合的每一个元素
            if( sets[set2].find( it ) != sets[set2].end( ) ) // 在第二个集合里找到了交集+1
                mergeSize++;
        unionSize -= mergeSize; // 并集先减去重复的交集
        printf( "%.1f%\n", ( 1.0 * mergeSize / unionSize ) * 100 );
    }
    return 0;
}