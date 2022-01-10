#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in, post;
bool flag = true;
void GetIn( int preL, int preR, int postL, int postR ) {
    if( preL == preR ) { // 到达一棵子树最左下的叶结点
        in.push_back( pre[preL] );
        return;
    }
    if( pre[preL] == post[postR] ) { // 处理一棵子树的根结点
        int numLeft; // 这棵子树左子树的结点个数
        for( int i = preL + 1; i <= preR; i++ )
            if( pre[i] == post[postR - 1] ) { // 后序序列中前一个元素就是该子树的右子树的根结点
                numLeft = i - preL - 1; // 所以在前序中就可以求出该子树左子树的结点个数
                break;
            }
        if( numLeft != 0 ) // 左子树不空就递归处理这棵子树
            GetIn( preL + 1, preL + numLeft, postL, postL + numLeft - 1 );
        else // 左子树为空那么很明显树不唯一
            flag = false;
        in.push_back( post[postR] ); // 进栈当前根结点
        GetIn( preL + numLeft + 1, preR, postL + numLeft, postR - 1 ); // 递归处理右子树
    } // 结合中序遍历——左、根、右的特点递归处理左右子树
}

int main( ) {
    int N;
    cin >> N;
    pre.resize( N ), post.resize( N );
    for( int i = 0; i < N; i++ )
        cin >> pre[i];
    for( int i = 0; i < N; i++ )
        cin >> post[i];
    GetIn( 0, N - 1, 0, N - 1 );
    cout << ( flag ? "Yes" : "No" );
    cout << endl << in[0];
    for( int i = 1; i < N; i++ )
        cout << " " << in[i];
    cout << endl;
    return 0;
}
