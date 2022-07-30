#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main( ) {
    string goods, owns;
    cin >> goods >> owns;
    int absent = 0;
    unordered_map<char, int> m;
    for( int i = 0; i < goods.length( ); i++ )
        m[goods[i]]++;
    for( int i = 0; i < owns.length( ); i++ )
        if( m[owns[i]] > 0 ) {
            m[owns[i]]--;
        } else {
            absent++;
        }
    if( absent == 0 ) {
        cout << "Yes " << goods.length( ) - owns.length( );
    } else {
        cout << "No " << absent;
    }
    return 0;
}
