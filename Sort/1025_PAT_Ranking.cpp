#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Record {
    char id[13];
    int grade, final_rank, location_number, local_rank;
} temp;

bool cmp( const Record &a, const Record &b ) {
    if( a.grade != b.grade ) {
        return a.grade > b.grade;
    } else {
        return strcmp( a.id, b.id ) < 0;
    }
}

int main( ) {
    int N;
    cin >> N;
    vector<Record> stu;
    for( int i = 0, K = 0; i < N; i++ ) {
        scanf( "%d", &K );
        char c = getchar( );
        for( int j = 0; j < K; j++ ) {
            scanf( "%s %d", &temp.id, &temp.grade );
            char c = getchar( );
            temp.location_number = i + 1;
            stu.emplace_back( temp );
        }
        vector<Record>::iterator it = stu.end( ) - K;
        sort( it, stu.end( ), cmp ); // 单独考场排序
        it++->local_rank = 1;
        for( int i = 1; i < K; i++, it++ ) {
            if( it->grade == ( it - 1 )->grade ) {
                it->local_rank = ( it - 1 )->local_rank;
            } else {
                it->local_rank = i + 1;
            }
        }
    }
    cout << stu.size( ) << endl;
    sort( stu.begin( ), stu.end( ), cmp ); // 所有考生排名
    stu[0].final_rank = 1;
    printf( "%s %d %d %d\n", stu[0].id, stu[0].final_rank, stu[0].location_number, stu[0].local_rank );
    for( int i = 1; i < stu.size( ); i++ ) {
        if( stu[i].grade == stu[i - 1].grade ) {
            stu[i].final_rank = stu[i - 1].final_rank;
        } else {
            stu[i].final_rank = i + 1;
        }
        printf( "%s %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].location_number, stu[i].local_rank );
    }
    return 0;
}
