#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct Record {
    string id;
    int programing = -1, mid = -1, final = -1, grade = -1;
};
// 题目中的final grade不是期末考试！！！
int main( ) {
    int P, M, N;
    cin >> P >> M >> N;
    string id;
    vector<Record> ans;
    unordered_map<string, Record> stu;
    for( int i = 0, grade = 0; i < P; i++ ) {
        cin >> id >> grade;
        if( grade > 900 ) {
            grade = 900;
        }
        stu[id].programing = grade;
    }
    for( int i = 0, grade = 0; i < M; i++ ) {
        cin >> id >> grade;
        if( grade > 100 ) {
            grade = 100;
        }
        stu[id].mid = grade;
    }
    for( int i = 0, grade = 0; i < N; i++ ) {
        cin >> id >> grade;
        if( grade > 100 ) {
            grade = 100;
        }
        stu[id].final = grade;
        if( stu[id].programing >= 200 ) { // 编程分数必须大于等于200
            if( stu[id].final >= stu[id].mid ) {
                stu[id].grade = stu[id].final;
            } else {
                stu[id].grade = stu[id].mid * 0.4 + stu[id].final * 0.6 + 0.5;
            }
            if( stu[id].grade >= 60 ) { // 最后final grade必须大于等于60
                stu[id].id = id;
                ans.emplace_back( stu[id] );
            }
        }
    }
    sort( ans.begin( ), ans.end( ), [] ( const Record &a, const Record &b ) {
        if( a.grade != b.grade ) {
            return a.grade > b.grade;
        } else {
            return a.id < b.id;
        }
    } );
    for( const Record &i : ans ) {
        printf( "%s %d %d %d %d\n", i.id.c_str( ), i.programing, i.mid, i.final, i.grade );
    }
    return 0;
}
