#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 越长的绳子对折次数越少
int main( ) {
    int N;
    cin >> N;
    vector<int> ropes( N );
    for( int i = 0; i < N; i++ )
        cin >> ropes[i];
    sort( ropes.begin( ), ropes.end( ) );
    int ans = ropes[0];
    for( int i = 1; i < N; i++ )
        ans = ( ropes[i] + ans ) / 2;
    cout << ans;
    return 0;
}
