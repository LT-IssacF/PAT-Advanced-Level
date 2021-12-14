#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max 320
using namespace std;
struct student {
    char id[13];
    int score;
    int location_num; // 考场号
    int local_rank; // 本考场排名
    int final_rank; // 全场排名
} stu[max];

bool cmp( student a, student b ) {
    if( a.score != b.score )
        return a.score > b.score;
    else
        return strcmp( a.id, b.id ) < 0;
}

int main() {
    int N, K, total = 0; // 考生总数
    cin >> N;
    for( int location = 1; location <= N; location++ ) {
        cin >> K;
        for( int person = 0; person < K; person++ ) {
            cin >> stu[total].id >> stu[total].score;
            stu[total].location_num = location;
            total++;
        }
        sort( stu + total - K, stu + total, cmp ); // 单独考场排序
        stu[total - K].local_rank = 1; // 每个考场的第一名
        for( int i = total - K + 1, rank = 2; i < total; i++, rank++ ) { // 获得本考场排名
            if( stu[i].score == stu[i - 1].score )
                stu[i].local_rank = stu[i - 1].local_rank;
            else
                stu[i].local_rank = rank;
        }
    }
    sort( stu, stu + total, cmp ); // 所有考生排名
    stu[0].final_rank = 1; // 总排名第一名
    for( int i = 1, rank = 2; i < total; i++, rank++ ) { // 获得总排名
        if( stu[i].score == stu[i - 1].score )
            stu[i].final_rank = stu[i - 1].final_rank;
        else
            stu[i].final_rank = rank;
    }
    cout << total << endl;
    for( int i = 0; i < total; i++ ) {
        printf( "%s %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].location_num, stu[i].local_rank );
    }
    return 0;
}
