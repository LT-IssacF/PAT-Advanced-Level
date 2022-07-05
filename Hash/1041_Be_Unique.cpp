#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 10020
using namespace std;

int main( ) {
    int N;
    cin >> N;
    vector<int> arr;
    int hash[MAX] = { 0 };
    for( int i = 0, temp = 0; i < N; i++ ) {
        scanf( "%d", &temp );
        hash[temp]++;
        arr.push_back( temp );
    }
    bool flag = false;
    for( int i = 0; i < N; i++ )
        if( hash[arr[i]] == 1 ) {
            flag = true;
            cout << arr[i];
            break;
        }
    if( !flag )
        cout << "None";
    return 0;
}
