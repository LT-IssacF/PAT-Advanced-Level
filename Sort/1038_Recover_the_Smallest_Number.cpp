#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main( ) {
    int N;
    cin >> N;
    vector<string> v;
    string temp, ans;
    for( int i = 0; i < N; i++ ) {
        cin >> temp;
        v.emplace_back( temp );
    }
    sort( v.begin( ), v.end( ), [] ( const string &a, const string &b ) {
        return a + b < b + a;
    } );
    for( int i = 0; i < N; i++ )
        ans += v[i];
    while( ans.length( ) > 0 && ans[0] == '0' )
        ans.erase( ans.begin( ) );
    cout << ( ans.length( ) > 0 ? ans : 0 );
    return 0;
}
