#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, dis, cost;
};
vector<vector<node>> G;
vector<int> d, c, pre;
vector<bool> visit;

void Dijkstra( int N, int S ) { // S为开始顶点
    fill( d.begin( ), d.end( ), INF );
    fill( c.begin( ), c.end( ), INF );
    fill( pre.begin( ), pre.end( ), -1 );
    fill( visit.begin( ), visit.end( ), false );
    d[S] = 0; // 赋初值，不能忘
    c[S] = 0;
    for( int i = 0, u = 0, min = 0; i < N; i++ ) { // N个顶点循环N次
        u = -1, min = INF;
        for( int j = 0; j < N; j++ ) { // 找到未访问顶点中d[]最小的
            if( visit[j] == false && d[j] < min ) {
                u = j;
                min = d[j];
            }
        }
        if( u == -1 )
            return;
        visit[u] = true; // 这句容易忘
        int size = G[u].size( );
        for( int j = 0, v = 0; j < size; j++ ) { // 枚举此顶点所能到达的其余顶点
            v = G[u][j].v;
            if( visit[v] == false ) {
                if( d[u] + G[u][j].dis < d[v] ) { // 更新最短路径
                    d[v] = d[u] + G[u][j].dis;
                    c[v] = c[u] + G[u][j].cost;
                    pre[v] = u; // 前驱
                }
                else if( d[u] + G[u][j].dis == d[v] && c[u] + G[u][j].cost < c[v] ) { // 路径长度相同但花费更少
                    c[v] = c[u] + G[u][j].cost; // 更新代价
                    pre[v] = u; // 同样的更新前驱
                }
            }
        }
    }
}

void DFS( int S, int v ) {
    if( S == v ) {
        cout << S << " ";
        return;
    }
    DFS( S, pre[v] );
    cout << v << " ";
}

int main( ) {
    int N, M, S, D;
    cin >> N >> M >> S >> D;
    G.resize( N );
    d.resize( N );
    c.resize( N );
    pre.resize( N );
    visit.resize( N );
    node temp;
    for( int i = 0, city1 = 0, city2 = 0, tempDis = 0, tempCost = 0; i < M; i++ ) {
        cin >> city1 >> city2 >> tempDis >> tempCost;
        temp.v = city2, temp.dis = tempDis, temp.cost = tempCost;
        G[city1].push_back( temp );
        temp.v = city1;
        G[city2].push_back( temp );
    }
    Dijkstra( N, S );
    DFS( S, D );
    cout << d[D] << " " << c[D];
    return 0;
}