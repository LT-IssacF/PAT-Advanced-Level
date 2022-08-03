#include <iostream>
#include <string>
#include <map>
using namespace std;
string digit[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep","oct","nov","dec" },
digit2[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
map<string, int> stringToInt = { { "tret", 0 }, { "jan", 1 }, { "feb", 2 }, { "mar", 3 }, { "apr", 4 }, { "may", 5 }, { "jun", 6 }, { "jly", 7 }, { "aug", 8 }, { "sep", 9 }, { "oct", 10 }, { "nov", 11 }, { "dec", 12 } },
stringToInt2 = { { "tret", 0 }, { "tam", 1 }, { "hel", 2 }, { "maa", 3 }, { "huh", 4 }, { "tou", 5 }, { "kes", 6 }, { "hei", 7 }, { "elo", 8 }, { "syy", 9 }, { "lok", 10 }, { "mer", 11 }, { "jou", 12 } };

int main( ) {
    int N;
    cin >> N;
    getchar( );
    string s, ans;
    for( int i = 0, num; i < N; i++ ) {
        getline( cin, s );
        if( s[0] >= '0' && s[0] <= '9' ) {
            num = stoi( s );
            if( num / 13 > 0 ) {
                if( num % 13 == 0 ) {
                    ans = digit2[num / 13];
                } else {
                    ans = digit2[num / 13] + " " + digit[num % 13];
                }
            } else {
                ans = digit[num];
            }
            cout << ans << endl;
        } else {
            if( s.length( ) > 4 ) {
                num = stringToInt2[s.substr( 0, 3 )] * 13 + stringToInt[s.substr( 4, 3 )] * 1;
            } else {
                if( stringToInt2.find( s ) != stringToInt2.end( ) ) {
                    num = stringToInt2[s] * 13;
                } else {
                    num = stringToInt[s];
                }
            }
            cout << num << endl;
        }
    }
    return 0;
}
