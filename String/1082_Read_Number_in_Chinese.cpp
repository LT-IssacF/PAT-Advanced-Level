#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
char num[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char digit[5][6] = {" Shi", " Bai", " Qian", " Wan", " Yi"};

int main() {
    string s;
    cin >> s;
    int left = 0, right = s.length() - 1;
    if (s[0] == '-') {
        printf("Fu");
        left++;
    }
    while (right - 4 >= left) // 将left和right放在同一节内
        right -= 4;
    while (left < s.length()) {
        bool zeroFlag = false, printFlag = false;
        while (left <= right) {
            if (s[left] == '0' && left > 0) { // 本位为0
                zeroFlag = true;
            } else { // 本位不是0
                if (zeroFlag == true) { // 之前有积攒的0位就把0先输出了再说
                    printf(" %s", num[0]);
                    zeroFlag = false; // 重置0标记
                }
                if (left > 0) // 正数最高位不能输出空格
                    printf(" ");
                printf("%s", num[s[left] - '0']); // 读出当前所指数字
                if (left < right) // left所指非个位，需要输出权位
                    printf("%s", digit[right - left - 1]);
                printFlag = true;
            }
            left++;
        }
        if (right + 4 < s.length() && printFlag) // 当前处理的节处于万或亿且已经输出过有效位
            printf("%s", digit[(s.length() - right) / 4 + 2]);
        right += 4; // 处理下一节
    }
    return 0;
}