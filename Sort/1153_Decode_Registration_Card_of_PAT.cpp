#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Record {
    string str; // 可能储存card也有可能储存site
    int value; // 有可能储存socre也可能记录次数
}; // 这个类是精髓，完美理解运用了题意，即情况1和情况3是一回事
vector<Record> t;
bool cmp(const Record &a, const Record &b) {
    return a.value == b.value ? a.str < b.str : a.value > b.value;
} // 情况1和情况3都是先按值降序排，再按键非降序排

int main() {
    int N, M, type;
    cin >> N >> M;
    t.resize(N);
    for (int i = 0; i < N; i++)
        cin >> t[i].str >> t[i].value;
    string term;
    for (int i = 1; i <= M; i++) {
        cin >> type >> term;
        printf("Case %d: %d %s\n", i, type, term.c_str());
        vector<Record> ans;
        int total = 0, cnt = 0;
        switch (type) {
        case 1: // 情况1
            for (int j = 0; j < N; j++)
                if (t[j].str[0] == term[0])
                    ans.push_back(t[j]);
            break;
        case 2: // 情况2
            for (int j = 0; j < N; j++)
                if (t[j].str.substr(1, 3) == term) {
                    total += t[j].value;
                    cnt++;
                }
            if (cnt != 0)
                cout << cnt << " " << total << endl;
            break;
        case 3: // 情况3
            unordered_map<string, int> m;
            for (int j = 0; j < N; j++)
                if (t[j].str.substr(4, 6) == term)
                    m[t[j].str.substr(1, 3)]++; // map不需要判断有没有这个键，初值都是0
            for (auto it : m)
                ans.push_back({it.first, it.second});
        }
        int size = ans.size();
        if ((type != 2 && size == 0) || (type == 2 && cnt == 0))
            cout << "NA" << endl; // 统一输出特殊情况
        else if (size > 0) {
            sort(ans.begin(), ans.end(), cmp);
            for (int j = 0; j < size; j++)
                printf("%s %d\n", ans[j].str.c_str(), ans[j].value);
        }
    }
    return 0;
}