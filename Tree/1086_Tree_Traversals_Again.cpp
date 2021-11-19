#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
typedef struct BiNode {
    int Data;
    struct BiNode *Left, *Right;
} BiNode, *BiTree;
vector<int> pre, in, post;
// 这题没啥好讲的，就是输入用了栈，其他在前面的遍历那说过了
BiTree Build_Tree( int preL, int preR, int inL, int inR ) {
    if( preL > preR )
        return NULL;
    int i, numLeft;
    for( i = 0; i <= preR; i++ )
        if( in[i] == pre[preL] )
            break;
    numLeft = i - inL;
    BiTree T = ( BiTree ) malloc( sizeof( struct BiNode ) );
    T->Data = pre[preL];
    T->Left = Build_Tree( preL + 1, preL + numLeft, inL, i - 1 );
    T->Right = Build_Tree( preL + numLeft + 1, preR, i + 1, inR );
    return T;
}

void Traversals( BiTree T ) {
    if( !T )
        return;
    Traversals( T->Left );
    Traversals( T->Right );
    post.push_back( T->Data );
}

int main( ) {
    int N;
    cin >> N;
    stack<int> s;
    string order;
    for( int i = 0, temp = 0; i < 2 * N; i++ ) {
        cin >> order;
        if( order == "Push" ) {
            cin >> temp;
            pre.push_back( temp );
            s.push( temp );
        }
        else {
            in.push_back( s.top( ) );
            s.pop( );
        }
    }
    BiTree T = Build_Tree( 0, N - 1, 0, N - 1 );
    Traversals( T );
    int size = post.size( );
    if( size > 0 )
        cout << post[0];
    for( int i = 1; i < size; i++ )
        cout << " " << post[i];
    return 0;
}