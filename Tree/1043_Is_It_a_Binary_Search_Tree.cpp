#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef struct BiNode {
    int data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
vector<int> input, pre, post, mirPre, mirPost;
void Insert( BiTree &T, const int &key ) { // 插入
    if( T == NULL ) {  // 插入位置
        T = ( BiTree ) malloc ( sizeof( BiNode ) );
        T->data = key;
        T->lchild = T->rchild = NULL;
        return;
    } else if( key < T->data ) {
        Insert( T->lchild, key );
    } else {
        Insert( T->rchild, key );
    }
}

void PreOrder( const BiTree &T ) {
    if( T == NULL )
        return;
    pre.push_back( T->data );
    PreOrder( T->lchild );
    PreOrder( T->rchild );
}

void PostOrder( const BiTree &T ) {
    if( T == NULL )
        return;
    PostOrder( T->lchild );
    PostOrder( T->rchild );
    post.push_back( T->data );
}

void MirPreOrder( const BiTree &T ) {
    if( T == NULL )
        return;
    mirPre.push_back( T->data );
    MirPreOrder( T->rchild );
    MirPreOrder( T->lchild );
}

void MirPostOrder( const BiTree &T ) {
    if( T == NULL )
        return;
    MirPostOrder( T->rchild );
    MirPostOrder( T->lchild );
    mirPost.push_back( T->data );
}

void Print( const vector<int> &sequence ) {
    for( const int &i : sequence ) {
        if( i != sequence[0] )
            printf( " " );
        printf( "%d", i );
    }
}

int main( ) {
    int N;
    cin >> N;
    BiTree T = NULL;
    for( int i = 0, data = 0; i < N; i++ ) {
        scanf( "%d", &data );
        Insert( T, data ); // 每次调用都从树根处递归建树
        input.push_back( data );
    }
    PreOrder( T );
    if( pre == input ) {
        printf( "YES\n" );
        PostOrder( T );
        Print( post );
    } else {
        MirPreOrder( T );
        if( mirPre == input ) {
            printf( "YES\n" );
            MirPostOrder( T );
            Print( mirPost );
        }
        else {
            printf( "NO" );
        }
    }
    return 0;
}
