#include <iostream>
#include <cstring>
#include <vector>
#define MAX 0x3fffffff
using namespace std;
struct node {
    int v, dis; // 编号，边权
} temp;
vector<vector<node>> G; // 邻接表
vector<int> d;
vector<bool> visit;

int GetV( char str[], int N ) { // 输入转换函数
    int v = 0, exponent = 1, length = strlen( str );
    for( int i = length - 1; i >= 1; i-- ) { // 从后面往前面算，留最前面的0号位
        v += ( str[i] - '0' ) * exponent;
        exponent *= 10;
    }
    if( str[0] == 'G' ) // 是加油站
        return v + N; // 从N开始单独编号
    v += ( str[0] - '0' ) * exponent; // 是房屋就从1开始正常编号
    return v;
}

void Dijkstra( int N, int M, int s ) { // 最直白的一类迪哥算法不多讲
    fill( d.begin( ), d.end( ), MAX );
    fill( visit.begin( ), visit.end( ), false );
    d[s] = 0;
    for( int i = 0; i < N + M; i++ ) {
        int u = -1, min = MAX;
        for( int j = 1; j < N + M + 1; j++ ) {
            if( visit[j] == false && d[j] < min ) {
                u = j;
                min = d[j];
            }
        }
        if( u == -1 )
            return;
        visit[u] = true;
        int size = G[u].size( );
        for( int j = 0, v = 0; j < size; j++ ) {
            v = G[u][j].v;
            if( visit[v] == false && d[u] + G[u][j].dis < d[v] ) {
                d[v] = d[u] + G[u][j].dis;
            }
        }
    }
}

int main( ) {
    int N, M, K, D;
    cin >> N >> M >> K >> D;
    G.resize( N + M + 1 ); // 房屋是从1开始编号的
    d.resize( N + M + 1 );
    visit.resize( N + M + 1 );
    char city1[5], city2[5];
    for( int i = 0, v = 0, u = 0, w = 0; i < K; i++ ) {
        cin >> city1 >> city2 >> w;
        v = GetV( city1, N );
        u = GetV( city2, N );
        temp.v = u;
        temp.dis = w;
        G[v].push_back( temp );
        temp.v = v;
        G[u].push_back( temp );
    }
    int num = -1, minDis = 0;
    double minAvgDis = MAX;
    for( int s = N + 1; s < N + M + 1; s++ ) { // 枚举每个加油站
        int m = MAX, total = 0;
        double avgDis = 0;
        Dijkstra( N, M, s ); // 已获得从s开始到各个居民房的最短距离
        bool flag = true;
        for( int i = 1; i <= N; i++ ) {
            if( d[i] > D ) { // 有居民房超出范围，不用管这个加油站了
                flag = false;
                break;
            }
            if( d[i] < m )
                m = d[i];
            total += d[i];
        }
        if( flag == false ) // 不用管这个加油站
            continue;
        avgDis = 1.0 * total / N;
        if( m > minDis ) {
            num = s;
            minDis = m;
            minAvgDis = avgDis;
        }
        else if( m == minDis && avgDis < minAvgDis ) {
            num = s;
            minAvgDis = avgDis;
        }
    }
    if( num == -1 )
        cout << "No Solution";
    else {
        cout << "G" << num - N << endl;
        printf( "%d.0 %.1f", minDis, minAvgDis );
    }
    return 0;
}
