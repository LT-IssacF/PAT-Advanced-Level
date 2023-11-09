#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N, b, A[52], B[52], a_len = 0;
    cin >> N >> b;
    do {
        A[a_len++] = N % b;
        N /= b;
    } while (N > 0);
    for (int i = 0, j = a_len - 1; i < a_len; i++, j--)
        B[i] = A[j];
    bool ans = true;
    for (int i = 0; i < a_len; i++)
        if (B[i] != A[i]) {
            ans = false;
            break;
        }
    cout << (ans ? "Yes" : "No") << endl;
    for (int i = 0; i < a_len; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", B[i]);
    }
    return 0;
}