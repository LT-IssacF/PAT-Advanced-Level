#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<int> pre;
map<int, bool> hashTable;
// 建树直接超时
int main( ) {
    int N, M;
    cin >> M >> N;
    pre.resize( N );
    for( int i = 0; i < N; i++ ) {
        scanf( "%d", &pre[i] );
        hashTable[pre[i]] = true; // 标记是否有这个结点
    }
    for( int i = 0, ans = 0, u = 0, v = 0; i < M; i++ ) {
        scanf( "%d %d", &u, &v );
        if( hashTable[u] == false && hashTable[v] == false ) {
            printf( "ERROR: %d and %d are not found.\n", u, v );
        } else if( hashTable[u] == false || hashTable[v] == false ) {
            printf( "ERROR: %d is not found.\n", hashTable[u] == false ? u : v );
        } else {
            for( int j = 0; j < N; j++ ) // 建树也是前序遍历挨个挨个找，那就可以直接用现成的前序序列找
                if( ( pre[j] >= u && pre[j] <= v ) || ( pre[j] <= u && pre[j] >= v ) ) { // pre[j]就是当前访问的结点值
                    ans = pre[j]; // 找到一个u比pre[j]大v比pre[j]小（或相反）的结点
                    break;
                }
            if( ans != u && ans != v ) {
                printf( "LCA of %d and %d is %d.\n", u, v, ans );
            } else {
                printf( "%d is an ancestor of %d.\n", ans, ans != u ? u : v );
            }
        }
    }
}
