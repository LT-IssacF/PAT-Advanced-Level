#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
bool Judge( const vector<int> &sequence, const int &N, const int &M ) {
    stack<int> s;
    for( int i = 1, j = 0; i <= N; i++ ) {
        s.push( i ); // 按1，2，…，N的顺序每轮进一次栈
        if( s.size( ) > M ) // 栈溢出
            return false;
        while( !s.empty( ) && s.top( ) == sequence[j] ) { // 栈顶元素与出栈序列的当前元素相同
            s.pop( ); // 出栈
            j++; // 下一个元素
        }
    }
    return s.empty( ); // 正确的序列能够出完
}

int main( ) {
    int M, N, K;
    cin >> M >> N >> K;
    vector<int> sequence( N );
    for( int i = 0; i < K; i++ ) {
        for( int j = 0; j < N; j++ )
            scanf( "%d", &sequence[j] );
        printf( "%s\n", ( Judge( sequence, N, M ) ? "YES" : "NO" ) );
    }
    return 0;
}
