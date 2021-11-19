#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 0xff
using namespace std;
struct node { // 邻接表
    int data, layer;
    vector<int> child;
} tree[MAX];
vector<int> ans;

int GetData( char tempData[] ) {
    int data = 0;
    for( int i = 1, exponent = 1; i >= 0; i-- ) {
        data += ( tempData[i] - '0' ) * exponent;
        exponent *= 10;
    }
    return data;
}

void LayerOrder( int root ) { // 即BFS
    queue<int> q;
    tree[root].layer = 1;
    int numOfLeaftree = 0, nowLayer = tree[root].layer;
    q.push( root );
    while( !q.empty( ) ) {
        int front = q.front( );
        if( nowLayer != tree[front].layer ) { // 已经到下一层
            ans.push_back( numOfLeaftree ); // 保存叶子结点个数
            numOfLeaftree = 0; // 更新信息
            nowLayer = tree[front].layer;
        }
        q.pop( );
        int size = tree[front].child.size( );
        if( size == 0 ) // 叶子结点+1
            numOfLeaftree++;
        else {
            for( int i = 0; i < size; i++ ) {
                tree[tree[front].child[i]].layer = tree[front].layer + 1;
                q.push( tree[front].child[i] );
            }
        }
    }
    ans.push_back( numOfLeaftree ); // 保存最后一层的叶子结点个数
}

int main( ) {
    int N, M;
    cin >> N >> M;
    for( int i = 0, k = 0, treeData = 0; i < M; i++ ) {
        char tempData[3];
        cin >> tempData >> k;
        treeData = GetData( tempData );
        tree[treeData].data = treeData;
        for( int j = 0, childData = 0; j < k; j++ ) {
            cin >> tempData;
            childData = GetData( tempData );
            tree[treeData].child.push_back( childData );
            tree[childData].data = childData;
        }
    }
    LayerOrder( 1 );
    int size = ans.size( );
    cout << ans[0];
    for( int i = 1; i < size; i++ )
        cout << " " << ans[i];
    return 0;
}