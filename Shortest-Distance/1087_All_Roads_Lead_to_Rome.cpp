#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 0xff
#define INF 0x3fffffff
using namespace std;
vector<bool> visit; // 访问标记
map<string, int> nameToIndex; // 城市名字和编号相互转换的映射表
map<int, string> indexToName;
// Dijstra+DFS*****个人更喜欢这种，纯Dijstra不好理解
int G[MAX][MAX] = { INF }; // 邻接矩阵在DFS时很方便
vector<int>d, happiness, path, tempPath; // 储存到每个城市的最短距离，点权和路径
vector<vector<int>> pre; // 记录前驱
int index = 1, totalHappiness = 0, cntOfPath = 0; // index的0留给开始城市
double avgHappiness = 0;
// 根据编译器不同，index可能会起名冲突
int GetIndex( int N, string name ) {
	if( name == "ROM" )
		return N - 1; // 最后一个位置留给ROM
	else {
		nameToIndex[name] = index;
		indexToName[index] = name;
		return index++;
	}
}

void Dijstra( int N, int start ) {
	fill( d.begin( ), d.end( ), INF );
	fill( visit.begin( ), visit.end( ), false );
	d[start] = 0;
	for( int i = 0, u = -1, min = INF; i < N; i++ ) {
		u = -1, min = INF;
		for( int j = 0; j < N; j++ ) {
			if( visit[j] == false && d[j] < min ) {
				u = j;
				min = d[j];
			}
		}
		if( u == -1 )
			return;
		visit[u] = true;
		for( int j = 0; j < N; j++ ) {
			if( G[u][j] != INF && visit[j] == false ) { // 两个城市间有边且后者没被访问过
				if( d[u] + G[u][j] < d[j] ) {
					d[j] = d[u] + G[u][j];
					pre[j].clear( ); // 清空前驱
					pre[j].push_back( u ); // 城市u是城市j最短路径上的直接前驱
				}
				else if( d[u] + G[u][j] == d[j] ) {
					pre[j].push_back( u ); // 城市j的前驱不止一个，即不止一条最短路径
				}
			}
		}
	}
}

void DFS( int N, int start ) {
	if( start == 0 ) { // 深度递归到起点了
		tempPath.push_back( start );
		int tempTotalDis = 0, size = tempPath.size( );
		for( int i = 0; i < size - 1; i++ ) { // eg:5条边4个结点
			tempTotalDis += G[tempPath[i]][tempPath[i + 1]]; // 计算距离
		}
		if( tempTotalDis == d[N - 1] ) { // 是通往ROM的最短路径
			cntOfPath++; // 这样的路径+1
			int tempTotalHappiness = 0;
			double tempAvgHappiness = 0;
			for( int i = 0; i < size - 1; i++ ) // 把这条路径上的点权加起来，但起点点权为0
				tempTotalHappiness += happiness[tempPath[i]];
			tempAvgHappiness = 1.0 * tempTotalHappiness / ( size - 1 ); // 不算起点
			if( tempTotalHappiness > totalHappiness ) { // 注意不是直接判断平均点权的，要先判断总点权大小
				totalHappiness = tempTotalHappiness;
				avgHappiness = tempAvgHappiness;
				path = tempPath;
			}
			else if( tempTotalHappiness == totalHappiness ) { // 总点权相等了
				if( tempAvgHappiness > avgHappiness ) { // 再判断平均点权
					avgHappiness = tempAvgHappiness;
					path = tempPath;
				}
			}
		}
		return;
	}
	tempPath.push_back( start );
	int size = pre[start].size( ); // 分叉数量即前驱
	for( int i = 0; i < size; i++ ) {
		DFS( N, pre[start][i] );
		tempPath.pop_back( ); // 回溯到分叉处
	}
}

void Print( ) {
	int size = path.size( );
	for( int i = size - 1; i > 0; i-- )
		cout << indexToName[path[i]] << "->";
	cout << indexToName[path[0]];
}

int main( ) {
	int N, K, city1, city2;
	string start, name1, name2;
	cin >> N >> K >> start;
	visit.resize( N );
	d.resize( N );
	happiness.resize( N );
	pre.resize( N );
	nameToIndex[start] = 0;
	indexToName[0] = start;
	nameToIndex[string( "ROM" )] = N - 1;
	indexToName[N - 1] = string( "ROM" );
	for( int i = 0, num = 0; i < N - 1; i++ ) {
		cin >> name1;
		num = GetIndex( N, name1 );
		cin >> happiness[num];
	} // 处理点权并建立映射
	fill( G[0], G[0] + MAX * MAX, INF );
	for( int i = 0, dis = 0; i < K; i++ ) {
		cin >> name1 >> name2 >> dis;
		city1 = nameToIndex[name1];
		city2 = nameToIndex[name2];
		G[city1][city2] = dis;
		G[city2][city1] = dis;
	}
	for( int i = 0; i < N; i++ )
		G[i][i] = 0; // 每个城市到它自己的距离都是0
	Dijstra( N, 0 );
	DFS( N, N - 1 );
	cout << cntOfPath << " " << d[N - 1] << " " << totalHappiness << " " << ( int )avgHappiness << endl;
	Print( );
	return 0;
}

// 纯Dijstra
// struct node {
// 	int v, dis; // 城市编号，边权
// } temp;
// vector<vector<node>> G; // 邻接表
// vector<int> d, w, pre, happiness, cntOfPath, cntOfCity; // 最短路径，最大总点权，保存的路径，点权数组以及相同距离的路径数和路径上的结点数量
// vector<bool> visit; // 访问标记
// map<string, int> nameToIndex; // 城市名字和编号相互转换的映射表
// map<int, string> indexToName;

// int GetIndex( string name, int N ) { // 得到城市编号并添加映射
// 	if( name.compare( string( "ROM" ) ) == 0 )
// 		return N - 1; // 最后一个位置给ROM，好看
// 	else {
// 		nameToIndex[name] = index;
// 		indexToName[index] = name;
// 		return index++;
// 	}
// }

// void Dijstra( int N, int s ) {
// 	fill( d.begin( ), d.end( ), INF );
// 	fill( w.begin( ), w.end( ), 0 );
// 	fill( pre.begin( ), pre.end( ), -1 );
// 	fill( cntOfPath.begin( ), cntOfPath.end( ), 0 );
// 	fill( cntOfCity.begin( ), cntOfCity.end( ), 0 );
// 	fill( visit.begin( ), visit.end( ), false );
// 	d[s] = 0; // 开始城市的初始化
// 	w[s] = 0;
// 	pre[s] = 0;
// 	cntOfPath[s] = 1;
// 	for( int i = 0, u = -1, min = INF; i < N; i++ ) { // 找每次能到的最近一个未访问过的城市
// 		u = -1, min = INF;
// 		for( int j = 0; j < N; j++ ) {
// 			if( visit[j] == false && d[j] < min ) {
// 				u = j;
// 				min = d[j];
// 			}
// 		}
// 		if( u == -1 )
// 			return;
// 		int size = G[u].size( );
// 		visit[u] = true; // 下面是核心代码
// 		for( int k = 0, v = 0; k < size; k++ ) {
// 			v = G[u][k].v;
// 			if( visit[v] == false && d[u] + G[u][k].dis < d[v] ) { // 以u为中介点使d[v]更短
// 				d[v] = d[u] + G[u][k].dis; // 更新d[v]和w[v]
// 				w[v] = w[u] + happiness[v];
// 				cntOfPath[v] = cntOfPath[u]; // 都在一条路径上，所以覆盖
// 				cntOfCity[v] = cntOfCity[u] + 1; // 把v算进去不就加1了
// 				pre[v] = u; // 保存路径
// 			}
// 			else if( visit[v] == false && d[u] + G[u][k].dis == d[v] ) { // 距离相同的不同路径比总点权
// 				cntOfPath[v] += cntOfPath[u]; // 不同的是距离相同的路径数是继承的
// 				if( w[u] + happiness[v] > w[v] ) { // 以u为中介点使w[v]更大
// 					w[v] = w[u] + happiness[v];
// 					cntOfCity[v] = cntOfCity[u] + 1;
// 					pre[v] = u;
// 				}
// 				else if( w[u] + happiness[v] == w[v] ) { // 总点权还一样就算平均点权
// 					double uAvg = 1.0 * ( w[u] + happiness[v] ) / ( cntOfCity[u] + 1 ); // 以u为中介点的
// 					double vAvg = 1.0 * w[v] / cntOfCity[v]; // 不算u的
// 					if( uAvg > vAvg ) {
// 						cntOfCity[v] = cntOfCity[u] + 1;
// 						pre[v] = u;
// 					}
// 				}
// 			}
// 		}
// 	}
// }

// void ShowPath( int v ) {
// 	if( v == 0 ) {
// 		cout << indexToName[v];
// 		return;
// 	}
// 	ShowPath( pre[v] );
// 	cout << "->" << indexToName[v];
// }

// int main( ) {
// 	int N, K, city1, city2;
// 	string start, name1, name2;
// 	cin >> N >> K >> start;
// 	G.resize( N );
// 	d.resize( N );
// 	w.resize( N );
// 	pre.resize( N );
// 	happiness.resize( N );
// 	cntOfPath.resize( N );
// 	cntOfCity.resize( N );
// 	visit.resize( N );
// 	nameToIndex[start] = 0;
// 	indexToName[0] = start;
// 	nameToIndex[string( "ROM" )] = N - 1;
// 	indexToName[N - 1] = string( "ROM" );
// 	for( int i = 1, num = 0; i < N; i++ ) {
// 		cin >> name1;
// 		num = GetIndex( name1, N );
// 		cin >> happiness[num];
// 	}
// 	for( int i = 0, tempDis = 0; i < K; i++ ) {
// 		cin >> name1 >> name2 >> tempDis;
// 		city1 = nameToIndex[name1], city2 = nameToIndex[name2];
// 		temp.v = city2, temp.dis = tempDis;
// 		G[city1].push_back( temp );
// 		temp.v = city1;
// 		G[city2].push_back( temp ); // 无向图双向处理
// 	}
// 	Dijstra( N, 0 );
// 	cout << cntOfPath[N - 1] << " " << d[N - 1] << " " << w[N - 1] << " ";
// 	printf( "%d\n", w[N - 1] / cntOfCity[N - 1] );
// 	ShowPath( N - 1 );
// 	return 0;
// }
