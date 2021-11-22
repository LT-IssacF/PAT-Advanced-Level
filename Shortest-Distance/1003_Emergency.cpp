#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;
struct node {
    int v, w, dis;
}; // v为城市号，w为救援队数量点权，dis为距离边权
vector<vector<node>> G; // 邻接表
vector<int> d, pathNum, teamGather, tempTeam;
vector<bool> visit;
// d储存最短路径长度，pathNum储存最短路径数量，teamGather储存能带的队伍数量
void Dijkstra( int N, int city1 ) { // city1为起始顶点
    fill( d.begin( ), d.end( ), INF ); // INF意味不可达
    fill( pathNum.begin( ), pathNum.end( ), 0 );
    fill( teamGather.begin( ), teamGather.end( ), 0 );
    fill( visit.begin( ), visit.end( ), false );
    d[city1] = 0; // 赋初值
    pathNum[city1] = 1;
    teamGather[city1] = tempTeam[city1];
    for( int i = 0; i < N; i++ ) {
        int u = -1, min = INF;
        for( int j = 0; j < N; j++ ) {
            if( visit[j] == false && d[j] < min ) {
                u = j;
                min = d[j];
            }
        }
        if( u == -1 )
            return;
        visit[u] = true; // 容易忘写
        int size = G[u].size( );
        for( int j = 0, v = 0; j < size; j++ ) {
            v = G[u][j].v; // 城市号
            if( visit[v] == false ) {
                if( d[u] + G[u][j].dis < d[v] ) { // 更新最短路径
                    d[v] = d[u] + G[u][j].dis;
                    teamGather[v] = teamGather[u] + G[u][j].w;
                    pathNum[v] = pathNum[u];
                }
                else if( d[u] + G[u][j].dis == d[v] ) { // 路径长度相等
                    if( teamGather[u] + G[u][j].w > teamGather[v] ) { // 且此路径能带的队伍更多
                        teamGather[v] = teamGather[u] + G[u][j].w;
                    }
                    pathNum[v] += pathNum[u]; // 更新路径数量
                }
            }
        }
    }
}

int main( ) {
    int N, M, city1, city2;
    cin >> N >> M >> city1 >> city2;
    G.resize( N );
    d.resize( N );
    pathNum.resize( N );
    teamGather.resize( N );
    visit.resize( N );
    for( int i = 0, tempTeamCnt; i < N; i++ ) {
        cin >> tempTeamCnt;
        tempTeam.push_back( tempTeamCnt ); // 城市i有tempTeamCnt个救援队
    }
    node temp;
    for( int i = 0, c1 = 0, c2 = 0, dis = 0; i < M; i++ ) {
        cin >> c1 >> c2 >> dis;
        temp.dis = dis;
        temp.v = c2;
        temp.w = tempTeam[c2];
        G[c1].push_back( temp );
        temp.v = c1;
        temp.w = tempTeam[c1];
        G[c2].push_back( temp );
    } // G[c1][i].v表示c1到其连通的第i个城市(i从0开始)的城市号
    // G[c1][i].dis表示c1到其连通的第i个城市的距离，G[c1][i].w表示从c1到其连通的第i个城市可以带上该城市内的w个救援队
    Dijkstra( N, city1 );
    cout << pathNum[city2] << " " << teamGather[city2];
}
