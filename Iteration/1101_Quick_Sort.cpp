#include <iostream>
#include <cstdio>
#include <vector>
#define INF 0x3fffffff
using namespace std;
vector<int> arr, leftMax, rightMin, ans;
// leftMax[i]为i左边最大的元素，rightMin[i]为i右边最小的元素
int main( ) {
    int N;
    cin >> N;
    arr.resize( N ), leftMax.resize( N ), rightMin.resize( N );
    fill( rightMin.begin( ), rightMin.end( ), INF );
    for( int i = 0; i < N; i++ )
        scanf( "%d", &arr[i] );
    for( int i = 1; i < N; i++ ) // leftMax[i]等于leftMax[i - 1]和arr[i - 1]中较大的那个
        leftMax[i] = max( leftMax[i - 1], arr[i - 1] );
    for( int i = N - 2; i >= 0; i-- ) // rightMin[i]等于rightMin[i + 1]和arr[i + 1]中较小的那个
        rightMin[i] = min( rightMin[i + 1], arr[i + 1] );
    for( int i = 0; i < N; i++ ) {
        if( leftMax[i] <= arr[i] && arr[i] <= rightMin[i] )
            ans.push_back( arr[i] );
    }
    int size = ans.size( );
    cout << size << endl;
    if( size > 0 )
        cout << ans[0];
    else // 还要再输出一个换行，吐了
        cout << endl;
    for( int i = 1; i < size; i++ )
        printf( " %d", ans[i] );
    return 0;
}
