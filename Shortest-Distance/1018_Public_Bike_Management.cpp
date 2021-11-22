#include <iostream>
#include <vector>
#include <cmath>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, w, dis;
} temp;
vector<vector<node>> G; // 邻接表
vector<int> d, path, tempPath;
vector<bool> visit;
vector<vector<int>> pre; // 记录前驱
int minRemain = INF, minNeed = INF;
// 全局变量最少剩余车辆，最少初始携带车辆
void Dijkstra( int N, int start ) {
    fill( d.begin( ), d.end( ), INF );
    fill( visit.begin( ), visit.end( ), false );
    d[start] = 0; // 初始城市处理
    for( int i = 0; i < N; i++ ) {
        int u = -1, MIN = INF;
        for( int j = 0; j < N; j++ ) {
            if( visit[j] == false && d[j] < MIN ) {
                u = j;
                MIN = d[j];
            }
        }
        if( u == -1 )
            return;
        int size = G[u].size( );
        visit[u] = true;
        for( int j = 0, v = 0; j < size; j++ ) {
            v = G[u][j].v;
            if( visit[v] == false ) {
                if( d[u] + G[u][j].dis < d[v] ) {
                    d[v] = d[u] + G[u][j].dis;
                    pre[v].clear( ); // 更新最短路径了就要清空前驱
                    pre[v].push_back( u ); // 记下前驱
                }
                else if( d[u] + G[u][j].dis == d[v] )
                    pre[v].push_back( u ); // 最短路径不唯一，即有多个前驱
            }
        }
    }
}

void DFS( int v ) { // 从S倒着深度遍历回PBMC
    if( v == 0 ) { // 递归到边界即PBMC就把这一路的结点计算
        tempPath.push_back( v );
        int remain = 0, need = 0, size = tempPath.size( );
        for( int i = size - 1; i >= 0; i-- ) {
            int id = tempPath[i];
            if( G[id][0].w > 0 ) // 站点车多了
                remain += G[id][0].w;
            else if( G[id][0].w < 0 ) { // 站点车不够
                int tempNeed = abs( G[id][0].w );
                if( remain >= tempNeed )
                    remain -= tempNeed;
                else {
                    need += tempNeed - remain;
                    remain = 0;
                }
            }
        }
        if( need < minNeed ) {
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        }
        else if( need == minNeed && remain < minRemain ) {
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back( ); // 真正保存结果的路径已在path中保存
        return; // 这个和下面的俩个pop是为了回溯到分叉结点
    }
    tempPath.push_back( v ); // 加入路径
    int size = pre[v].size( );
    for( int i = 0; i < size; i++ )
        DFS( pre[v][i] ); // 深度遍历v的前驱
    tempPath.pop_back( );
}

int main( ) {
    int C, N, S, M;
    cin >> C >> N >> S >> M;
    G.resize( N + 1 ); // N不包括下标为0的PBMC
    d.resize( N + 1 );
    visit.resize( N + 1 );
    pre.resize( N + 1 );
    vector<int> tempWeight;
    tempWeight.resize( N + 1 );
    for( int i = 1; i <= N; i++ ) {
        cin >> tempWeight[i];
        tempWeight[i] -= ( C / 2 );
    } // 这里对点权车辆数量做了处理，取2/C为零点，方便计算
    for( int i = 0, c1 = 0, c2 = 0, tempDis = 0; i < M; i++ ) {
        cin >> c1 >> c2 >> tempDis;
        temp.dis = tempDis;
        temp.v = c2; // c1->c2的
        temp.w = tempWeight[c1];
        G[c1].push_back( temp );
        temp.v = c1; // c2->c1的
        temp.w = tempWeight[c2];
        G[c2].push_back( temp );
    }
    Dijkstra( N + 1, 0 );
    DFS( S );
    cout << minNeed << " ";
    for( int i = path.size( ) - 1; i >= 0; i-- ) {
        if( i != 0 )
            cout << path[i] << "->";
        else
            cout << path[i];
    }
    cout << " " << minRemain;
    return 0;
}
