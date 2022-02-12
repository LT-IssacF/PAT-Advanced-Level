#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 30010
using namespace std;
struct student {
    char id[15];
    int score;
    int location_num; // 考场号
    int local_rank; // 本考场排名
    int final_rank; // 全场排名
} stu[MAX];

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
        sort( stu + ( total - K ), stu + total, cmp ); // 单独考场排序
        stu[total - K].local_rank = 1; // 每个考场的第一名
        for( int i = 0; i < K;i++ ) { // 获得本考场排名
            if( stu[total - K + i + 1].score == stu[total - K + i].score )
                stu[total - K + i + 1].local_rank = stu[total - K + i].local_rank;
            else
                stu[total - K + i + 1].local_rank = i + 2;
        }
    }
    sort( stu, stu + total, cmp ); // 所有考生排名
    stu[0].final_rank = 1; // 总排名第一名
    for( int i = 1; i < total; i++ ) { // 获得总排名
        if( stu[i].score == stu[i - 1].score )
            stu[i].final_rank = stu[i - 1].final_rank;
        else
            stu[i].final_rank = i + 1;
    }
    cout << total << endl;
    for( int i = 0; i < total; i++ )
        printf( "%s %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].location_num, stu[i].local_rank );
    return 0;
}