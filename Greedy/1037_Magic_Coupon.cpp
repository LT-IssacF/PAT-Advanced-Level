#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main( ) {
    int N, M, ans = 0;
    cin >> N;
    vector<int> coupon( N );
    for( int i = 0; i < N; i++ )
        scanf( "%d", &coupon[i] );
    cin >> M;
    vector<int> product( M );
    for( int i = 0; i < M; i++ )
        scanf( "%d", &product[i] );
    sort( coupon.begin( ), coupon.end( ) );
    sort( product.begin( ), product.end( ) );
    for( int i = 0, j = 0; coupon[i] < 0 && product[j] < 0; i++, j++ )
        ans += coupon[i] * product[j];
    for( int i = N - 1, j = M - 1; coupon[i] > 0 && product[j] > 0; i--, j-- )
        ans += coupon[i] * product[j];
    cout << ans;
    return 0;
}
