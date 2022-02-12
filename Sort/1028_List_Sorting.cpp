#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Record {
    char ID[20], name[20];
    int grade;
};
vector<Record> stu;
bool cmp_ID( const Record &a, const Record &b ) { // 按ID升序排序
    return strcmp( a.ID, b.ID ) < 0;
}
bool cmp_name( const Record &a, const Record &b ) {
    if( strcmp( a.name, b.name ) != 0 ) // 名字不同就按名字升序排序
        return strcmp( a.name, b.name ) < 0;
    else // 名字相同就按ID升序排序
        return strcmp( a.ID, b.ID ) < 0;
}
bool cmp_grade( const Record &a, const Record &b ) {
    if( a.grade != b.grade ) // 分数不同按分数升序排序
        return a.grade < b.grade;
    else // 同样的
        return strcmp( a.ID, b.ID ) < 0;
}
// 送分题
int main( ) {
    int N, C;
    cin >> N >> C;
    stu.resize( N );
    for( int i = 0; i < N; i++ )
        scanf( "%s %s %d", &stu[i].ID, &stu[i].name, &stu[i].grade );
    switch( C ) {
        case 1: sort( stu.begin( ), stu.end( ), cmp_ID ); break;
        case 2: sort( stu.begin( ), stu.end( ), cmp_name ); break;
        case 3: sort( stu.begin( ), stu.end( ), cmp_grade );
    }
    for( int i = 0; i < N; i++ )
        printf( "%s %s %d\n", stu[i].ID, stu[i].name, stu[i].grade );
    return 0;
}
