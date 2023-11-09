#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#define INF 0x3fffffff
using namespace std;
struct node {
    int address, data, next, order = INF * 2; // 初始顺序为INF * 2
} list[100020];
bool hashTable[100020] = {false};

int main() {
    int start, N, validCnt = 0, total = 0;
    cin >> start >> N;
    for (int i = 0, address = 0; i < N; i++) {
        scanf("%d", &address);
        scanf("%d %d", &list[address].data, &list[address].next);
        list[address].address = address;
    }
    for (int p = start, delCnt = 0; p != -1; p = list[p].next, total++) // 遍历单链表
        if (hashTable[abs(list[p].data)] == false) { // data第一次出现
            list[p].order = validCnt++;
            hashTable[abs(list[p].data)] = true;
        } else { // 重复的
            list[p].order = INF + delCnt; // 要删除的多余重复结点的顺序从INF开始重新编号
            delCnt++;
        }
    sort(list, list + 100020, [](const node &a, const node &b) { return a.order < b.order; }); // 在链上的结点从0开始排，重复的从INF开始排，不在链上的排在最后
    for (int i = 0; i < total; i++)
        if (i == validCnt - 1 || i == total - 1) {
            printf("%05d %d -1\n", list[i].address, list[i].data);
        } else {
            printf("%05d %d %05d\n", list[i].address, list[i].data, list[i + 1].address);
        }
    return 0;
}