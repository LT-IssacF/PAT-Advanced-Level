#include <iostream>
#include <cstdio>
#include <stack>
#include <unordered_map>
using namespace std;
unordered_map<string, int> command{ { "Push", 0 }, { "Pop", 1 }, { "PeekMedian", 2 } };
stack<int> s;
int block[316] = { 0 }, table[100020] = { 0 }; // 把100000个数分成316块
// block是每块内元素的个数，table是每个元素的个数
void Push( const int &key ) {
    block[key / 316]++, table[key]++;
    s.push( key );
}

int Pop( ) {
    int key = s.top( );
    block[key / 316]--, table[key]--;
    s.pop( );
    return key;
}
// median是第median小的数
int PeekMedian( const int &median ) {
    int i = 0, pos = 0, num = 0;
    while( pos + block[i] < median ) // 把第median小的数所在块的前面的块内的所有数的个数都加起来
        pos += block[i++];
    num = i * 316; // 到了第median小的数所在块，num是这个块的第一个数
    while( pos + table[num] < median ) // 把这个块内所有比第median小的数小的数的个数加起来
        pos += table[num++];
    return num;
}

int main( ) {
    int N;
    cin >> N;
    string order;
    for( int i = 0; i < N; i++ ) {
        cin >> order;
        switch( command[order] ) {
            case 0:
                int key;
                scanf( "%d", &key );
                Push( key );
                break;
            case 1:
                if( s.empty( ) ) {
                    printf( "Invalid\n" );
                } else {
                    printf( "%d\n", Pop( ) );
                }
                break;
            case 2:
                if( s.empty( ) ) {
                    printf( "Invalid\n" );
                } else {
                    int median = s.size( );
                    if( median % 2 == 0 ) {
                        median /= 2;
                    } else {
                        median = ( median + 1 ) / 2;
                    }
                    printf( "%d\n", PeekMedian( median ) );
                }
        }
    }
    return 0;
}