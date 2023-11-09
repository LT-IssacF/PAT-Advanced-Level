#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct Record {
    int id, rank, cnt = 0, total = 0, grade[6] = {-1, -1, -1, -1, -1, -1};
    bool pass = false;
};
void Print(const vector<Record> &stu, const int &i, const int &K) {
    printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].total);
    for (int j = 1; j <= K; j++) {
        if (stu[i].grade[j] > -1) {
            printf(" %d", stu[i].grade[j]);
        } else {
            printf(" -");
        }
    }
    printf("\n");
}

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    vector<Record> stu(N + 1);
    vector<int> problem(K + 1);
    for (int i = 1; i <= K; i++)
        scanf("%d", &problem[i]);
    for (int i = 0, id = 0, p_id = 0, t_grade = 0; i < M; i++) {
        scanf("%d %d %d", &id, &p_id, &t_grade);
        stu[id].id = id;
        if (t_grade > -1) {
            stu[id].pass = true;
            if (t_grade == problem[p_id] && stu[id].grade[p_id] < problem[p_id]) {
                stu[id].cnt++;
                stu[id].grade[p_id] = t_grade;
            } else if (t_grade > stu[id].grade[p_id]) {
                stu[id].grade[p_id] = t_grade;
            }
        } else if (t_grade == -1 && stu[id].grade[p_id] == -1) {
            stu[id].grade[p_id] = 0;
        }
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; stu[i].pass == true && j <= K; j++)
            if (stu[i].grade[j] > -1)
                stu[i].total += stu[i].grade[j];
    sort(stu.begin(), stu.end(), [](const Record &a, const Record &b) {
        if (a.pass != b.pass) {
            return a.pass > b.pass;
        } else if (a.total != b.total) {
            return a.total > b.total;
        } else if (a.cnt != b.cnt) {
            return a.cnt > b.cnt;
        } else {
            return a.id < b.id;
        }
    });
    stu[0].rank = 1;
    Print(stu, 0, K);
    for (int i = 1; i <= N; i++) {
        if (stu[i].pass == false) {
            break;
        } else {
            if (stu[i].total == stu[i - 1].total) {
                stu[i].rank = stu[i - 1].rank;
            } else {
                stu[i].rank = i + 1;
            }
            Print(stu, i, K);
        }
    }
    return 0;
}