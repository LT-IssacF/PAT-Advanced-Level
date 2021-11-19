#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 0x7f
using namespace std;
struct node { // 邻接表
    int data, weight;
    vector<int> child;
} tree[MAX];
vector<int> pre; // 用来保存路径
// 字符串转换为整型
int GetData( char tempData[] ) {
    int data = 0;
    for( int i = 1, exponent = 1; i >= 0; i-- ) {
        data += ( tempData[i] - '0' ) * exponent;
        exponent *= 10;
    }
    return data;
}

bool cmp( int a, int b ) {
    return  tree[a].weight > tree[b].weight;
}
 // 这个递归记牢，静态写法经常用
void Print( int now, int root ) {
    if( now == root ) {
        cout << tree[root].weight;
        return;
    }
    Print( pre[now], root );
    cout << " " << tree[now].weight;
}

void DFS( int nowNode, int fatherNode, int sum, int S ) {
    sum += tree[nowNode].weight;
    int size = tree[nowNode].child.size( );
    if( sum > S ) // 超过S直接返回
        return;
    else if( sum == S ) {
        if( size > 0 ) // 非叶结点也直接返回
            return;
        else { // 满足条件
            pre[nowNode] = fatherNode; // 保存最后一个结点
            Print( nowNode, tree[0].data );
            cout << '\n';
        }
    }
    else {
        for( int i = 0; i < size; i++ ) { // 深度遍历当前结点的孩子
            pre[tree[nowNode].child[i]] = nowNode;
            DFS( tree[nowNode].child[i], nowNode, sum, S );
        } // pre数组其实也保存了整个树的父子结构关系除了因大于S而提前结束的那一部分树
    } // 只是需要使用其中一条符合条件的路径
} // 也就是说pre数组不光是保存结果的，结果只是pre数组里的一部分

int main( ) {
    int N, M, S;
    cin >> N >> M >> S;
    pre.resize( N );
    pre[0] = 0; // 根结点处理
    for( int i = 0; i < N; i++ )
        tree[i].data = i;
    vector<int> tempWeight;
    for( int i = 0, w = 0; i < N; i++ ) {
        cin >> w; // 权重是按结点序号给的
        tempWeight.push_back( w );
    }
    tree[0].weight = tempWeight[0]; // 根结点处理
    char tempData[3];
    for( int i = 0, k = 0, nodeData; i < M; i++ ) {
        cin >> tempData >> k;
        nodeData = GetData( tempData );
        for( int j = 0, childData = 0; j < k; j++ ) {
            cin >> tempData;
            childData = GetData( tempData );
            tree[nodeData].child.push_back( childData );
            tree[childData].weight = tempWeight[childData];
        } // 把每个结点的孩子按weight从大到小排才能符合题目要求
        sort( tree[nodeData].child.begin( ), tree[nodeData].child.end( ),cmp );
    }
    DFS( 0, 0, 0, S );
    return 0;
}