#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int lchild, rchild;
}; // 静态树
vector<node> tree;
bool hashTable[32] = { false }; // 用来找根
int CharToInt( string str ) { // 把数据转换成整型
    if( str[0] == '-' )
        return -1; // 无孩子就标记为-1
    int length = str.length( ), ans = 0;
    for( int i = length - 1, exponent = 1; i >= 0; i--, exponent *= 10 ) {
        ans += ( str[i] - '0' ) * exponent;
    }
    hashTable[ans] = true;
    return ans;
}

int main( ) {
    int N, root, front;
    cin >> N;
    tree.resize( N );
    for( int i = 0; i < N; i++ ) {
        string left, right;
        cin >> left >> right;
        tree[i].lchild = CharToInt( left );
        tree[i].rchild = CharToInt( right );
    }
    for( int i = 0; i < N; i++ ) // 找根
        if( !hashTable[i] ) {
            root = i;
            break;
        }
    // 层序遍历，当遍历到某个结点，发现其任意一个孩子为空时，标记，
    // 往后继续遍历时，若出现某结点的任意一个孩子不为空则不是完全二叉树
    bool shouldBeComplete = true, startCheck = false; // 分别为是否是完全二叉树和是否开始检查
    queue<int> q;
    q.push( root );
    while( !q.empty( ) ) {
        front = q.front( );
        q.pop( );
        if( tree[front].lchild == -1 && tree[front].rchild != -1 ) { // 左空右不空一定不是完全二叉树
            shouldBeComplete = false;
            break;
        } // 检查本轮
        if( startCheck && ( tree[front].lchild != -1 || tree[front].rchild != -1 ) ) {
            shouldBeComplete = false;
            break;
        } // 开始检查了，发现有结点的任意孩子为空
        if( tree[front].lchild != -1 )
            q.push( tree[front].lchild );
        if( tree[front].rchild != -1 )
            q.push( tree[front].rchild );
        if( tree[front].lchild == -1 || tree[front].rchild == -1 ) // 两个孩子任意为空下一轮就开始检查
            startCheck = true;
    }
    if( shouldBeComplete )
        cout << "YES " << front;
    else
        cout << "NO " << root;
    return 0;
}
/* 2022第一道AC题，只可惜不是在昨天，希望接下来好运连连
   stay hungry, stay foolish. */
