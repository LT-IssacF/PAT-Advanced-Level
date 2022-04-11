#include <iostream>
#include <cstdio>
using namespace std;

int main( ) {
    int a, b, ans;
    cin >> a >> b;
    ans = a + b;
    bool positive = ans >= 0;
    if( !positive ) {
        ans *= -1;
        cout << "-";
    }
    int millons = ans / ( int ) 1e6, thousands = ans / 1000 % 1000, numbers = ans % 1000;
    if( millons > 0 ) {
        printf( "%d,%03d,%03d", millons, thousands, numbers );
    } else if( thousands > 0 ) {
        printf( "%d,%03d", thousands, numbers );
    } else {
        cout << numbers;
    }
    return 0;
}
