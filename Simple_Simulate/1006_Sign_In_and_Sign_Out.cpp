#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int N, earliest = 24 * 3600, latest = 0;
    cin >> N;
    char unlocked_id[16] = {'\0'}, locked_id[16] = {'\0'}, temp_id[16] = {'\0'};
    for (int i = 0, hour = 0, minute = 0, second = 0, time = 0; i < N; i++) {
        scanf("%s %d:%d:%d", &temp_id, &hour, &minute, &second);
        time = hour * 3600 + minute * 60 + second;
        if (time < earliest) {
            memcpy(unlocked_id, temp_id, strlen(temp_id));
            earliest = time;
        }
        scanf("%d:%d:%d", &hour, &minute, &second);
        time = hour * 3600 + minute * 60 + second;
        if (time > latest) {
            memcpy(locked_id, temp_id, strlen(temp_id));
            latest = time;
        }
    }
    printf("%s %s", unlocked_id, locked_id);
    return 0;
}