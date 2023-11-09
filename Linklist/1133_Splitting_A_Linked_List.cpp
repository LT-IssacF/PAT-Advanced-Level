#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int address, data, next;
    // bool operator < ( const node &a ) const {
    //     return this->data < a.data;
    // }
} tmp[100020];

int main() {
    int start, N, K;
    cin >> start >> N >> K;
    for (int i = 0, address = 0, data = 0, next = 0, tag = 0; i < N; i++) {
        scanf("%d %d %d", &address, &data, &next);
        tmp[address].address = address, tmp[address].data = data, tmp[address].next = next;
    }
    vector<vector<node>> list(3, vector<node>()); // 分别保存3部分
    for (int p = start, tag = 0; p >= 0; p = tmp[p].next) {
        tag = (tmp[p].data < 0 ? 0 : (tmp[p].data <= K ? 1 : 2));
        list[tag].emplace_back(tmp[p]);
    }
    bool isHead = true;
    for (int i = 0; i < 3; i++) {
        for (const node &a : list[i]) {
            if (isHead == false) {
                printf(" %05d\n%05d %d", a.address, a.address, a.data);
            } else {
                printf("%05d %d", a.address, a.data);
                isHead = false;
            }
        }
    }
    cout << " " << -1;
    return 0;
}