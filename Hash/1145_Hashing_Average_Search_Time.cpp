#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool IsPrime(const int &MSize) {
    for (int i = 2; i * i <= MSize; i++) {
        if (MSize % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int MSize, N, M, cnt = 0;
    cin >> MSize >> N >> M;
    while (!IsPrime(MSize)) {
        MSize++;
    }
    vector<int> hashTable(MSize, 0);
    unordered_map<int, int> insert_cnt; // 记录寻找插入键值位置时尝试的次数
    for (int i = 0, j = 0, key = 0, value = 0; i < N; i++) {
        scanf("%d", &value);
        for (j = 0; j < MSize; j++) {
            key = (value + j * j) % MSize; // 正向平方探测法
            if (hashTable[key] == 0) {
                hashTable[key] = value;
                break;
            }
        }
        insert_cnt[value] = j + 1;
        if (j == MSize) { // 尝试了最大次数也找不到合适位置插入
            printf("%d cannot be inserted.\n", value);
        }
    }
    for (int i = 0, value = 0; i < M; i++) {
        scanf("%d", &value);
        if (insert_cnt.find(value) != insert_cnt.end()) { // 之前插过这个值
            cnt += insert_cnt[value];
        } else { // 没插过
            int j = 0, key;
            do {
                key = (value + j * j) % MSize;
                cnt++, j++;
            } while (j <= MSize && hashTable[key] != 0);
        }
    }
    printf("%.1lf", cnt * 1.0 / M);
    return 0;
}