#include <cstdio>
#include <iostream>
using namespace std;
bool IsPrime(const int &key) {
    if (key < 2)
        return false;
    for (int i = 2; i * i <= key; i++)
        if (key % i == 0)
            return false;
    return true;
}

int main() {
    int N, D, arr[20], length = 0;
    while (1) {
        scanf("%d", &N);
        if (N < 0)
            break;
        scanf("%d", &D);
        if (!IsPrime(N)) {
            printf("No\n");
        } else {
            while (N > 0) { // 由低位至高位按序存入数组
                arr[length++] = N % D;
                N /= D;
            }
            int reverse = 0, exponent = 1;
            while (length > 0) { // 逆置数字
                reverse += arr[--length] * exponent; // 由高位至低位分别乘上由小到大的权重
                exponent *= D;
            }
            cout << (IsPrime(reverse) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}