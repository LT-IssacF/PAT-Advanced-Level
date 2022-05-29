#include <iostream>
using namespace std;
inline bool IsPrime( const int &key ) {
    for( int i = 2; i * i <= key; i++ )
        if( key % i == 0 )
            return false;
    return key >= 2 ? true : false; 
}

int main( ) {
    int N;
    cin >> N;
    if( IsPrime( N ) && ( IsPrime( N - 6 ) || IsPrime( N + 6 ) ) ) {
        cout << "Yes" << endl << ( IsPrime( N - 6 ) ? N - 6 : N + 6 );
    } else {
        cout << "No" << endl;
        for( int i = N + 1; ; i++ )
            if( IsPrime( i ) && ( IsPrime( i - 6 ) || IsPrime( i + 6 ) ) ) {
                cout << i;
                break;
            }
    }
    return 0;
}
