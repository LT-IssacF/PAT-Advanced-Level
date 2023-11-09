#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct Record {
    char id[7], name[9];
    int grade;
};
bool cmp_id(const Record &a, const Record &b) { // 按id升序排序
    return strcmp(a.id, b.id) < 0;
}
bool cmp_name(const Record &a, const Record &b) {
    if (strcmp(a.name, b.name) != 0) { // 名字不同就按名字升序排序
        return strcmp(a.name, b.name) < 0;
    } else { // 名字相同就按id升序排序
        return strcmp(a.id, b.id) < 0;
    }
}
bool cmp_grade(const Record &a, const Record &b) {
    if (a.grade != b.grade) { // 分数不同按分数升序排序
        return a.grade < b.grade;
    } else { // 同样的
        return strcmp(a.id, b.id) < 0;
    }
}
// 送分题
int main() {
    int N, C;
    cin >> N >> C;
    vector<Record> stu(N);
    for (int i = 0; i < N; i++)
        scanf("%s %s %d", &stu[i].id, &stu[i].name, &stu[i].grade);
    switch (C) {
    case 1:
        sort(stu.begin(), stu.end(), cmp_id);
        break;
    case 2:
        sort(stu.begin(), stu.end(), cmp_name);
        break;
    case 3:
        sort(stu.begin(), stu.end(), cmp_grade);
    }
    for (int i = 0; i < N; i++)
        printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    return 0;
}