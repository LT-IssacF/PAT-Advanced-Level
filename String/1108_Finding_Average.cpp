#include <iostream>
#include <string>
using namespace std;
bool Check(const string &s) {
    for (int i = 0, pointCnt = 0, pointPos = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            pointCnt++;
            pointPos = i;
            if (pointCnt > 1)
                return false;
            if (s.length() - 1 - pointPos > 2)
                return false;
        } else if (s[i] > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    int N, cnt = 0;
    cin >> N;
    double ans = 0;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        bool flag = Check(s);
        double value;
        if (flag)
            value = stod(s);
        if (flag == false || (abs(value) > 1000.0)) {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        } else {
            ans += value;
            cnt++;
        }
    }
    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined");
    } else if (cnt == 1) {
        printf("The average of %d number is %.2lf", cnt, ans);
    } else {
        printf("The average of %d numbers is %.2lf", cnt, ans / cnt);
    }
    return 0;
}