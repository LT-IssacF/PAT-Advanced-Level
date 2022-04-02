#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct Record {
    string id, birth_date;
    bool flag;
};
unordered_map<string, bool> isAlumnus;

int main( ) {
    int N, M, cnt = 0;
    cin >> N;
    vector<Record> alumnus( N );
    for( int i = 0; i < N; i++ ) {
        cin >> alumnus[i].id;
        alumnus[i].birth_date = alumnus[i].id.substr( 6, 8 );
        isAlumnus[alumnus[i].id] = true;
    }
    cin >> M;
    vector<Record> guest( M );
    for( int i = 0; i < M; i++ ) {
        cin >> guest[i].id;
        guest[i].birth_date = guest[i].id.substr( 6, 8 );
        if( isAlumnus[guest[i].id] == true ) {
            guest[i].flag = true;
            cnt++;
        }
    }
    cout << cnt << endl;
    if( cnt > 0 ) {
        sort( alumnus.begin( ), alumnus.end( ), [] ( const Record &a, const Record &b ) {
            return a.birth_date < b.birth_date;
            } );
    } else {
        sort( guest.begin( ), guest.end( ), [] ( const Record &a, const Record &b ) {
            if( a.flag != b.flag ) {
                return a.flag > b.flag;
            } else {
                return a.birth_date < b.birth_date;
            }
            } );
    }
    cout << ( cnt != 0 ? alumnus[0].id : guest[0].id );
    return 0;
}
