#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;
int father[100001];
unordered_set<int> birds; // 记下出现过的鸟
int FindFather( int key ) {
    int x = key;
    while( key != father[key] )
        key = father[key];
    while( x != father[x] ) {
        int a = x;
        x = father[x];
        father[a] = key;
    }
    return key;
}

void Union( const int &a, const int &b ) {
    int faA = FindFather( a ), faB = FindFather( b );
    if( faA != faB )
        father[faB] = faA;
}

int main( ) {
    int N, Q;
    cin >> N;
    for( int i = 0; i <= 10000; i++ ) // 初始化并查集
        father[i] = i;
    for( int i = 0, K = 0, root = 0; i < N; i++ ) {
        scanf( "%d %d", &K, &root ); // 取第一只鸟作为根
        birds.insert( root );
        for( int j = 1, bird = 0; j < K; j++ ) {
            scanf( "%d", &bird );
            birds.insert( bird );
            Union( root, bird );
        }
    }
    unordered_set<int> trees;
    for( const int &bird : birds )
        trees.insert( FindFather( bird ) );
    cout << trees.size( ) << " " << birds.size( ) << endl;
    cin >> Q;
    for( int i = 0, a = 0, b = 0; i < Q; i++ ) {
        scanf( "%d %d", &a, &b );
        printf( "%s\n", ( FindFather( a ) == FindFather( b ) ? "Yes" : "No" ) );
    }
    return 0;
}