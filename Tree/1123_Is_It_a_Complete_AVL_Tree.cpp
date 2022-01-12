#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct BiNode {
    int data, height;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
bool shouldBeComplete = true, startCheck = false;
BiTree NewNode( int key ) {
    BiTree T = ( BiTree ) malloc( sizeof( struct BiNode ) );
    T->data = key;
    T->height = 1;
    T->lchild = T->rchild = NULL;
    return T;
}

int GetHeight( const BiTree &T ) {
    if( !T )
        return 0;
    return T->height;
}

void UpdateHeight( BiTree &T ) {
    T->height = max( GetHeight( T->lchild ), GetHeight( T->rchild ) ) + 1;
}

int GetBalence( const BiTree &T) {
    return GetHeight( T->lchild ) - GetHeight( T->rchild );
}

void LeftRotation( BiTree &T ) {
    BiTree temp = T->rchild;
    T->rchild = temp->lchild;
    temp->lchild = T;
    UpdateHeight( T );
    UpdateHeight( temp );
    T = temp;
}

void RightRotation( BiTree &T ) {
    BiTree temp = T->lchild;
    T->lchild = temp->rchild;
    temp->rchild = T;
    UpdateHeight( T );
    UpdateHeight( temp );
    T = temp;
}

void Insert( BiTree &T, int key ) {
    if( !T ) {
        T = NewNode( key );
        return;
    }
    else if( T->data > key ) {
        Insert( T->lchild, key );
        UpdateHeight( T );
        if( GetBalence( T ) == 2 ) {
            if( GetBalence( T->lchild ) == 1 )
                RightRotation( T );
            else if( GetBalence( T->lchild ) == -1 ) {
                LeftRotation( T->lchild );
                RightRotation( T );
            }
        }
    }
    else if( T->data < key ) {
        Insert( T->rchild, key );
        UpdateHeight( T );
        if( GetBalence( T ) == -2 ) {
            if( GetBalence( T->rchild ) == -1 )
                LeftRotation( T );
            else if( GetBalence( T->rchild ) == 1 ) {
                RightRotation( T->rchild );
                LeftRotation( T );
            }
        }
    }
}
// 建AVL树在1066中详细说明过，判断一棵树是不是完全二叉树在1110中也说明过
void BFS( const BiTree &T ) {
    queue<BiTree> q;
    q.push( T );
    while( !q.empty( ) ) {
        BiTree front = q.front( );
        if( front != T )
            cout << " ";
        cout << front->data;
        q.pop( );
        if( !front->lchild && front->rchild )
            shouldBeComplete = false;
        if( startCheck && ( front->lchild || front->rchild ) )
            shouldBeComplete = false;
        if( front->lchild )
            q.push( front->lchild );
        if( front->rchild )
            q.push( front->rchild );
        if( !front->lchild || !front->rchild )
            startCheck = true;
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
    BFS( T );
    cout << endl << ( shouldBeComplete ? "YES" : "NO" );
    return 0;
}
