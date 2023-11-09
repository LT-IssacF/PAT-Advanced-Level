// #include <cstdio>
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
// struct node {
//     int in_degree; // 入度
//     queue<int> out_degree; // 连向的结点
// };
// bool Check(vector<node> G, const int &N) {
//     bool flag = true;
//     for (int i = 0, v1 = 0, v2 = 0; i < N; i++) {
//         scanf("%d", &v1);
//         if (G[v1].in_degree != 0) {
//             flag = false; // 如果当前访问的结点v1的入度不为0就不符合拓扑排序的特点
//         } else {
//             while (!G[v1].out_degree.empty()) { // 处理v1连向的所有结点
//                 v2 = G[v1].out_degree.front();
//                 G[v1].out_degree.pop(); // 消除边
//                 G[v2].in_degree--; // v2的度-1
//             }
//         }
//     }
//     return flag;
// }

// int main() {
//     int N, M, K;
//     cin >> N >> M;
//     vector<node> G(N + 1);
//     for (int i = 0, v1 = 0, v2 = 0; i < M; i++) {
//         scanf("%d %d", &v1, &v2);
//         G[v1].out_degree.push(v2);
//         G[v2].in_degree++;
//     }
//     cin >> K;
//     bool flag = false;
//     for (int i = 0; i < K; i++)
//         if (!Check(G, N)) {
//             if (flag)
//                 printf(" ");
//             printf("%d", i);
//             flag = true;
//         }
//     return 0;
// }

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int in_degree = 0; // 入度
    vector<int> out_degree; // 出度
};
bool Check(vector<node> G, const int &N) {
    bool flag = true;
    for (int i = 0, v = 0; i < N; i++) {
        scanf("%d", &v);
        if (flag == true) { // 结果成立判断才有意义
            if (G[v].in_degree != 0) { // 当前结点的入度不为0那么就不是拓扑排序
                flag = false;
            } else {
                for (const auto &j : G[v].out_degree) // 将入度为0的结点指向的结点的度都-1
                    G[j].in_degree--;
            }
        }
    }
    return flag;
}

int main() {
    int N, M, K;
    cin >> N >> M;
    vector<node> G(N + 1);
    for (int i = 1, v = 0, v2 = 0; i <= M; i++) {
        scanf("%d %d", &v, &v2);
        G[v].out_degree.push_back(v2);
        G[v2].in_degree++;
    }
    cin >> K;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (Check(G, N) == false) {
            if (flag == false) {
                printf("%d", i);
                flag = true;
            } else {
                printf(" %d", i);
            }
        }
    }
    return 0;
}