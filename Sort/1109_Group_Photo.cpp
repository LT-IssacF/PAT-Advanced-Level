#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct Record {
    string name;
    int height;
};

int main() {
    int N, K, it = 0;
    cin >> N >> K;
    int columns = N / K;
    vector<Record> stu(N);
    for (int i = 0; i < N; i++)
        cin >> stu[i].name >> stu[i].height;
    sort(stu.begin(), stu.end(), [](const Record &a, const Record &b) {
        if (a.height != b.height) {
            return a.height > b.height;
        } else {
            return a.name < b.name;
        }
    });
    vector<vector<string>> ans(K);
    for (int i = 0, central = 0, size = 0; i < K; i++) { // 从最后一排也就是要输出的第一排开始
        size = i > 0 ? columns : columns + N % K; // 每排人数
        ans[i].resize(size);
        central = size / 2; // 中间的那个人
        ans[i][central] = stu[it++].name;
        for (int j = 1, bias = 1; j < size; j++, it++) {
            if (j % 2 != 0) { // 先左后右
                ans[i][central - bias] = stu[it].name;
            } else { // 右边处理完了就增加偏移量
                ans[i][central + bias++] = stu[it].name;
            }
        }
        for (int j = 0; j < size - 1; j++) // 输出
            printf("%s ", ans[i][j].c_str());
        printf("%s\n", ans[i][size - 1].c_str());
    }
    return 0;
}