#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define open_time 8 * 3600
#define close_time 17 * 3600
using namespace std;
struct Record {
    int arrive_time, serve_time;
    Record(const int &arrive, const int &serve) : arrive_time(arrive), serve_time(serve) {}
};

int main() {
    int N, K, wait = 0;
    cin >> N >> K;
    vector<Record> users;
    vector<int> windows(K, open_time);
    for (int i = 0, hour = 0, minute = 0, second = 0, arrive = 0, serve = 0; i < N; i++) {
        scanf("%d:%d:%d %d", &hour, &minute, &second, &serve);
        arrive = hour * 3600 + minute * 60 + second;
        if (arrive > close_time)
            continue;
        serve = (serve * 60) > 3600 ? 3600 : serve * 60;
        users.emplace_back(Record(arrive, serve));
    }
    sort(users.begin(), users.end(), [](const Record &a, const Record &b) { return a.arrive_time < b.arrive_time; });
    for (int i = 0; i < K && i < users.size(); i++) { // 先处理最先到的前K个客户
        if (users[i].arrive_time < open_time) { // 来得比开门早
            wait += open_time - users[i].arrive_time;
            windows[i] += users[i].serve_time;
        } else {
            windows[i] = users[i].arrive_time + users[i].serve_time;
        }
    }
    for (int i = K; i < users.size(); i++) {
        int ealiest = windows[0], ealiest_win = 0; // 找最先空闲出来的窗口
        for (int j = 1; j < K; j++)
            if (windows[j] < ealiest) {
                ealiest = windows[j];
                ealiest_win = j;
            }
        if (users[i].arrive_time < windows[ealiest_win]) { // 客户来得比窗口空出来早
            wait += ealiest - users[i].arrive_time;
            windows[ealiest_win] += users[i].serve_time;
        } else {
            windows[ealiest_win] = users[i].arrive_time + users[i].serve_time;
        }
    }
    printf("%.1f", wait / (60 * 1.0 * users.size()));
    return 0;
}