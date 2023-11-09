#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
struct fraction {
    ll numerator, denominator;
};
ll gcd(const ll &a, const ll &b) {
    return b == 0 ? a : gcd(b, a % b);
}

void Reduction(fraction &result) { // 化简
    if (result.denominator < 0) { // 如果分母为负，那么分子分母同时变号
        result.numerator = -result.numerator;
        result.denominator = -result.denominator;
    }
    if (result.numerator == 0) { // 如果分子为0，那么令分母为1
        result.denominator = 1;
    } else { // 进行约分
        ll divisor = gcd(abs(result.numerator), abs(result.denominator));
        result.numerator /= divisor;
        result.denominator /= divisor;
    }
}

fraction Add(const fraction &a, const fraction &b) {
    fraction ans;
    ans.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    ans.denominator = a.denominator * b.denominator;
    Reduction(ans);
    return ans;
}

fraction Minus(const fraction &a, const fraction &b) {
    fraction ans;
    ans.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    ans.denominator = a.denominator * b.denominator;
    Reduction(ans);
    return ans;
}

fraction Multiply(const fraction &a, const fraction &b) {
    fraction ans;
    ans.numerator = a.numerator * b.numerator;
    ans.denominator = a.denominator * b.denominator;
    Reduction(ans);
    return ans;
}

fraction Divide(const fraction &a, const fraction &b) {
    fraction ans;
    ans.numerator = a.numerator * b.denominator;
    ans.denominator = a.denominator * b.numerator;
    Reduction(ans);
    return ans;
}

void Print(const fraction &a) {
    if (a.numerator < 0)
        printf("(");
    if (a.denominator == 1) { // 整数
        printf("%lld", a.numerator);
    } else if (abs(a.numerator) < a.denominator) { // 真分数
        printf("%lld/%lld", a.numerator, a.denominator);
    } else { // 假分数
        printf("%lld %lld/%lld", a.numerator / a.denominator, abs(a.numerator) % a.denominator, a.denominator);
    } // 注意分子要用绝对值，不然会多输负号
    if (a.numerator < 0)
        printf(")");
}

int main() {
    fraction a, b, ans;
    scanf("%lld/%lld %lld/%lld", &a.numerator, &a.denominator, &b.numerator, &b.denominator);
    Reduction(a), Reduction(b); // 先对a，b化简
    for (int i = 0; i < 4; i++) {
        bool INF = false;
        Print(a);
        switch (i) {
        case 0:
            printf(" + ");
            ans = Add(a, b);
            break;
        case 1:
            printf(" - ");
            ans = Minus(a, b);
            break;
        case 2:
            printf(" * ");
            ans = Multiply(a, b);
            break;
        case 3:
            printf(" / ");
            if (b.numerator != 0) { // 除数不为0正常运算
                ans = Divide(a, b);
            } else { // 除数为0特判
                INF = true;
            }
        }
        Print(b);
        printf(" = ");
        if (i < 3) {
            Print(ans);
        } else {
            if (INF == false) {
                Print(ans);
            } else { // 除数为0特判
                printf("Inf");
            }
        }
        printf("\n");
    }
    return 0;
}