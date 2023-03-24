#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main( ) {
    int N ,M;
    cin >> N >> M;
    unordered_map<int, unordered_set<int>> dangerousGoods;
    for( int i = 0, a = 0, b = 0; i < N; i++ ) {
        scanf( "%d %d", &a, &b ) ;
        dangerousGoods[a].insert( b ), dangerousGoods[b].insert( a );
    }
    for( int i = 0, K = 0; i < M; i++ ) {
        cin >> K;
        bool flag = true;
        unordered_map<int, bool> occurance; // 标记本轮出现的货物
        for( int j = 0, number = 0; j < K; j++ ) {
            scanf( "%d", &number );
            occurance[number] = true;
            if( flag == true && dangerousGoods.find( number ) != dangerousGoods.end( ) ) { // 仍在安全状态下且当前number属于危险品
                for( const auto &k : dangerousGoods[number] ) { // 遍历所有不能与number共存的所有危险品
                    if( occurance[k] == true ) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        printf( "%s\n", ( flag == true ? "Yes" : "No" ) );
    }
    return 0;
}