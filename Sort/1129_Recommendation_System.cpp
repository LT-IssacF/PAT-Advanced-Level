#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
struct node {
    int item, cnt;
    bool operator < ( const node &a ) const { // 因为原set里是升序排的，所以得重载<
        if( a.cnt != this->cnt ) { // 浏览次数不同就降序排
            return a.cnt < this->cnt;
        } else { // 浏览次数相同就按序号值升序排
            return this->item < a.item;
        }
    }
};

int main( ) {
    int N, K, item;
    cin >> N >> K >> item;
    vector<int> frequency( N + 1, 0 );
    frequency[item] = 1;
    set<node> ans;
    ans.insert( node{ item, frequency[item] } );
    for( int i = 1; i < N; i++ ) {
        scanf( "%d", &item );
        printf( "%d:", item );
        auto it = ans.begin( );
        for( int j = 0; j < K && it != ans.end( ); j++, it++ )
            printf( " %d", it->item );
        printf( "\n" );
        it = ans.find( node{ item, frequency[item] } );
        if( it != ans.end( ) ) // 当前商品之前浏览过就重置浏览次数
            ans.erase( it );
        frequency[item]++;
        ans.insert( node{ item, frequency[item] } );
    }
    return 0;
}
