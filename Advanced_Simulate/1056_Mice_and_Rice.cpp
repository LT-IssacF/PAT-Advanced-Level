#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct programmer {
    int weight, rank;
};

int main() {
    int P, G;
    cin >> P >> G;
    vector<programmer> mice(P);
    for (int i = 0; i < P; i++)
        scanf("%d", &mice[i].weight);
    vector<int> order(P);
    queue<int> q;
    for (int i = 0; i < P; i++) {
        scanf("%d", &order[i]);
        q.push(order[i]); // 初始顺序
    }
    for (int totalMice = P, sum = 0, group = 0; q.size() > 1;) {
        group = q.size() % G == 0 ? q.size() / G : q.size() / G + 1; // 要处理的组数
        for (int i = 0, maxMice = 0, maxWeight = 0; i < group; i++) {
            maxMice = -1, maxWeight = -1; // 找每组权值最大的人
            for (int j = 0, front = 0; j < G && sum < totalMice; j++, sum++) {
                front = q.front();
                mice[front].rank = group + 1; // 本轮的等级都为组数+1
                if (mice[front].weight > maxWeight) {
                    maxWeight = mice[front].weight;
                    maxMice = front;
                }
                q.pop();
            }
            q.push(maxMice); // 权值最大的再进队
        }
        totalMice = q.size(), sum = 0; // 下一轮要处理的人数就是现在队列中元素的个数
    } // 最终队列只会剩下权值最大的
    mice[q.front()].rank = 1;
    printf("%d", mice[0].rank);
    for (int i = 1; i < P; i++)
        printf(" %d", mice[i].rank);
    return 0;
}