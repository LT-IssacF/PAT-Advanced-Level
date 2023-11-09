#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    double arr[3], ans = 1;
    int tag[3];
    for (int i = 0; i < 3; i++) {
        double MAX = -1, temp;
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &temp);
            if (temp > MAX) {
                arr[i] = MAX = temp;
                tag[i] = j;
            }
        }
    }
    for (int i = 0; i < 3; i++)
        cout << (tag[i] == 0 ? "W " : (tag[i] == 1 ? "T " : "L "));
    for (const auto &c : arr)
        ans *= c;
    printf("%.2lf", (ans * 0.65 - 1) * 2);
    return 0;
}