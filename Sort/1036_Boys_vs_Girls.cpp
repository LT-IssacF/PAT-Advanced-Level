#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct Record {
    char gender, name[11], id[11];
    int grade;
};

int main() {
    int N;
    cin >> N;
    vector<Record> stu(N);
    for (int i = 0; i < N; i++)
        scanf("%s %c %s %d", &stu[i].name, &stu[i].gender, &stu[i].id, &stu[i].grade);
    sort(stu.begin(), stu.end(), [](const Record &a, const Record &b) {
        if (a.gender != b.gender) {
            return a.gender < b.gender;
        } else {
            return a.grade > b.grade;
        }
    });
    if (stu[0].gender != 'F') {
        printf("Absent\n");
    } else {
        printf("%s %s\n", stu[0].name, stu[0].id);
    }
    if (stu.back().gender != 'M') {
        printf("Absent\n");
    } else {
        printf("%s %s\n", stu.back().name, stu.back().id);
    }
    if (stu[0].gender != 'F' || stu.back().gender != 'M') {
        printf("NA\n");
    } else {
        printf("%d\n", stu[0].grade - stu.back().grade);
    }
    return 0;
}