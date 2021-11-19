#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct BiNode {
    int Data;
    struct BiNode *Left, *Right;
} BiNode, *BiTree;
int pre[32], post[32], in[32]; // 分别保存前序、中序、后序序列
// 由前序和中序序列建树
// BiTree Build_Tree( int preL, int preR, int inL, int inR ) {
//     if( preL > preR )
//         return NULL;
//     int i, numLeft;
//     for( i = inL; i <= inR; i++ )
//         if( in[i] == pre[preL] )
//             break;
//     numLeft = i - inL; // 左子树的个数
//     BiTree T = ( BiTree ) malloc( sizeof( struct BiNode ) );
//     T->Data = pre[preL];
//     T->Left = Build_Tree( preL + 1, preL + numLeft, inL, i - 1 );
//     T->Right = Build_Tree( preL + numLeft + 1, preR, i + 1, inR );
//     return T;
// }
// 由中序和后序序列建树
BiTree Build_Tree( int postL, int postR, int inL, int inR ) {
    if( postL > postR )
        return NULL;
    int i, numLeft;
    for( i = inL; i <= inR; i++ )
        if( in[i] == post[postR] )
            break;
    numLeft = i - inL; // 左子树的个数
    BiTree T = ( BiTree ) malloc( sizeof( struct BiNode ) );
    T->Data = post[postR];
    T->Left = Build_Tree( postL, postL + numLeft - 1, inL, i - 1 );
    T->Right = Build_Tree( postL + numLeft, postR - 1, i + 1, inR );
    return T;
}

void BFS( BiTree T ) {
    queue<BiTree> q;
    q.push( T );
    BiTree temp;
    vector<int> v;
    while( !q.empty( ) ) {
        temp = q.front( );
        q.pop( );
        v.push_back( temp->Data );
        if( temp->Left )
            q.push( temp->Left );
        if( temp->Right )
            q.push( temp->Right );
    }
    int length = v.size( );
    if( length )
        cout << v[0];
    for( int i = 1; i < length; i++ )
        cout << " " << v[i];
}

int main( ) {
    BiTree T;
    int N;
    cin >> N;
    for( int i = 0; i < N; i++ )
        cin >> post[i];
    for( int i = 0; i < N; i++ )
        cin >> in[i];
    T = Build_Tree( 0, N - 1, 0, N - 1 );
    BFS( T );
    return 0;
}