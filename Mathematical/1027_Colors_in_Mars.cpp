#include <iostream>
#include <cstdio>
using namespace std;

int main( ) {
    int red, green, blue;
    cin >> red >> green >> blue;
    char arr[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
                     '9', 'A', 'B', 'C' };
    cout << "#";
    printf( "%c%c", arr[red / 13], arr[red % 13] );
    printf( "%c%c", arr[green / 13], arr[green % 13] );
    printf( "%c%c", arr[blue / 13], arr[blue % 13] );
    return 0;
}
