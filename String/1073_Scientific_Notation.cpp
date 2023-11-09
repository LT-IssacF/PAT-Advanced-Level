#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int e_pos = s.find('E'); // E的位置
    int exponent = stoi(s.substr(e_pos + 2)); // 指数绝对值大小
    string number = s.substr(1, e_pos - 1); // 原数
    if (s[0] == '-')
        cout << s[0];
    if (s[e_pos + 1] == '-') { // 指数为负
        number.erase(number.find(1, 1));
        cout << "0.";
        while (exponent > 1) { // 补0
            cout << 0;
            exponent--;
        }
        cout << number;
    } else { // 指数大于等于0
        cout << number[0]; // 先把小数点前面的数输了
        int i = 2;
        while (i < number.length() && exponent > 0) { // 在指数和原数长度范围里输出
            cout << number[i++];
            exponent--;
        }
        if (i == number.length()) { // 原数不够了
            while (exponent > 0) { // 补0
                cout << 0;
                exponent--;
            }
        } else { // 原数多了或是指数不够了
            cout << ".";
            while (i < number.length())
                cout << number[i++];
        }
    }
    return 0;
}