#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Record {
    string name;
    int month, date, hour, minute;
    bool tag;
}; // 储存原始数据
struct Bill {
    int start_date, start_hour, start_minute, end_date, end_hour, end_minute, time;
    double cost;
}; // 汇总后的原始数据
struct client {
    int month;
    vector<Bill> b;
    double total;
}; // 客户类
map<string, client> user; // 保存客户名字与其信息的映射
int price[25]; // 下标24的记录一整天的价格
bool cmp(const Record &a, const Record &b) {
    if (a.name != b.name) {
        return a.name < b.name;
    } else if (a.date != b.date) {
        return a.date < b.date;
    } else if (a.hour != b.hour) {
        return a.hour < b.hour;
    } else {
        return a.minute < b.minute;
    }
}

double Calculate(const Bill &temp) {
    // 分别计算从01日00时00分到开始时间和结束时间的花费，最后二者再相减
    int start = temp.start_minute * price[temp.start_hour] + (temp.start_date - 1) * 60 * price[24],
        end = temp.end_minute * price[temp.end_hour] + (temp.end_date - 1) * 60 * price[24];
    for (int i = temp.start_hour - 1; i >= 0; i--)
        start += 60 * price[i];
    for (int i = temp.end_hour - 1; i >= 0; i--)
        end += 60 * price[i];
    return (end - start) / 100.0;
}

int main() {
    for (int i = 0; i < 24; i++) {
        scanf("%d", &price[i]);
        price[24] += price[i];
    }
    int N;
    cin >> N;
    vector<Record> origin(N);
    for (int i = 0; i < N; i++) {
        cin >> origin[i].name;
        scanf("%d:%d:%d:%d", &origin[i].month, &origin[i].date, &origin[i].hour, &origin[i].minute);
        string status;
        cin >> status;
        origin[i].tag = (status == "on-line" ? true : false);
    }
    sort(origin.begin(), origin.end(), cmp); // 按客户记录的时间先后排序
    for (int i = 0; i < N - 1; i++) { // 如果一条记录和它后面紧邻的一条记录符合条件的话
        if ((origin[i].name == origin[i + 1].name) && (origin[i].tag == true && origin[i + 1].tag == false)) {
            Bill temp;
            user[origin[i].name].month = origin[i].month;
            temp.start_date = origin[i].date, temp.start_hour = origin[i].hour, temp.start_minute = origin[i].minute;
            temp.end_date = origin[i + 1].date, temp.end_hour = origin[i + 1].hour,
            temp.end_minute = origin[i + 1].minute;
            temp.time = ((temp.end_date - 1) * 60 * 24 + temp.end_hour * 60 + temp.end_minute) -
                        ((temp.start_date - 1) * 60 * 24 + temp.start_hour * 60 + temp.start_minute);
            temp.cost = Calculate(temp);
            user[origin[i].name].b.emplace_back(temp);
            user[origin[i].name].total += temp.cost;
            i++;
        }
    }
    for (map<string, client>::iterator it = user.begin(); it != user.end(); it++) {
        cout << it->first;
        printf(" %02d\n", it->second.month);
        for (int i = 0; i < it->second.b.size(); i++) {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", it->second.b[i].start_date, it->second.b[i].start_hour,
                   it->second.b[i].start_minute, it->second.b[i].end_date, it->second.b[i].end_hour,
                   it->second.b[i].end_minute, it->second.b[i].time, it->second.b[i].cost);
        }
        printf("Total amount: $%.2lf\n", it->second.total);
    }
    return 0;
}