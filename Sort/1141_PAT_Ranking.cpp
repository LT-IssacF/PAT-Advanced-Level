#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct school {
    string name;
    int score, cnt;
};
unordered_map<string, double> m_score; // 以学校的名字为键值，处理输入阶段
unordered_map<string, int> m_cnt;
vector<school> ans;
bool cmp(const school &a, const school &b) {
    if (a.score != b.score) {
        return a.score > b.score;
    } else if (a.cnt != b.cnt) {
        return a.cnt < b.cnt;
    } else {
        return a.name < b.name;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0, score = 0; i < N; i++) {
        string id, school;
        cin >> id >> score >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if (id[0] == 'A') {
            m_score[school] += score;
        } else if (id[0] == 'B') {
            m_score[school] += score / 1.5;
        } else {
            m_score[school] += score * 1.5;
        }
        m_cnt[school]++;
    }
    for (auto it = m_cnt.begin(); it != m_cnt.end(); it++)
        ans.emplace_back(school{it->first, (int)m_score[it->first], m_cnt[it->first]});
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    cout << 1 << " " << ans[0].name << " " << ans[0].score << " " << ans[0].cnt;
    for (int i = 1, rank = 1; i < ans.size(); i++) {
        if (ans[i].score != ans[i - 1].score)
            rank = i + 1;
        cout << endl << rank << " " << ans[i].name << " " << ans[i].score << " " << ans[i].cnt;
    }
    return 0;
}
