#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    double amount, value, price;
};

int main( ) {
    int N;
    double D, profit = 0;
    cin >> N >> D;
    vector<node> mooncakes( N );
    for( int i = 0; i < N; i++ )
        scanf( "%lf", &mooncakes[i].amount );
    for( int i = 0; i < N; i++ ) {
        scanf( "%lf", &mooncakes[i].value );
        mooncakes[i].price = mooncakes[i].value / mooncakes[i].amount;
    }
    sort( mooncakes.begin( ), mooncakes.end( ), [] ( const node &a, const node &b ) {
        return a.price > b.price;
    } );
    for( int i = 0; i < N && D > 0; i++ )
        if( D >= mooncakes[i].amount ) {
            profit += mooncakes[i].value;
            D -= mooncakes[i].amount;
        } else {
            profit += D * mooncakes[i].price;
            D = 0;
        }
    printf( "%.2lf", profit );
    return 0;
}
