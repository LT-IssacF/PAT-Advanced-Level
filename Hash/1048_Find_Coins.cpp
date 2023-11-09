#include <cstdio>

int main() {
    int N, M, coins[1120] = {0}; // M - i可能会大于500
    scanf("%d %d", &N, &M);
    for (int i = 0, value = 0; i < N; i++) {
        scanf("%d", &value);
        coins[value]++;
    }
    for (int i = 1; i <= M; i++)
        if (coins[i] > 0 && coins[M - i] > 0) {
            if (i == M - i && coins[i] < 2)
                continue;
            printf("%d %d", i, M - i);
            return 0;
        }
    printf("No Solution");
    return 0;
}