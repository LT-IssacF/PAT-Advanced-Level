#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 0xff
#define INF 0x3fffffff
using namespace std;
struct node {
	int v, dis; // 城市编号，边权
} temp;
vector<vector<node>> G; // 邻接表
vector<int> d, w, pre, happiness, cntOfPath, cntOfCity; // 最短路径，最大总点权，保存的路径，点权数组以及相同距离的路径数和路径上的结点数量
vector<bool> visit; // 访问标记
map<string, int> nameToIndex; // 城市名字和编号相互转换的映射表
map<int, string> indexToName;
int index = 1, total = 0, avg = 0; // index的0留给开始城市

int GetIndex( string name, int N ) { // 得到城市编号并添加映射
	if( name.compare( string( "ROM" ) ) == 0 )
		return N - 1; // 最后一个位置给ROM，好看
	else {
		nameToIndex[name] = index;
		indexToName[index] = name;
		return index++;
	}
}

void Dijstra( int N, int s ) {
	fill( d.begin( ), d.end( ), INF );
	fill( w.begin( ), w.end( ), 0 );
	fill( pre.begin( ), pre.end( ), -1 );
	fill( cntOfPath.begin( ), cntOfPath.end( ), 0 );
	fill( cntOfCity.begin( ), cntOfCity.end( ), 0 );
	fill( visit.begin( ), visit.end( ), false );
	d[s] = 0; // 开始城市的初始化
	w[s] = 0;
	pre[s] = 0;
	cntOfPath[s] = 1;
	for( int i = 0, u = -1, min = INF; i < N; i++ ) { // 找每次能到的最近一个未访问过的城市
		u = -1, min = INF;
		for( int j = 0; j < N; j++ ) {
			if( visit[j] == false && d[j] < min ) {
				u = j;
				min = d[j];
			}
		}
		if( u == -1 )
			return;
		int size = G[u].size( );
		visit[u] = true; // 下面是核心代码
		for( int k = 0, v = 0; k < size; k++ ) {
			v = G[u][k].v;
			if( visit[v] == false && d[u] + G[u][k].dis < d[v] ) { // 以u为中介点使d[v]更短
				d[v] = d[u] + G[u][k].dis; // 更新d[v]和w[v]
				w[v] = w[u] + happiness[v];
				cntOfPath[v] = cntOfPath[u]; // 都在一条路径上，所以覆盖
				cntOfCity[v] = cntOfCity[u] + 1; // 把v算进去不就加1了
				pre[v] = u; // 保存路径
			}
			else if( visit[v] == false && d[u] + G[u][k].dis == d[v] ) { // 距离相同的不同路径比总点权
				cntOfPath[v] += cntOfPath[u]; // 不同的是距离相同的路径数是继承的
				if( w[u] + happiness[v] > w[v] ) { // 以u为中介点使w[v]更大
					w[v] = w[u] + happiness[v];
					cntOfCity[v] = cntOfCity[u] + 1;
					pre[v] = u;
				}
				else if( w[u] + happiness[v] == w[v] ) { // 总点权还一样就算平均点权
					double uAvg = 1.0 * ( w[u] + happiness[v] ) / ( cntOfCity[u] + 1 ); // 以u为中介点的
					double vAvg = 1.0 * w[v] / cntOfCity[v]; // 不算u的
					if( uAvg > vAvg ) {
						cntOfCity[v] = cntOfCity[u] + 1;
						pre[v] = u;
					}
				}
			}
		}
	}
}

void ShowPath( int v ) {
	if( v == 0 ) {
		cout << indexToName[v];
		return;
	}
	ShowPath( pre[v] );
	cout << "->" << indexToName[v];
}

int main( ) {
	int N, K, city1, city2;
	string start, name1, name2;
	cin >> N >> K >> start;
	G.resize( N );
	d.resize( N );
	w.resize( N );
	pre.resize( N );
	happiness.resize( N );
	cntOfPath.resize( N );
	cntOfCity.resize( N );
	visit.resize( N );
	nameToIndex[start] = 0;
	indexToName[0] = start;
	nameToIndex[string( "ROM" )] = N - 1;
	indexToName[N - 1] = string( "ROM" );
	for( int i = 1, num = 0; i < N; i++ ) {
		cin >> name1;
		num = GetIndex( name1, N );
		cin >> happiness[num];
	}
	for( int i = 0, tempDis = 0; i < K; i++ ) {
		cin >> name1 >> name2 >> tempDis;
		city1 = nameToIndex[name1], city2 = nameToIndex[name2];
		temp.v = city2, temp.dis = tempDis;
		G[city1].push_back( temp );
		temp.v = city1;
		G[city2].push_back( temp ); // 无向图双向处理
	}
	Dijstra( N, 0 );
	cout << cntOfPath[N - 1] << " " << d[N - 1] << " " << w[N - 1] << " ";
	printf( "%d\n", w[N - 1] / cntOfCity[N - 1] );
	ShowPath( N - 1 );
	return 0;
}
