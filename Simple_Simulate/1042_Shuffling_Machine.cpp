#include <cstdio>
#include <iostream>
#define MAX 54
using namespace std;

int main() {
    int K;
    cin >> K;
    char card[5] = {'S', 'H', 'C', 'D', 'J'};
    int start[MAX + 1], end[MAX + 1], next[MAX + 1];
    for (int i = 1; i <= MAX; i++)
        start[i] = i;
    for (int i = 1, temp = 0; i <= MAX; i++)
        scanf("%d", &next[i]);
    for (int step = 0; step < K; step++) {
        for (int i = 1; i <= MAX; i++) // 举个栗子，next[0…4] = { 4，2，5，3，1 }
            end[next[i]] = start[i]; // 那么，end[0…4] = { 5，2，4，1，3 }
        for (int i = 1; i <= MAX; i++) // start保存本轮结果并用来进行下一步
            start[i] = end[i];
    }
    cout << card[start[1] / 13] << start[1] % 13;
    for (int i = 2; i <= MAX; i++) {
        start[i]--;
        cout << " " << card[start[i] / 13] << start[i] % 13 + 1;
    }
    return 0;
}