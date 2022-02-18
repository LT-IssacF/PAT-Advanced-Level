#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#define MAX 2020
using namespace std;
int G[MAX][MAX] = { 0 }, time2[MAX] = { 0 }, cnt = 0;
vector<bool> visit;
unordered_map<string, int> stringToInt;
unordered_map<int, string> intToString;
map<string, int> gang;
int GetInt( const string &name ) {
    if( stringToInt.find( name ) != stringToInt.end( ) ) // name已经出现过
        return stringToInt[name];
    stringToInt[name] = cnt;
    intToString[cnt] = name;
    return cnt++;
}

void DFS( const int &now, int &head, int &num, int &totalTime ) {
    if( time2[now] > time2[head] )
        head = now;
    visit[now] = true;
    num++;
    for( int i = 0; i < cnt; i++ ) {
        if( G[now][i] > 0 ) {
            totalTime += G[now][i];
            G[now][i] = G[i][now] = 0; // 消除回路
            if( visit[i] == false )
                DFS( i, head, num, totalTime );
        }
    }
}

void DFS_Travels( const int &K ) {
    fill( visit.begin( ), visit.end( ), false );
    for( int i = 0, head = 0, num = 0, totalTime = 0; i < cnt; i++ ) {
        if( visit[i] == false ) { // 每次执行访问一个极大连通子图
            head = i, num = 0, totalTime = 0; // 重置参数
            DFS( i, head, num, totalTime );
            if( totalTime > K && num > 2 ) // 如果当前子图结点个数大于2且总权重大于阈值那么就符合要求
                gang[intToString[head]] = num; // 建立映射
        }
    }
}

int main( ) {
    int N, K;
    cin >> N >> K;
    string name, name2;
    for( int i = 0, num = 0, num2 = 0, t = 0; i < N; i++ ) {
        cin >> name >> name2 >> t;
        num = GetInt( name ), num2 = GetInt( name2 );
        G[num][num2] += t, G[num2][num] += t;
        time2[num] += t, time2[num2] += t;
    }
    visit.resize( cnt );
    DFS_Travels( K );
    cout << gang.size( ) << endl;
    for( map<string, int>::iterator it = gang.begin( ); it != gang.end( ); it++ )
        cout << it->first << " " << it->second << endl;
    return 0;
}
