#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
struct Record {
    int id, year;
    string title, author, publisher;
    vector<string> key;
    unordered_set<string> s;
};

int main( ) {
    int N, M;
    cin >> N;
    vector<Record> books( N );
    string words;
    for( int i = 0; i < N; i++ ) {
        scanf( "%d\n", &books[i].id );
        getline( cin, books[i].title );
        getline( cin, books[i].author );
        getline( cin, words );
        int j = 0, k = 1;
        while( j < words.length( ) ) {
            k = j + 1;
            while( k < words.length( ) && words[k] != ' ' ) {
                k++;
            }
            books[i].key.emplace_back( words.substr( j, k - j ) );
            books[i].s.insert( words.substr( j, k - j ) );
            j = k + 1;
        }
        getline( cin, books[i].publisher );
        scanf( "%d", &books[i].year );
    }
    cin >> M;
    vector<int> ans;
    for( int i = 0, a = 0; i < M; i++ ) {
        ans.clear( );
        scanf( "%d: ", &a );
        getline( cin, words );
        switch( a ) {
        case 1:
            for( int j = 0; j < N; j++ )
                if( words == books[j].title )
                    ans.emplace_back( books[j].id );
            break;
        case 2:
            for( int j = 0; j < N; j++ )
                if( words == books[j].author )
                    ans.emplace_back( books[j].id );
            break;
        case 3:
            for( int j = 0; j < N; j++ )
                if( books[j].s.find( words ) != books[j].s.end( ) )
                    ans.emplace_back( books[j].id );
            break;
        case 4:
            for( int j = 0; j < N; j++ )
                if( words == books[j].publisher )
                    ans.emplace_back( books[j].id );
            break;
        case 5:
            int temp = stoi( words );
            for( int j = 0; j < N; j++ )
                if( temp == books[j].year )
                    ans.emplace_back( books[j].id );
        }
        printf( "%d: ", a );
        cout << words << endl;
        if( ans.size( ) > 0 ) {
            sort( ans.begin( ), ans.end( ) );
            for( int j = 0; j < ans.size( ); j++ )
                printf( "%07d\n", ans[j] );
        } else {
            printf( "Not Found\n" );
        }
    }
    return 0;
}
