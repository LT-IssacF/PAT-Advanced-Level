#include <iostream>
#include <vector>
using namespace std;
struct node {
    string data;
    int lchild, rchild;
};
string DFS(const int &now, const int &root, vector<node> &tree) {
    if (now < 0)
        return "";
    if (tree[now].rchild >= 0) { // 左不空右空的式子不存在，所以只用判断右孩子
        tree[now].data = DFS(tree[now].lchild, root, tree) + tree[now].data + DFS(tree[now].rchild, root, tree);
        if (now != root)
            tree[now].data = "(" + tree[now].data + ")";
    }
    return tree[now].data;
}
// 中序遍历
int main() {
    int N, root = 1;
    cin >> N;
    vector<node> tree(N + 1);
    vector<bool> hashTable(N + 1, false);
    for (int i = 1; i <= N; i++) {
        cin >> tree[i].data >> tree[i].lchild >> tree[i].rchild;
        if (tree[i].lchild >= 0)
            hashTable[tree[i].lchild] = true;
        if (tree[i].rchild >= 0)
            hashTable[tree[i].rchild] = true;
    }
    while (hashTable[root] == true)
        root++;
    cout << DFS(root, root, tree);
    return 0;
}