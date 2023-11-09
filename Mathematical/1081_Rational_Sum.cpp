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

void Add(fraction &a, const fraction &b) { // result = ( n1 * d2 + n2 * d1 ) / ( d1 * d2 )
    a.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    a.denominator *= b.denominator;
    Reduction(a);
}

int main() {
    int N;
    cin >> N;
    fraction ans;
    for (ll i = 0, numerator = 0, denominator = 0; i < N; i++) {
        scanf("%lld/%lld", &numerator, &denominator);
        Add(ans, fraction{numerator, denominator});
    }
    if (ans.denominator == 1) { // 整数
        printf("%lld", ans.numerator);
    } else if (abs(ans.numerator) < ans.denominator) { // 真分数
        printf("%lld/%lld", ans.numerator, ans.denominator);
    } else { // 假分数
        printf("%lld %lld/%lld", ans.numerator / ans.denominator, ans.numerator % ans.denominator, ans.denominator);
    }
    return 0;
}