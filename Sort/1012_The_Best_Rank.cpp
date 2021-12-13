#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 0x3fffffff
using namespace std;
struct student {
    string ID;
    int grade[4]; // A C M E
    int rank[4];
};
vector<student> stu;

int main( ) {
    int N, M;
    cin >> N >> M;
    stu.resize( N );
    for( int i = 0, j = 0, total = 0; i < N; i++ ) {
        cin >> stu[i].ID;
        for( j = 1, total = 0; j < 4; j++ ) {
            cin >> stu[i].grade[j];
            total += stu[i].grade[j];
        }
        stu[i].grade[0] = round( total / 3.0 ); // 下标0存放A
    }
    vector<string> check( M );
    for( int i = 0; i < M; i++ )
        cin >> check[i];
    for( int tag = 0; tag < 4; tag++ ) { // 获取4门成绩的排名
        sort( stu.begin( ), stu.end( ),
            [tag] ( student a, student b ) { // 按每门成绩降序排序
                return a.grade[tag] > b.grade[tag];
                } );
        stu[0].rank[tag] = 1; // 最高分第一名
        for( int j = 1; j < N; j++ ) {
            if( stu[j].grade[tag] == stu[j - 1].grade[tag] )
                stu[j].rank[tag] = stu[j - 1].rank[tag];
            else
                stu[j].rank[tag] = j + 1;
        }
    }
    for( int i = 0, j = 0, k = 0, min = MAX, flag = MAX; i < M; i++ ) {
        min = MAX, flag = MAX;
        for( j = 0; j < N; j++ ) {
            if( check[i] == stu[j].ID ) {
                for( k = 0; k < 4; k++ ) {
                    if( min > stu[j].rank[k] ) { // 找4门成绩中排名最高的
                        min = stu[j].rank[k];
                        flag = k + 1; // 标记
                    }
                }
                cout << min << " ";
                if( flag == 1 ) cout << "A";
                else if( flag == 2 ) cout << "C";
                else if( flag == 3 ) cout << "M";
                else cout << "E";
                cout << '\n';
                break; // 退出找这个学生的循环
            }
            if( j == N - 1 ) // 没这个学生
                cout << "N/A" << endl;
        }
    }
    return 0;
}
