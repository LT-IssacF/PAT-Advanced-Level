#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
struct node {
    string data;
    int lchild, rchild;
};
vector<node> tree;
void PostTravel( const int &now ) { // 每棵子树都有三种情况，需要注意括号的位置
    if( tree[now].lchild == -1 && tree[now].rchild == -1 ) { // 第一种叶结点，直接括号包起来输出
        cout << "(" + tree[now].data;
    } else if( tree[now].lchild == -1 && tree[now].rchild != -1 ) { // 第二种左孩子空右孩子不空，先把左括号和当前data输出了，再递归处理右孩子，最后再输出自己的右括号
        cout << "(" + tree[now].data;
        PostTravel( tree[now].rchild );
    } else { // tree[now].lchild != -1 && tree[now].rchild != -1
        cout << "("; // 最后一种先把左括号输出了，再按后序遍历递归处理，最后再输出自己的右括号
        PostTravel( tree[now].lchild );
        PostTravel( tree[now].rchild );
        cout << tree[now].data;
    }
    cout << ")";
}

int main( ) {
    int N, root;
    cin >> N;
    tree.resize( N + 1 );
    vector<int> hashTable( N + 1, false );
    for( int i = 1; i <= N; i++ ) {
        cin >> tree[i].data >> tree[i].lchild >> tree[i].rchild;
        if( tree[i].lchild != -1 )
            hashTable[tree[i].lchild] = true;
        if( tree[i].rchild != -1 )
            hashTable[tree[i].rchild] = true;
    }
    for( int i = 1; i <= N; i++ )
        if( hashTable[i] == false ) {
            root = i;
            break;
        }
    PostTravel( root );
    return 0;
}
