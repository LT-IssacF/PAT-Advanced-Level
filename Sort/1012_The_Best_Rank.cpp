#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#define WORSE 0xffff
using namespace std;
struct Record {
    int id, best_sub, best_rank = WORSE;
    int grade[4], rank[4]; // A C M E
};
map<int, Record> ans;

int main() {
    int N, M;
    cin >> N >> M;
    vector<Record> stu(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &stu[i].id);
        for (int j = 1; j <= 3; j++) {
            scanf("%d", &stu[i].grade[j]);
            stu[i].grade[0] += stu[i].grade[j];
        }
    }
    for (int tag = 0; tag < 4; tag++) { // 获取4门成绩的排名
        sort(stu.begin(), stu.end(), [tag](const Record &a, const Record &b) { return a.grade[tag] > b.grade[tag]; }); // 按每门成绩降序排序
        stu[0].rank[tag] = 1; // 最高分第一名
        if (stu[0].best_rank > 1) // 如果他最好的排名不是第一的话就要更新
            stu[0].best_rank = 1, stu[0].best_sub = tag;
        for (int i = 1; i < N; i++) {
            if (stu[i].grade[tag] == stu[i - 1].grade[tag]) {
                stu[i].rank[tag] = stu[i - 1].rank[tag];
            } else {
                stu[i].rank[tag] = i + 1;
            }
            if (stu[i].best_rank > stu[i].rank[tag]) // 同理
                stu[i].best_rank = stu[i].rank[tag], stu[i].best_sub = tag;
        }
    }
    for (int i = 0; i < N; i++) // 建立映射
        ans[stu[i].id] = stu[i];
    for (int i = 0, id = 0; i < M; i++) {
        scanf("%d", &id);
        map<int, Record>::iterator it = ans.find(id);
        if (it == ans.end()) {
            printf("N/A\n");
        } else {
            printf("%d ", it->second.best_rank);
            switch (it->second.best_sub) {
            case 0:
                printf("A\n");
                break;
            case 1:
                printf("C\n");
                break;
            case 2:
                printf("M\n");
                break;
            case 3:
                printf("E\n");
                break;
            }
        }
    }
    return 0;
}