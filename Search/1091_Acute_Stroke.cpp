#include <cstdio>
#include <iostream>
#include <queue>
#define line 1300
#define column 1300
#define slice 64
using namespace std;
struct node {
    int x, y, z;
};
int matrix[line][column][slice] = {0}; // 矩阵
bool visit[line][column][slice] = {false}; // 标记数组
int biasX[6] = {1, -1, 0, 0, 0, 0}; // 增量数组
int biasY[6] = {0, 0, 1, -1, 0, 0};
int biasZ[6] = {0, 0, 0, 0, 1, -1};
int M, N, L, T;
bool Check(const node &coord) {
    if (coord.x < 0 || coord.x >= M || coord.y < 0 || coord.y >= N || coord.z < 0 || coord.z >= L) { // 越界
        return false;
    } else if (matrix[coord.x][coord.y][coord.z] == 0 || visit[coord.x][coord.y][coord.z] == true) { // 元素为0或已访问过
        return false;
    } else {
        return true;
    }
}

int BFS(const node &coord) {
    queue<node> q;
    q.push(coord);
    visit[coord.x][coord.y][coord.z] = true;
    int cnt = 0;
    while (!q.empty()) {
        node front = q.front();
        cnt++;
        q.pop();
        for (int i = 0, newX = 0, newY = 0, newZ = 0; i < 6; i++) { // 分别枚举左右，上下，高低6个方向
            newX = front.x + biasX[i], newY = front.y + biasY[i], newZ = front.z + biasZ[i];
            if (Check(node{newX, newY, newZ})) {
                q.push(node{newX, newY, newZ});
                visit[newX][newY][newZ] = true;
            }
        }
    }
    return (cnt >= T ? cnt : 0);
}

int main() {
    cin >> M >> N >> L >> T;
    for (int i = 0, j = 0, k = 0; i < L; i++)
        for (j = 0; j < M; j++)
            for (k = 0; k < N; k++)
                scanf("%d", &matrix[j][k][i]);
    int cnt = 0;
    for (int i = 0, j = 0, k = 0; i < L; i++)
        for (j = 0; j < M; j++)
            for (k = 0; k < N; k++)
                if (matrix[j][k][i] == 1 && visit[j][k][i] == false) // 按行列片枚举的不可能越界
                    cnt += BFS(node{j, k, i});
    cout << cnt;
    return 0;
}