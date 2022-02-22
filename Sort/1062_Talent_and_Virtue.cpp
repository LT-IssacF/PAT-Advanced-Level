#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Record {
    string id;
    int virtue, talent, total, tag; // tag标记属于哪一类
};

int main( ) {
    int N, L, H;
    cin >> N >> L >> H;
    vector<Record> people;
    for( int i = 0, virtue = 0, talent = 0, tag = 0; i < N; i++ ) {
        string id;
        cin >> id >> virtue >> talent;
        if( virtue >= L && talent >= L ) { // 都过最低线才有资格排
            if( virtue >= H ) {
                if( talent >= H ) { // 圣人
                    tag = 0;
                } else { // 君子
                    tag = 1;
                }
            } else {
                if( virtue >= talent ) { // 庸人
                    tag = 2;
                } else { // 小人
                    tag = 3;
                }
            }
        } else { // 没过线的
            tag = -1;
        }
        if( tag >= 0 )
            people.emplace_back( Record{ id, virtue, talent, virtue + talent, tag } );
    }
    sort( people.begin( ), people.end( ), [] ( const Record &a, const Record &b ) {
        if( a.tag != b.tag ) { // 人以群分
            return a.tag < b.tag; // 圣人>君子>庸人>小人
        } else if( a.total != b.total ) { // 同类人就按总分排
            return a.total > b.total;
        } else if( a.virtue != b.virtue ) { // 总分相同就按品德排
            return a.virtue > b.virtue;
        } else { // 再相同就按考号按升序排
            return a.id < b.id;
        }
    } );
    cout << people.size( ) << endl;
    for( const auto &i : people )
        printf( "%s %d %d\n", i.id.c_str( ), i.virtue, i.talent );
    return 0;
}
