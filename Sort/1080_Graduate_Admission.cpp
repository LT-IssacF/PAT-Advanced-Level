#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Record {
    int id, GE, GI, GF, rank;
    vector<int> prefers;
};

int main( ) {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> quotas( M );
    for( int i = 0; i < M; i++ )
        scanf( "%d", &quotas[i] );
    vector<Record> stu( N );
    for( int i = 0; i < N; i++ ) {
        scanf( "%d %d", &stu[i].GE, &stu[i].GI );
        stu[i].id = i, stu[i].GF = stu[i].GE + stu[i].GI;
        for( int j = 0, p = 0; j < K; j++ ) {
            scanf( "%d", &p );
            stu[i].prefers.emplace_back( p );
        }
    }
    sort( stu.begin( ), stu.end( ), [] ( const Record &a, const Record &b ) {
        if( a.GF != b.GF ) {
            return a.GF > b.GF;
        } else if( a.GE != b.GE ) {
            return a.GE > b.GE;
        } else {
            return a.id < b.id; // 按id排一下好看点
        }
    } );
    vector<vector<int>> schools( M ); // set没有back函数，不然用set就很方便了
    stu[0].rank = 1;
    for( int i = 0; i < K; i++ )
        if( quotas[stu[0].prefers[i]] > 0 ) {
            schools[stu[0].prefers[i]].emplace_back( stu[0].id );
            quotas[stu[0].prefers[i]]--;
            break;
        }
    for( int i = 1; i < N; i++ ) {
        if( stu[i].GF == stu[i - 1].GF && stu[i].GE == stu[i - 1].GE ) {
            stu[i].rank = stu[i - 1].rank;
        } else {
            stu[i].rank = i + 1;
        } // 先获取排名
        for( int j = 0; j < K; j++ )
            if( quotas[stu[i].prefers[j]] > 0 || stu[i].rank == stu[schools[stu[i].prefers[j]].back( )].rank ) {
                schools[stu[i].prefers[j]].emplace_back( stu[i].id );
                quotas[stu[i].prefers[j]]--;
                break;
            } // 要么还有名额要么就是要和要去学校的最后一名比排名相等
    }
    for( int i = 0; i < M; i++ ) {
        if( schools[i].size( ) > 1 ) // 大于等于2人时排序才有意义
            sort( schools[i].begin( ), schools[i].end( ) );
        for( int j = 0; j < schools[i].size( ); j++ ) {
            if( j > 0 )
                printf( " " );
            printf( "%d", schools[i][j] );
        }
        printf( "\n" );
    }
    return 0;
}