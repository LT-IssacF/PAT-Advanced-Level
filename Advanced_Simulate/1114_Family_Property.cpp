#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct Record { // 储存原始记录
    int id, fid, mid, kcnt, estate, area;
    vector<int> kids;
};
struct node { // 家族信息
    int id, cnt = 0, estate = 0, area = 0;
    double avg_estate, avg_area;
};
unordered_map<int, node> families; // 键为id
unordered_set<int> people; // 记下所有出现过的id
int father[10000];
int FindFather(int key) {
    int x = key;
    while (key != father[key])
        key = father[key];
    while (x != father[x]) { // 压缩路径
        int a = x;
        x = father[x];
        father[a] = key;
    }
    return key;
}

void Union(const int &a, const int &b) {
    int faA = FindFather(a), faB = FindFather(b);
    if (faA < faB) { // id小的当父结点
        father[faB] = faA;
    } else {
        father[faA] = faB;
    }
}

int main() {
    int N;
    cin >> N;
    vector<Record> input(N);
    for (int i = 0; i < 10000; i++) // 并查集初始化
        father[i] = i;
    for (int i = 0, id, fid, mid, kcnt; i < N; i++) {
        scanf("%d %d %d %d", &id, &fid, &mid, &kcnt);
        input[i].id = id, input[i].fid = fid, input[i].mid = mid, input[i].kcnt = kcnt;
        people.insert(id);
        if (fid >= 0) {
            people.insert(fid);
            Union(fid, id);
        }
        if (mid >= 0) {
            people.insert(mid);
            Union(mid, id);
        }
        for (int j = 0, kid = 0; j < kcnt; j++) {
            scanf("%d", &kid);
            input[i].kids.push_back(kid);
            people.insert(kid);
            Union(id, kid);
        }
        scanf("%d %d", &input[i].estate, &input[i].area);
    }
    for (const auto &i : input) { // 统计家族信息
        int fid = FindFather(i.id); // 找到每个Record的族长
        families[fid].id = fid;
        families[fid].estate += i.estate, families[fid].area += i.area;
    }
    for (const int &id : people) { // 统计家族人数
        int fid = FindFather(id);
        families[fid].cnt++;
    }
    vector<node> ans;
    for (auto &it : families) {
        it.second.avg_estate = it.second.estate * 1.0 / it.second.cnt,
        it.second.avg_area = it.second.area * 1.0 / it.second.cnt;
        ans.emplace_back(it.second);
    }
    sort(ans.begin(), ans.end(), [](const node &a, const node &b) {
        if (a.avg_area != b.avg_area) {
            return a.avg_area > b.avg_area;
        } else {
            return a.id < b.id;
        }
    });
    cout << ans.size() << endl;
    for (const node &i : ans)
        printf("%04d %d %.3lf %.3lf\n", i.id, i.cnt, i.avg_estate, i.avg_area);
    return 0;
}