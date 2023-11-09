#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    for (int i = 0, len = 0; i < N; i++) {
        string s;
        cin >> s;
        len = s.length();
        ll a = stoll(s.substr(0, len / 2)), b = stoll(s.substr(len / 2, len / 2));
        ll c = a * b;
        if (c == 0) {
            printf("No\n");
        } else {
            printf("%s\n", stoll(s) % c == 0 ? "Yes" : "No");
        }
    }
    return 0;
}