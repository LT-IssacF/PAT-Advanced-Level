#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int address, data, next;
    bool flag = false; // 标记结点是否在链上
} list[100020];

int main() {
    int N, start, cnt = 0;
    cin >> N >> start;
    for (int i = 0, address = 0; i < N; i++) {
        scanf("%d", &address);
        scanf("%d %d", &list[address].data, &list[address].next);
        list[address].address = address;
    }
    for (int p = start; p != -1; p = list[p].next, cnt++) // 遍历链表，标记哪些结点在链上
        list[p].flag = true;
    if (cnt == 0) {
        printf("0 -1");
    } else {
        sort(list, list + 100020, [](const node &a, const node &b) {
            if (a.flag != b.flag) {
                return a.flag > b.flag; // 不在链上的往后排
            } else {
                return a.data < b.data;
            }
        });
        printf("%d %05d\n", cnt, list[0].address);
        for (int i = 0; i < cnt - 1; i++) // 本结点的next就是下一个结点的address
            printf("%05d %d %05d\n", list[i].address, list[i].data, list[i + 1].address);
        printf("%05d %d -1", list[cnt - 1].address, list[cnt - 1].data);
    }
    return 0;
}