#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Record {
    string school;
    double tws_d = 0;
    int tws_i = 0, ns = 0;
};

int main() {
    int N;
    cin >> N;
    unordered_map<string, Record> m;
    for (int i = 0; i < N; i++) {
        string id, school;
        double score;
        cin >> id >> score >> school;
        for (auto &c : school) { // 规范化学校名
            if (c >= 'A' && c <= 'Z') {
                c = tolower(c);
            }
        }
        switch (id[0]) {
        case 'B':
            score /= 1.5;
            break;
        case 'T':
            score *= 1.5;
        }
        m[school].tws_d += score, m[school].ns++;
    }
    vector<Record> ans;
    for (auto &i : m) {
        i.second.school = i.first, i.second.tws_i = static_cast<int>(i.second.tws_d);
        ans.emplace_back(i.second);
    }
    sort(ans.begin(), ans.end(), [](const Record &a, const Record &b) {
        if (a.tws_i != b.tws_i) {
            return a.tws_i > b.tws_i;
        } else if (a.ns != b.ns) {
            return a.ns < b.ns;
        } else {
            return a.school < b.school;
        }
    });
    cout << ans.size() << endl;
    printf("1 %s %d %d\n", ans[0].school.c_str(), ans[0].tws_i, ans[0].ns);
    for (int i = 1, rank = 1; i < ans.size(); i++) {
        if (ans[i].tws_i != ans[i - 1].tws_i) {
            rank = i + 1;
        }
        printf("%d %s %d %d\n", rank, ans[i].school.c_str(), ans[i].tws_i, ans[i].ns);
    }
    return 0;
}