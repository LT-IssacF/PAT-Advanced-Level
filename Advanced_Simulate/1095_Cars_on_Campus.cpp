#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Record {
    string num;
    int time;
    bool tag = false; // true代表in，false代表out
};

int main() {
    int N, M, maxParkedTime = 0;
    cin >> N >> M;
    vector<Record> origin(N), valid;
    string status, in = "in", out = "out";
    for (int i = 0, hour = 0, minute = 0, second = 0; i < N; i++) {
        cin >> origin[i].num;
        scanf("%d:%d:%d", &hour, &minute, &second);
        cin >> status;
        origin[i].time = hour * 3600 + minute * 60 + second;
        origin[i].tag = status == in;
    }
    sort(origin.begin(), origin.end(), [](const Record &a, const Record &b) {
        if (a.num != b.num) { // 一辆车的所有记录排一块
            return a.num < b.num;
        } else { // 一辆车的记录按时间排
            return a.time < b.time;
        }
    });
    map<string, int> cars; // key->车牌号，value->停放时间
    for (int i = 0; i < N; i++) // 是否是一辆车且必须是in out为一前一后
        if (origin[i].num == origin[i + 1].num && origin[i].tag == true && origin[i + 1].tag == false) {
            valid.emplace_back(origin[i]), valid.emplace_back(origin[i + 1]); // 前后两条记录都录入
            cars[origin[i].num] += origin[i + 1].time - origin[i].time; // 累计停放时间
            maxParkedTime = max(cars[origin[i].num], maxParkedTime); // 同时记下最大停车时间
            i++;
        }
    sort(valid.begin(), valid.end(), [](const Record &a, const Record &b) { return a.time < b.time; }); // 按时间排序
    for (int i = 0, j = 0, time = 0, hour = 0, minute = 0, second = 0, cnt = 0; i < M; i++) {
        scanf("%d:%d:%d", &hour, &minute, &second);
        time = hour * 3600 + minute * 60 + second;
        while (j < valid.size() && valid[j].time <= time) { // 利用查询时间递增的特性，不用每次都从头遍历
            if (valid[j].tag == true) { // in
                cnt++;
            } else { // out
                cnt--;
            }
            j++;
        }
        printf("%d\n", cnt);
    }
    for (const auto &i : cars)
        if (i.second == maxParkedTime)
            cout << i.first << " ";
    printf("%02d:%02d:%02d", maxParkedTime / 3600, maxParkedTime % 3600 / 60, maxParkedTime % 60);
    return 0;
}