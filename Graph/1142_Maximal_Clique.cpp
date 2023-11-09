#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    bool G[201][201] = {false}; // 用邻接矩阵判断效率更好
    for (int i = 0, v = 0, v2 = 0; i < M; i++) {
        scanf("%d %d", &v, &v2);
        G[v][v2] = G[v2][v] = true;
    }
    cin >> M;
    for (int i = 0, K = 0; i < M; i++) {
        scanf("%d", &K);
        bool isClique = true, isMaximal = true;
        vector<int> tmp; // 记录clique结点编号
        unordered_map<int, bool> appearance; // 标记结点已出现
        for (int j = 0, v = 0; j < K; j++) {
            scanf("%d", &v);
            appearance[v] = true;
            for (const auto &v2 : tmp) { // clique每进来一个结点就与之前的每个结点判断有无边
                if (isClique == false || G[v][v2] == false) {
                    isClique = false;
                    break;
                }
            }
            tmp.push_back(v);
        }
        if (isClique == false) {
            printf("Not a Clique\n");
        } else { // 是clique
            for (int j = 1; j <= N && isMaximal == true; j++) { // 从1开始挨个试是否能加入clique
                if (appearance.find(j) == appearance.end()) { // 必须是非原clique结点
                    int cnt = 0; // 与clique中结点有边的计数器
                    for (const int &v : tmp) {
                        if (G[j][v] == true) {
                            cnt++;
                        }
                    }
                    if (cnt == K) { // 与原clique每个结点都有边就不是Maximal
                        isMaximal = false;
                    }
                }
            }
            if (isMaximal == true) {
                printf("Yes\n");
            } else {
                printf("Not Maximal\n");
            }
        }
    }
    return 0;
}