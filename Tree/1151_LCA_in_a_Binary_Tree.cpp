#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef struct BiNode {
    int data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
vector<int> in, pre;
unordered_map<int, int> order;
BiTree Build( const int &preL, const int &preR, const int &inL, const int &inR ) {
    if( preL > preR )
        return NULL;
    int numLeft, i;
    for( i = inL; i <= inR; i++ )
        if( in[i] == pre[preL] ) {
            numLeft = i - inL;
            break;
        }
    BiTree T = ( BiTree ) malloc( sizeof( BiNode ) );
    T->data = pre[preL];
    T->lchild = Build( preL + 1, preL + numLeft, inL, i - 1 );
    T->rchild = Build( preL + numLeft + 1, preR, i + 1, inR );
    return T;
}

void LCA( const BiTree &T, const int &u, const int &v ) {
    if( ( order[u] < order[T->data] && order[v] > order[T->data] ) || ( order[u] > order[T->data] && order[v] < order[T->data] ) ) {
        printf( "LCA of %d and %d is %d.\n", u, v, T->data );
    } else if( order[u] == order[T->data] || order[v] == order[T->data] ) {
        printf( "%d is an ancestor of %d.\n", T->data, ( order[v] == order[T->data] ? u : v ) );
    } else if( order[u] < order[T->data] && order[v] < order[T->data] ) {
        LCA( T->lchild, u, v );
    } else {
        LCA( T->rchild, u, v );
    }
}

int main( ) {
    int M, N;
    cin >> M >> N;
    in.resize( N + 1 ), pre.resize( N + 1 );
    for( int i = 1; i <= N; i++ ) {
        scanf( "%d", &in[i] );
        order[in[i]] = i; // 很重要的一点就是中序遍历的结果就是一棵树的结点从左到右出现的顺序
    } // 所以就根据中序遍历里结点出现的顺序来判断，这是核心
    for( int i = 1; i <= N; i++ )
        scanf( "%d", &pre[i] );
    BiTree T = Build( 1, N, 1, N );
    for( int i = 0, u = 0, v = 0; i < M; i++ ) {
        scanf( "%d %d", &u, &v );
        if( order[u] == 0 && order[v] == 0 ) {
            printf( "ERROR: %d and %d are not found.\n", u, v );
        } else if( order[u] == 0 || order[v] == 0 ) {
            printf( "ERROR: %d is not found.\n", ( order[u] == 0 ? u : v ) );
        } else { // 我比较笨，只会先建树再比较
            LCA( T, u, v );
        }
    }
    return 0;
}
