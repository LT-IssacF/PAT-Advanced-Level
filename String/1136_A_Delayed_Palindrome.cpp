#include <iostream>
#include <string>
using namespace std;
struct bign {
    int len = 0, d[0x3ff] = {0};
};
bign Convert(const string &s) {
    bign ans;
    for (int i = s.length() - 1; i >= 0; i--)
        ans.d[ans.len++] = s[i] - '0';
    return ans;
}

bign Add(const bign &a) {
    bign ans;
    int carry = 0;
    for (int i = 0, j = a.len - 1; i < a.len; i++, j--) {
        carry += a.d[i] + a.d[j];
        ans.d[ans.len++] = carry % 10;
        carry /= 10;
    }
    if (carry > 0)
        ans.d[ans.len++] = carry;
    return ans;
}

bool Check(const bign &a) {
    for (int i = 0, j = a.len - 1; i < j; i++, j--)
        if (a.d[i] != a.d[j])
            return false;
    return true;
}

void Print(bign &a) {
    for (int i = a.len - 1; i >= 0; i--)
        printf("%d", a.d[i]);
    printf(" + ");
    for (int i = 0; i < a.len; i++)
        printf("%d", a.d[i]);
    printf(" = ");
    a = Add(a);
    for (int i = a.len - 1; i >= 0; i--)
        printf("%d", a.d[i]);
    printf("\n");
}

int main() {
    string s;
    cin >> s;
    bign a = Convert(s);
    int i;
    for (i = 0; i < 10; i++) {
        if (Check(a) == true) {
            for (int i = a.len - 1; i >= 0; i--)
                printf("%d", a.d[i]);
            printf(" is a palindromic number.");
            break;
        } else {
            Print(a);
        }
    }
    if (i == 10)
        printf("Not found in 10 iterations.");
    return 0;
}