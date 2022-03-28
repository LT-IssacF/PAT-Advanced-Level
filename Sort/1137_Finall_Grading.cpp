#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct Record {
    string id;
    int program_score = 0, mid_score = -1, final_score = 0, score = 0;
    bool certificate = false; // 有无资格获得证书
};
vector<Record> stu;
unordered_map<string, int> excel; // id与在stu数组中序号的映射
bool cmp( const Record &a, const Record &b ) {
    if( a.certificate != b.certificate ) { // 有证书的排前面，没证书的排后面
        return a.certificate > b.certificate;
    } else if( a.score != b.score ) { // 比最终成绩
        return a.score > b.score;
    } else { // 比id的字典序
        return a.id < b.id;
    }
}

int main( ) {
    int P, M, N, cnt = 0;
    cin >> P >> M >> N;
    stu.resize( P ); // 必需有平台上的编程成绩才有可能获得证书
    for( int i = 0; i < P; i++ ) {
        cin >> stu[i].id >> stu[i].program_score;
        excel[stu[i].id] = i; // 建立映射
    }
    string id;
    for( int i = 0, score = 0; i < M; i++ ) {
        cin >> id >> score;
        auto it = excel.find( id );
        if( it != excel.end( ) ) // 只有有编程成绩后面的卷面成绩才有意义
            stu[it->second].mid_score = score;
    }
    for( int i = 0, score = 0; i < N; i++ ) {
        cin >> id >> score;
        auto it = excel.find( id );
        if( it != excel.end( ) ) // 只有有编程成绩后面的卷面成绩才有意义
            stu[it->second].final_score = score;
    }
    for( int i = 0; i < P; i++ ) {
        if( stu[i].program_score >= 200 ) { // 编程成绩至少200分
            stu[i].score = ( stu[i].final_score >= stu[i].mid_score ) ? stu[i].final_score : ( int )round( stu[i].mid_score * 0.4 + stu[i].final_score * 0.6 );
            if( stu[i].score >= 60 ) { // 就有资格获得证书了
                stu[i].certificate = true;
                cnt++; // 人数+1
            }
        } // 最终成绩 = ( 期末成绩 >= 期中成绩 ) ? 期末成绩 : ( 期中成绩的40% +  期末成绩的60% )
    }
    sort( stu.begin( ), stu.end( ), cmp );
    for( int i = 0; i < cnt; i++ )
        cout << stu[i].id << " " << stu[i].program_score << " " << stu[i].mid_score << " " << stu[i].final_score << " " << stu[i].score << endl;
    return 0;
}
