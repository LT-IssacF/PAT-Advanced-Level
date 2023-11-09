#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node {
    string data;
    int lchild, rchild;
};
string PostTravals(const int &now, const vector<node> &tree) {
    if (tree[now].lchild < 0) {
        if (tree[now].rchild < 0) { // 叶结点
            return "(" + tree[now].data + ")";
        } else { // 没有左子树，得先根再往右子树上递归
            return "(" + tree[now].data + PostTravals(tree[now].rchild, tree) + ")";
        }
    } else { // 左右孩子都在，左右根后续递归
        return "(" + PostTravals(tree[now].lchild, tree) + PostTravals(tree[now].rchild, tree) + tree[now].data + ")";
    }
}

int main() {
    int N, root = 1;
    cin >> N;
    vector<node> tree(N + 1);
    vector<bool> hashTable(N + 1, false);
    for (int i = 1; i <= N; i++) {
        cin >> tree[i].data >> tree[i].lchild >> tree[i].rchild;
        if (tree[i].lchild > 0)
            hashTable[tree[i].lchild] = true;
        if (tree[i].rchild > 0)
            hashTable[tree[i].rchild] = true;
    }
    while (root <= N && hashTable[root] == true)
        root++;
    printf("%s", PostTravals(root, tree).c_str());
    return 0;
}