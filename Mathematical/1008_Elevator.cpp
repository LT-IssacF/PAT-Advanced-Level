#include <cstdio>
#include <iostream>
using namespace std;
// 签到题
int main() {
    int N, now_floor, pre_floor = 0, ascend = 6, descend = 4, stay = 5;
    cin >> N >> now_floor;
    int ans = (now_floor - pre_floor) * ascend + stay;
    for (int i = 1; i < N; i++) {
        pre_floor = now_floor;
        scanf("%d", &now_floor);
        ans += (now_floor > pre_floor ? (now_floor - pre_floor) * ascend : (pre_floor - now_floor) * descend) + stay;
    }
    cout << ans;
}