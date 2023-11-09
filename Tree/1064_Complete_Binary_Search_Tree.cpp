#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int arr[1020] = {0}, tree[1020] = {0};
void InOrder(int &now, const int &root, const int &N) {
    if (root > N)
        return;
    InOrder(now, root * 2, N);
    tree[root] = arr[now++];
    InOrder(now, root * 2 + 1, N);
}
// 中序遍历按数组顺序挨个插入即可
int main() {
    int N, now = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + N); // 二叉搜索树的中序序列是严格递增的
    InOrder(now, 1, N); // root不能设为0
    cout << tree[1];
    for (int i = 2; i <= N; i++)
        printf(" %d", tree[i]);
    return 0;
}