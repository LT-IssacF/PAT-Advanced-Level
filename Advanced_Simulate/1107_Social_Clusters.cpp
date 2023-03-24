// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;
// unordered_map<int, int> hobbies;
// vector<int> father, roots;
// int FindFather( int key ) {
//     int x = key; // 保存变量key
//     while( key != father[key] )
//         key = father[key];
//     while( x != father[x] ) { // 此时key为集合的根结点
//         int a = x; // 保存变量x
//         x = father[x]; // x回溯到x的父结点
//         father[a] = key; // 路径压缩
//     }
//     return x;
// }

// void Union( const int &a, const int &b ) {
//     int faA = FindFather( a ), faB = FindFather( b );
//     if( faA != faB )
//         father[faB] = faA;
// }

// int main( ) {
//     int N, ans = 0;
//     cin >> N;
//     father.resize( N + 1 ), roots.resize( N + 1 );
//     for( int i = 1; i <= N; i++ )
//         father[i] = i;
//     fill( roots.begin( ), roots.end( ), 0 );
//     for( int i = 1, K = 0; i <= N; i++ ) {
//         scanf( "%d: ", &K );
//         for( int j = 0, num = 0; j < K; j++ ) {
//             scanf( "%d", &num );
//             if( hobbies[num] == 0 ) // 第一个爱好num的人是i
//                 hobbies[num] = i;
//             Union( FindFather( hobbies[num] ), i ); // 合并第一个爱好num的人与i
//         }
//     } // 并查集建立完成
//     for( int i = 1; i <= N; i++ ) // 统计每个集合的人数
//         roots[FindFather( i )]++;
//     sort( roots.begin( ) + 1, roots.end( ), [] ( const int &a, const int &b ) { return a > b; } );
//     for( int i = 1; i <= N && roots[i] != 0; i++ )
//         ans++;
//     cout << ans << endl;
//     for( int i = 1; i <= ans; i++ ) {
//         if( i != 1 )
//             printf( " " );
//         printf( "%d", roots[i] );
//     }
//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father;
int hashTable[0x3ff] = { 0 };
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
    int N, ans = 0;
    cin >> N;
    father.resize( N + 1 );
    for( int i = 1; i <= N; i++ ) // 并查集初始化
        father[i] = i;
    for( int i = 1, K = 0; i <= N; i++ ) {
        scanf("%d:", &K );
        for( int j = 0, hobby = 0; j < K; j++ ) {
            scanf( "%d", &hobby );
            if( hashTable[hobby] == 0 ) // 第一个喜欢hobby的人作为这个集合的father
                hashTable[hobby] = i;
            Union( hashTable[hobby], i ); // 合并第一个喜欢hobby的人和当前i
        }
    }
    vector<int> roots( N + 1 );
    for( int i = 1; i <= N; i++ ) // 遍历所有人，统计集合数
        roots[FindFather( i )]++;
    sort( roots.begin( ), roots.end( ), [] ( const int &a, const int &b ) {
        return a > b;
    } );
    for( int i = 0; i < N && roots[i] > 0; i++ )
        ans++;
    cout << ans << endl;
    printf( "%d", roots[0] );
    for( int i = 1; i < ans; i++ )
        printf( " %d", roots[i] );
    return 0;
}