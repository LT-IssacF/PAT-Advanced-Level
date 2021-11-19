#include <iostream>
#include <algorithm>
#define MAX 1020
using namespace std;
int tree[MAX] = { -1 }, arr[MAX] = { -1 };
// 类似1099，不同的是这道的是从0开始连续递增所以更方便
// 一个二叉搜索树的中序序列是递增的，中序遍历时将数组挨个插入
void InOrder( int root, int N, int &index ) {
    if( root > N )
        return;
    InOrder( root * 2, N, index );
    tree[root] = arr[index++];
    InOrder( root * 2 + 1, N, index );
}

int main( ) {
    int N;
    cin >> N;
    for( int i = 0; i < N; i++ )
        cin >> arr[i];
    sort( arr, arr + N );
    int index = 0;
    InOrder( 1, N, index );
    cout << tree[1];
    for( int i = 2; i <= N; i++ )
        cout << " " << tree[i];
    return 0;
}