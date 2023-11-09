#include <iostream>
#include <string>
using namespace std;
void Formulate(string &str, int &exponent, const int &N) {
    while (str[0] == '0' && str.length() > 0) // 消除前导0
        str.erase(0, 1);
    if (str.length() > 0) { // 非0常数
        if (str[0] == '.') { // 小于1的数
            str.erase(0, 1); // 去掉小数点
            while (str[0] == '0' && str.length() > 0) {
                str.erase(0, 1);
                exponent--;
            } // 消除前面的0，同时指数减少
            if (str.length() == 0) // 0.000
                exponent = 0;
        } else { // 大于等于1的数
            int point = 0; // 保存小数点的位置
            while (point < str.length() && str[point] != '.') {
                point++;
                exponent++;
            } // 寻找小数点，同时指数增加
            if (point != str.length()) // 如果有小数点就去掉
                str.erase(point, 1);
        }
    } else { // 真0
        exponent = 0;
    }
    if (str.length() > N) { // 去掉多余的数位
        str.erase(N, str.length() - N);
    } else { // 数位少了后面补0
        while (str.length() < N)
            str += '0';
    }
}

int main() {
    int N, exponentA = 0, exponentB = 0;
    string A, B;
    cin >> N >> A >> B;
    Formulate(A, exponentA, N), Formulate(B, exponentB, N);
    if (A == B && exponentA == exponentB) {
        cout << "YES 0." << A << "*10^" << exponentA;
    } else {
        cout << "NO 0." << A << "*10^" << exponentA << " 0." << B << "*10^" << exponentB;
    }
    return 0;
}