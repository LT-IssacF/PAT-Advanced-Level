#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 0x1f
using namespace std;
struct bign {
    int d[MAX] = {0}, len = 0;
};
bign Change(const char *str) {
    bign a;
    for (int i = strlen(str) - 1; i >= 0; i--)
        a.d[a.len++] = str[i] - '0';
    return a;
}

bign Add(const bign &a, const bign &b) {
    bign c;
    int carry = 0;
    for (int i = 0, temp = 0; i < a.len || i < b.len; i++) {
        temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry > 0)
        c.d[c.len++] = carry;
    return c;
}

bign Minus(bign a, const bign &b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++) {
        if (a.d[i] < b.d[i]) {
            a.d[i] += 10;
            a.d[i + 1]--;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.d[c.len - 1] == 0 && c.len > 1)
        c.len--;
    return c;
}

bign Multi(const bign &a, const int &d) {
    bign b;
    int carry = 0;
    for (int i = 0, temp = 0; i < a.len; i++) {
        temp = a.d[i] * d + carry;
        b.d[b.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry > 0) {
        b.d[b.len++] = carry % 10;
        carry /= 10;
    }
    return b;
}

bign Divide(const bign &a, const int &b, int &remnant) {
    bign c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--) {
        remnant = remnant * 10 + a.d[i];
        c.d[i] = remnant / b;
        remnant %= b;
    }
    while (c.d[c.len - 1] == 0 && c.len > 1)
        c.len--;
    return c;
}

bool Judge(const bign &a, const bign &b) {
    if (a.len != b.len)
        return false;
    int temp[10] = {0};
    for (int i = 0; i < a.len; i++) {
        temp[a.d[i]]++;
        temp[b.d[i]]--;
    }
    for (int i = 0; i < 10; i++)
        if (temp[i] != 0)
            return false;
    return true;
}

int main() {
    char str[21];
    scanf("%s", str);
    bign a = Change(str);
    bign b = Multi(a, 2);
    cout << (Judge(a, b) ? "Yes" : "No") << endl;
    for (int i = b.len - 1; i >= 0; i--)
        printf("%d", b.d[i]);
    return 0;
}