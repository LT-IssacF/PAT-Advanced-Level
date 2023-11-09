#include <cstdio>
#include <cstring>

int main() {
    char str[81] = {'\0'};
    scanf("%s", str);
    int len = strlen(str), n1 = (len + 2) / 3, n2 = (len + 2) - n1 * 2, p = 0;
    for (int i = 1; i < n1; i++, p++) {
        printf("%c", str[p]);
        for (int j = 2; j < n2; j++)
            printf(" ");
        printf("%c\n", str[len - 1 - p]);
    }
    while (p <= (len - n1))
        printf("%c", str[p++]);
    return 0;
}