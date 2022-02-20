#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Record {
    char name[9] = { '\0' };
    int age, worth;
};

int main( ) {
    int N, K;
    cin >> N >> K;
    vector<Record> people( N );
    for( int i = 0; i < N; i++ )
        scanf( "%s %d %d", &people[i].name, &people[i].age, &people[i].worth );
    sort( people.begin( ), people.end( ), [] ( const Record &a, const Record &b ) {
        if( a.worth != b.worth ) {
            return a.worth > b.worth;
        } else if( a.age != b.age ) {
            return a.age < b.age;
        } else {
            return strcmp( a.name, b.name ) < 0;
        }
    } );
    for( int i = 1, M = 0, aMin = 0, aMax = 0; i <= K; i++ ) {
        scanf( "%d %d %d", &M, &aMin, &aMax );
        printf( "Case #%d:\n", i );
        vector<Record>::iterator it = people.begin( );
        while( it != people.end( ) && ( it->age < aMin || it->age > aMax ) ) it++;
        if( it == people.end( ) ) {
            printf( "None\n" );
        } else {
            for( int i = 0; it != people.end( ) && i < M; it++ )
                if( it->age >= aMin && it->age <= aMax ) {
                    printf( "%s %d %d\n", it->name, it->age, it->worth );
                    i++;
                }
        }
    }
    return 0;
}
