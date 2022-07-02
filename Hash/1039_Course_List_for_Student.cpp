#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main( ) {
    int N, K;
    cin >> N >> K;
    map<string, set<int>> stu;
    string name;
    for( int i = 0, course = 0, cnt = 0; i < K; i++ ) {
        scanf( "%d %d", &course, &cnt );
        for( int j = 0; j < cnt; j++ ) {
            cin >> name;
            stu[name].insert( course );
        }
    }
    for( int i = 0; i < N; i++ ) {
        cin >> name;
        cout << name << " " << stu[name].size( );
        for( const auto &i : stu[name] )
            printf( " %d", i );
        printf( "\n" );
    }
    return 0;
}
