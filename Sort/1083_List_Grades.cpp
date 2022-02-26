#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Record {
    char name[11] = { '\0' }, id[11] = { '\0' };
    int score;
};

int main( ) {
    int N, low = 0, high = 0;
    cin >> N;
    vector<Record> stu( N );
    for( int i = 0; i < N; i++ )
        scanf( "%s %s %d", &stu[i].name, &stu[i].id, &stu[i].score );
    cin >> low >> high;
    sort( stu.begin( ), stu.end( ), [] ( const Record &a, const Record &b ) {
        return a.score > b.score;
    } );
    bool flag = false;
    for( const auto i : stu )
        if( i.score >= low && i.score <= high ) {
            flag = true;
            printf( "%s %s\n", i.name, i.id );
        }
    if( flag == false )
        printf( "NONE" );
    return 0;
}
