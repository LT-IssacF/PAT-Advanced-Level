#include <iostream>
#include <cstdio>
using namespace std;
struct node {
    int data = 0, lchild = 0, rchild = 0;
} tree[0x3ff];
void PostTravals( const int &N, const int &now, bool &flag ) {
    if( now == 0 ) {
        return;
    } else if( now <= N ) {
        PostTravals( N, tree[now].lchild, flag );
        PostTravals( N, tree[now].rchild, flag );
        if( flag == false ) {
            printf( "%d", tree[now].data );
            flag = true;
        } else {
            printf( " %d", tree[now].data );
        }
    }
}

int main( ) {
    int M, N;
    cin >> M >> N;
    for( int i = 0; i < M; i++ ) {
        for( int j = 1; j <= N; j++ ) {
            scanf( "%d", &tree[j].data );
            if( j <= N / 2 ) { // 为非叶结点设置左右指针
                tree[j].lchild = 2 * j, tree[j].rchild = 2 * j + 1;
            }
            if( j == 2 ) { // 用第二个结点和根结点判断堆的性质
                tree[0].data = tree[1].data >= tree[2].data ? 1 : 2; // tree[0].data储存堆最初的性质
            }
            if( tree[0].data > 0 && j > 2 ) { // 之前的结点依旧满足堆的性质再判断
                if( tree[0].data == 1 ) { // 大顶堆
                    if( tree[j / 2].data < tree[j].data ) { // 父结点的值小于孩子结点的值就不是堆
                        tree[0].data = 0;
                    }
                } else { // 小顶堆
                    if( tree[j / 2].data >= tree[j].data ) {// 父结点的值大于等于孩子结点的值就不是堆
                        tree[0].data = 0;
                    }
                }
            }
        }
        printf( "%s\n", tree[0].data > 0 ? ( tree[0].data == 1 ? "Max Heap" : "Min Heap" ) : "Not Heap" );
        bool flag = false;
        PostTravals( N, 1, flag );
        printf( "\n" );
    }
    return 0;
}
