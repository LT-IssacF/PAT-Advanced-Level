#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct BiNode {
    int data, level;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
vector<int> in, post;
vector<BiTree> ans;

BiTree Insert( const int &inL, const int &inR, const int &postL, const int &postR, const int &level ) {
    if( postL > postR )
        return NULL;
    int numLeft, i;
    for( i = inL; i <= inR; i++ )
        if( in[i] == post[postR] )
            break;
    numLeft = i - inL;
    BiTree T = ( BiTree ) malloc( sizeof( BiNode ) );
    T->data = post[postR], T->level = level;
    T->lchild = Insert( inL, i - 1, postL, postL + numLeft - 1, level + 1 );
    T->rchild = Insert( i + 1, inR, postL + numLeft, postR - 1, level + 1 );
    return T;
}

void BFS( const BiTree &T ) {
    queue<BiTree> q;
    q.push( T );
    while( !q.empty( ) ) {
        BiTree front = q.front( );
        ans.push_back( front );
        q.pop( );
        if( front->lchild )
            q.push( front->lchild );
        if( front->rchild )
            q.push( front->rchild );
    }
}

void Print( const int &N ) {
    int depth = ans[N - 1]->level; // 获取整棵树的高度
    cout << ans[0]->data;
    if( ans.size( ) > 1 ) {
        for( int i = ans[1]->level, j = 1; i <= depth; i++ ) {
            if( i % 2 == 0 ) { // 偶数层顺序输出
                while( j < N && ans[j]->level == i ) {
                    cout << " " << ans[j]->data;
                    j++;
                } 
            } else { // 奇数层倒序输出
                int cnt = 0; // 记录这一层的结点个数
                while( j < N && ans[j]->level == i ) {
                    cnt++;
                    j++;
                } // 循环结束j已经指向下一层首结点了
                for( int k = 1; k <= cnt; k++ )
                    cout << " " << ans[j - k]->data;
            }
        }
    }
}

int main( ) {
    int N;
    cin >> N;
    in.resize( N ), post.resize( N );
    for( int i = 0; i < N; i++ )
        cin >> in[i];
    for( int i = 0; i < N; i++ )
        cin >> post[i];
    BiTree T = Insert( 0, N - 1, 0, N - 1, 1 );
    BFS( T );
    Print( N );
    return 0;
}
