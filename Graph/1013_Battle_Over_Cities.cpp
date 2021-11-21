#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> G;
vector<bool> visit;
// 深度遍历单个连通图
void DFS( int now ) {
    visit[now] = true; // 访问标记
    int size = G[now].size( );
    for( int i = 0, v = 0; i < size; i++ ) {
        v = G[now][i];
        if( visit[v] == false ) {
            DFS( v );
        }
    }
}
// 用来获取连通块数
int DFS_Travels( int key ) {
    fill( visit.begin( ), visit.end( ), false ); // 重置访问标记
    visit[key] = true; // 相当于置此城市is lost
    int numOfConnect = 0, size = G.size( );
    for( int i = 1; i < size; i++ ) {
        if( visit[i] == false ) {
            DFS( i );
            numOfConnect++;
        }
    }
    // 假设图G有n个连通块，那么使它们都连通的最简单方法就是给n1到n2一条边，n2到n3一条边……
    // 以此类推n个连通块的图最少需要n-1条边才能全都连通，所以题目也就变成了求一个图的连通块数的问题
    // 在乎哪个城市就是标记这个城市再去遍历，题解就是得到的连通块数-1
    return numOfConnect - 1;
}

int main( ) {
    int N, M, K;
    cin >> N >> M >> K;
    G.resize( N + 1 );
    visit.resize( N + 1 );
    for( int i = 0, city1 = 0, city2 = 0; i < M; i++ ) {
        cin >> city1 >> city2;
        G[city1].push_back( city2 ); // 处理输入无向图
        G[city2].push_back( city1 );
    }
    vector<int> caresCity;
    for( int i = 0, temp = 0; i < K; i++ ) {
        cin >> temp;
        caresCity.push_back( temp );
    }
    for( int i = 0, repaired = 0; i < K; i++ ) {
        repaired = DFS_Travels( caresCity[i] );
        cout << repaired << endl;
    }   
    return 0;
}