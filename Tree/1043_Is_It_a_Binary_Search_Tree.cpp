#include <iostream>
#include <vector>
using namespace std;
typedef struct BiNode {
    int Data;
    BiNode *Left, *Right;
} BiNode, *BiTree;
vector<int> input, pre, post, mirPre, mirPost;
// 插入
void Insert( BiTree &T, int key ) {
    if( T == NULL ) { // 插入位置
        T = ( BiTree ) malloc( sizeof( struct BiNode ) );
        T->Data = key;
        T->Left = T->Right = NULL;
    }
    else if( key < T->Data )
        Insert( T->Left, key );
    else
        Insert( T->Right, key );
}
// 前序遍历序列
void PreOrder( BiTree T, vector<int> &sequence ) {
    if( !T )
        return;
    sequence.push_back( T->Data );
    PreOrder( T->Left, sequence );
    PreOrder( T->Right, sequence );
}
// 后序遍历序列
void PostOrder( BiTree T, vector<int> &sequence ) {
    if( !T )
        return;
    PostOrder( T->Left, sequence );
    PostOrder( T->Right, sequence );
    sequence.push_back( T->Data );
}
// 镜像数的前序遍历序列
void Mir_PreOrder( BiTree T, vector<int> &sequence ) {
    if( !T )
        return;
    sequence.push_back( T->Data );
    Mir_PreOrder( T->Right, sequence );
    Mir_PreOrder( T->Left, sequence );
}
// 镜像数的后序遍历序列
void Mir_PostOrder( BiTree T, vector<int> &sequence ) {
    if( !T )
        return;
    Mir_PostOrder( T->Right, sequence );
    Mir_PostOrder( T->Left, sequence );
    sequence.push_back( T->Data );
}

void Print( vector<int> sequence ) {
    int size = sequence.size( );
    cout << sequence[0];
    for( int i = 1; i < size; i++ )
        cout << " " << sequence[i];
}

int main( ) {
    int N;
    cin >> N;
    BiTree T = NULL;
    for( int i = 0, temp = 0; i < N; i++ ) {
        scanf( "%d", &temp );
        input.push_back( temp );
        Insert( T, temp );
    }
    PreOrder( T, pre );
    PostOrder( T, post );
    Mir_PreOrder( T, mirPre );
    Mir_PostOrder( T, mirPost );
    if( pre == input ) { // 原树既是
        cout << "YES" << endl;
        Print( post );
    }
    else if( mirPre == input ) { // 原树的镜像树是
        cout << "YES" << endl;
        Print( mirPost );
    }
    else
        cout << "NO";
    return 0;
}