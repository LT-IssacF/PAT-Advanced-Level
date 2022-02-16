#include <iostream>
#include <cstdio>
using namespace std;

int main( ) {
    int K, cnt = 0;
    double coefficient, A[1020] = { 0 };
    cin >> K;
    for( int i = 0, exponent = 0; i < K; i++ ) {
        cin >> exponent >> coefficient;
        A[exponent] = coefficient;
    }
    cin >> K;
    for( int i = 0, exponent = 0; i < K; i++ ) {
        cin >> exponent >> coefficient;
        A[exponent] += coefficient;
    }
    for( int i = 0; i < 1020; i++ )
        if( A[i] != 0 )
            cnt++;
    cout << cnt;
    for( int i = 1010; i >= 0; i-- )
        if( A[i] != 0 )
            printf( " %d %.1f", i, A[i] );
    return 0;
}
