#include <iostream>
using namespace std;
typedef struct BiNode {
    int data, height;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

BiTree NewNode( int key ) {
    BiTree T = ( BiTree ) malloc( sizeof( struct BiNode ) );
    T->data = key;
    T->height = 1;
    T->lchild = T->rchild = NULL;
    return T;
}
// 其实我觉得下面这几个高度相关的操作递归理解起来比左旋右旋难
int GetHeight( BiTree T ) {
    if( !T )
        return 0;
    return T->height;
}
// 平衡因子
int GetBalence( BiTree T ) {
    return GetHeight( T->lchild ) - GetHeight( T->rchild );
}
void UpdateHeight( BiTree T ) {
    T->height = max( GetHeight( T->lchild ), GetHeight( T->rchild ) ) + 1;
}
// 左旋
void LeftRotation( BiTree &T ) {
    BiTree temp = T->rchild;
    T->rchild = temp->lchild;
    temp->lchild = T;
    UpdateHeight( T );
    UpdateHeight( temp );
    T = temp;
}
// 右旋
void RightRotation( BiTree &T ) {
    BiTree temp = T->lchild;
    T->lchild = temp->rchild;
    temp->rchild = T;
    UpdateHeight( T );
    UpdateHeight( temp );
    T = temp;
}
// LL和LR型树都是左高右低，RR和RL型树是右高左低
// LL(2,1)是root的左子树左边高，而LR(2,-1)是root的左子树右边高
// 所以LL型一次右旋就可以了，而LR型要先对root的左子树左旋，再对root右旋
// RR和RL型同理
void Insert( BiTree &T, int key ) {
    if( !T ) {
        T = NewNode( key );
        return;
    }
    if( T->data > key ) { // 往左边插
        Insert( T->lchild, key );
        UpdateHeight( T );
        if( GetBalence( T ) == 2 ) {
            if( GetBalence( T->lchild ) == 1 ) { // LL型树
                RightRotation( T ); // 一次右旋
            }
            else if( GetBalence( T->lchild ) == -1 ) { // LR型树
                LeftRotation( T->lchild ); // 先对左子树左旋
                RightRotation( T ); // 再给自己右旋
            }
        }
    }
    else if( T->data < key ) { // 往右边插
        Insert( T->rchild, key );
        UpdateHeight( T );
        if( GetBalence( T ) == -2 ) {
            if( GetBalence( T->rchild ) == -1 ) { // RR型树
                LeftRotation( T ); // 一次左旋
            }
            else if( GetBalence( T->rchild ) == 1 ) { // RL型树
                RightRotation( T->rchild ); // 先对右子树右旋
                LeftRotation( T ); // 再对自己左旋
            }
        }
    }
}

int main( ) {
    int N;
    cin >> N;
    BiTree T = NULL;
    for( int i = 0, key = 0; i < N; i++ ) {
        cin >> key;
        Insert( T, key );
    }
    cout << T->data;
    return 0;
}