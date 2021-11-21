#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int v, level;
};
vector<vector<node>> G;
vector<bool> visitQueue;

int BFS( int L, int user ) { // 每次BFS不改变原图数据，user为起始结点
    queue<node> q;
    int numOfShare = 0; // 转发过的人
    node start;
    start.v = user, start.level = 0;
    q.push( start );
    visitQueue[start.v] = true;
    while( !q.empty( ) ) {
        start = q.front( );
        if( start.level >= L ) // 易错点（最大转发次数）
            break;
        q.pop( );
        int size = G[start.v].size( );
        for( int i = 0; i < size; i++ ) {
            node fan = G[start.v][i];
            fan.level = start.level + 1;
            if( visitQueue[fan.v] == false ) { // 易错点
                q.push( fan );
                visitQueue[fan.v] = true;
                numOfShare++;
            }
        }
    }
    return numOfShare;
}

int main( ) {
    int N, L, K;
    cin >> N >> L;
    G.resize( N + 1 );
    visitQueue.resize( N + 1 );
    node temp;
    for( int i = 1, j = 0, cnt = 0, followedV = 0; i < N + 1; i++ ) {
        cin >> cnt;
        temp.v = i;
        for( j = 0; j < cnt; j++ ) {
            cin >> followedV;
            G[followedV].push_back( temp );
        }
    }
    vector<int> outcome;
    cin >> K;
    for( int i = 0, j = 0; i < K; i++ ) {
        cin >> j;
        fill( visitQueue.begin( ), visitQueue.end( ), false );
        int numOfShare = BFS( L, j );
        outcome.push_back( numOfShare );
    }
    int size = outcome.size( );
    for( int i = 0; i < size; i++ )
        cout << outcome[i] << endl;
    return 0;
}