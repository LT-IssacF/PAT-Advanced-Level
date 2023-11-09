#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int address, data, next;
} list[100020];

int main() {
    int start, start2, N, p, q;
    cin >> start >> start2 >> N;
    for (int i = 0, add = 0, data = 0, next = 0; i < N; i++) {
        scanf("%d %d %d", &add, &data, &next);
        list[add].address = add, list[add].data = data, list[add].next = next;
    }
    vector<node> ans, ans2;
    for (int p = start; p != -1; p = list[p].next)
        ans.emplace_back(list[p]);
    for (int p = start2; p != -1; p = list[p].next)
        ans2.emplace_back(list[p]);
    if (ans.size() < ans2.size()) // 前者固定为长链表，后者为短链表
        swap(ans, ans2);
    for (p = 0, q = ans2.size() - 1; q >= 0; q--) { // 短链表固定至少比长链表少2倍
        printf("%05d %d %05d\n", ans[p].address, ans[p].data,
               ans[p + 1].address); // 长链表每块前一个结点，next是长链表后一个结点
        printf("%05d %d %05d\n", ans[p + 1].address, ans[p + 1].data,
               ans2[q].address); // 长链表每块后一个结点，next是短链表的结点
        p += 2;
        if (p == ans.size()) { // 如果长链表结束了，即没有多余的结点，那么next就为-1
            printf("%05d %d -1", ans2[q].address, ans2[q].data);
        } else { // 有多余的
            printf("%05d %d %05d\n", ans2[q].address, ans2[q].data, ans[p].address);
        }
    }
    if (p < ans.size()) { // 处理多余的
        while (p < ans.size() - 1) {
            printf("%05d %d %05d\n", ans[p].address, ans[p].data, ans[p + 1].address);
            p++;
        }
        printf("%05d %d -1", ans[p].address, ans[p].data);
    }
    return 0;
}