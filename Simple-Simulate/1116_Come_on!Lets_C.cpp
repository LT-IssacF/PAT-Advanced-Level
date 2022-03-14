#include <iostream>
#include <map>
using namespace std;
bool IsPrime( const int &key ) {
    for( int i = 2; i * i <= key; i++ )
        if( key % i == 0 )
            return false;
    return true;
}

int main( ) {
    int N, K;
    cin >> N;
    map<int, string> awards = { { 0, "Mystery Award" }, { 1, "Minion" }, { 2, "Chocolate" } };
    map<string, int> stu;
    string id, checked = "Checked", none = "Are you kidding?";
    cin >> id;
    stu[id] = 0;
    for( int i = 2; i <= N; i++ ) {
        cin >> id;
        stu[id] = ( IsPrime( i ) ? 1 : 2 );
    }
    cin >> K;
    map<string, bool> visit;
    for( int i = 0; i < K; i++ ) {
        cin >> id;
        if( stu.find( id ) != stu.end( ) ) {
            if( visit[id] == false ) {
                cout << id << ": " << awards[stu[id]] << endl;
                visit[id] = true;
            }
            else {
                cout << id << ": " << checked << endl;
            }
        } else {
            cout << id << ": " << none << endl;
        }
    }
    return 0;
}
