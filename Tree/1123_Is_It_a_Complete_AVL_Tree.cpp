#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef struct BiNode {
    int data, height;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
int GetHeight( const BiTree &T ) {
    return T == NULL ? 0 : T->height;
}

int GetBalance( const BiTree &T ) {
    return GetHeight( T->lchild ) - GetHeight( T->rchild );
}

void UpdateHeight( BiTree &T ) {
    T->height = max( GetHeight( T->lchild ), GetHeight( T->rchild ) ) + 1;
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

void Insert( BiTree &T, const int &key ) {
    if( T == NULL ) {
        T = ( BiTree ) malloc( sizeof( BiNode ) );
        T->data = key, T->height = 1;
        T->lchild = T->rchild = NULL;
        return;
    }
    if( T->data > key ) {
        Insert( T->lchild, key );
        UpdateHeight( T );
        if( GetBalance( T ) == 2 ) {
            if( GetBalance( T->lchild ) == 1 ) {
                RightRotation( T );
            } else if( GetBalance( T->lchild ) == -1 ) {
                LeftRotation( T->lchild );
                RightRotation( T );
            }
        }
    } else {
        Insert( T->rchild, key );
        UpdateHeight( T );
        if( GetBalance( T ) == -2 ) {
            if( GetBalance( T->rchild ) == -1 ) {
                LeftRotation( T );
            } else if( GetBalance( T->rchild ) == 1 ) {
                RightRotation( T->rchild );
                LeftRotation( T );
            }
        }
    }
}

bool BFS( const BiTree &T ) {
    queue<BiTree> q;
    q.push( T );
    bool startToCheck = false, ans = true;
    while( !q.empty( ) ) {
        BiTree front = q.front( );
        if( front == T ) {
            printf( "%d", front->data );
        } else {
            printf( " %d", front->data );
        }
        q.pop( );
        if( front->lchild == NULL && front->rchild != NULL )
            ans = false;
        if( startToCheck == true && ( front->lchild != NULL || front->rchild != NULL ) )
            ans = false;
        if( front->lchild != NULL )
            q.push( front->lchild );
        if( front->rchild != NULL )
            q.push( front->rchild );
        if( front->lchild == NULL || front->rchild == NULL )
            startToCheck = true;
    }
    return ans;
}
// 建AVL树在1066中详细说明过，判断一棵树是不是完全二叉树在1110中也说明过
int main( ) {
    int N;
    cin >> N;
    BiTree T = NULL;
    for( int i = 0, key = 0; i < N; i++ ) {
        scanf( "%d", &key );
        Insert( T, key );
    }
    printf( "\n%s", BFS( T ) ? "YES" : "NO" );
    return 0;
}
