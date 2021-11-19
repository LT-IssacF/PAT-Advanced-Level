#include <iostream>
#include <vector>
#define MAX 0xff
using namespace std;
vector<vector<int>> tree;
int hashTable[MAX] = { 0 };
// hashTable存储每代人的人数
void DFS( int root, int level ) {
    int size = tree[root].size( );
    hashTable[level]++;
    for( int i = 0; i < size; i++ ) {
        DFS( tree[root][i], level + 1 );
    }
}

int main( ) {
    int N, M;
    cin >> N >> M;
    tree.resize( N + 1 );
    for( int i = 0, father = 0, children = 0, K = 0; i < M; i++ ) {
        cin >> father >> K;
        for( int j = 0; j < K; j++ ) {
            cin >> children;
            tree[father].push_back( children );
        }
    }
    DFS( 1, 1 );
    int largestPopulation = 1, level = 1;
    for( int i = 1; i <= N; i++ ) {
        if( hashTable[i] > largestPopulation ) {
            largestPopulation = hashTable[i];
            level = i;
        }
    }
    cout << largestPopulation << " " << level;
    return 0;
}