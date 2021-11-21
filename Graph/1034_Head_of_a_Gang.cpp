#include <iostream>
#include <cstring>
#include <map>
#define MAX 2020
using namespace std;
map<string, int> stringToInt;
map<int, string> intToSting;
map<string, int> gang;
int G[MAX][MAX] = { 0 }, weight[MAX] = { 0 }; // 得用邻接矩阵，邻接表不方便
bool visit[MAX] = { 0 };
int cnt = 0;

int GetInt( string name ) {
    if( stringToInt.find( name ) != stringToInt.end( ) ) // name已经出现过
        return stringToInt[name];
    else { // 建立映射
        stringToInt[name] = cnt;
        intToSting[cnt] = name;
        return cnt++;
    }
}
// 注意后三个参数是引用
void DFS( int now, int &head, int &conGraphCnt, int &conGraphValue ) {
    conGraphCnt++;
    visit[now] = true;
    if( weight[head] < weight[now] ) // 谁才是大哥
        head = now;
    for( int i = 0; i < cnt; i++ ) {
        if( G[now][i] > 0 ) { // 有边
            conGraphValue += G[now][i];
            G[now][i] = G[i][now] = 0; // 消除回路
            if( visit[i] == false )
                DFS( i, head, conGraphCnt, conGraphValue );
        }
    }
}

void DFS_Travels( int K ) {
    for( int i = 0, head = 0, conGraphCnt = 0, conGraphValue = 0; i < cnt; i++ ) {
        if( visit[i] == false ) { // 每次执行访问一个极大连通子图
            head = i, conGraphCnt = 0, conGraphValue = 0; // 重置参数
            DFS( i, head, conGraphCnt, conGraphValue );
            if( conGraphCnt > 2 && conGraphValue > K ) // 如果当前子图结点个数大于2且总权重大于门槛值那么就符合要求
                gang[intToSting[head]] = conGraphCnt; // 建立映射
        }
    }
}

int main( ) {
    int N, K;
    cin >> N >> K;
    string name1, name2;
    for( int i = 0, num1 = 0, num2 = 0, tempWeight = 0; i < N; i++ ) {
        cin >> name1 >> name2 >> tempWeight;
        num1 = GetInt( name1 );
        num2 = GetInt( name2 );
        G[num1][num2] += tempWeight;
        G[num2][num1] += tempWeight;
        weight[num1] += tempWeight;
        weight[num2] += tempWeight;
    } // 无向图，用邻接矩阵累计权重很方便
    DFS_Travels( K );
    int size = gang.size( );
    cout << size;
    if( size > 0 ) {
        for( map<string, int>::iterator it = gang.begin( ); it != gang.end( ); it++ )
            cout << '\n' << it->first << " " << it->second;
    }
    return 0;
}