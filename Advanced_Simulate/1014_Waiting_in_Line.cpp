#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define open_time 8 * 60
#define close_time 17 * 60
using namespace std;
struct node { // pop_time是窗口空出位子的时间，end_time是窗口的服务结束时间
    int pop_time = open_time, end_time = open_time;
    queue<int> q;
};

int main() {
    int N, M, K, Q, num = 1;
    cin >> N >> M >> K >> Q;
    vector<node> windows(N + 1);
    vector<int> serve_time(K + 1), ans(K + 1);
    for (int i = 1; i <= K; i++)
        scanf("%d", &serve_time[i]);
    while (num <= K && num <= N * M) { // 先把一开始前面N * M个人处理了
        int win_index = (num % N != 0 ? num % N : N); // 获得窗口序号
        windows[win_index].q.push(serve_time[num]);
        if (windows[win_index].end_time < close_time) { // 如果没过关门时间
            windows[win_index].end_time += serve_time[num]; // 服务结束时间加上自己需要的服务时间
            ans[num] = windows[win_index].end_time;
        } else { // 过了关门时间
            ans[num] = -1;
        }
        if (num <= N) // 各窗口的第一位客户的服务结束时间也是这个窗口空出位子的时间
            windows[win_index].pop_time = windows[win_index].end_time;
        num++;
    }
    while (num <= K) {
        int earliest = windows[1].pop_time, earliest_win = 1;
        for (int i = 2; i <= N; i++) // 寻找最早空出位子的窗口
            if (windows[i].pop_time < earliest) {
                earliest = windows[i].pop_time;
                earliest_win = i;
            }
        windows[earliest_win].q.pop();
        windows[earliest_win].q.push(serve_time[num]);
        windows[earliest_win].pop_time += windows[earliest_win].q.front();
        if (windows[earliest_win].end_time < close_time) {
            windows[earliest_win].end_time += serve_time[num];
            ans[num] = windows[earliest_win].end_time;
        } else {
            ans[num] = -1;
        }
        num++;
    }
    for (int i = 0, j = 0; i < Q; i++) {
        scanf("%d", &j);
        if (ans[j] > 0) {
            printf("%02d:%02d\n", ans[j] / 60, ans[j] % 60);
        } else {
            printf("Sorry\n");
        }
    }
    return 0;
}