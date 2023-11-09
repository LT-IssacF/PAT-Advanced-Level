#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> code(4);
    int day = 0, hour, minute;
    for (int i = 0; i < 4; i++)
        cin >> code[i];
    for (int i = 0; i < code[0].length() && i < code[1].length(); i++) {
        if (code[0][i] == code[1][i]) {
            if ((code[0][i] >= 'A' && code[0][i] <= 'G') && day == 0) {
                day = code[0][i] - 'A' + 1;
            } else if ((code[0][i] >= '0' && code[0][i] <= '9') && day != 0) {
                hour = code[0][i] - '0';
                break;
            } else if ((code[0][i] >= 'A' && code[0][i] <= 'N') && day != 0) {
                hour = code[0][i] - 'A' + 10;
                break;
            }
        }
    }
    for (int i = 0; i < code[2].length() && i < code[3].length(); i++) {
        if (code[2][i] == code[3][i] && ((code[2][i] >= 'A' && code[2][i] <= 'Z') || (code[2][i] >= 'a' && code[2][i] <= 'z'))) {
            minute = i;
            break;
        }
    }
    switch (day) {
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;
    case 5:
        cout << "FRI";
        break;
    case 6:
        cout << "SAT";
        break;
    case 7:
        cout << "SUN";
    }
    printf(" %02d:%02d", hour, minute);
    return 0;
}