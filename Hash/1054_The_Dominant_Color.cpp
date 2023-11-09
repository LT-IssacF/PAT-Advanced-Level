#include <iostream>
#include <map>
using namespace std;

int main() {
    int N, M, min = 0, ans;
    cin >> N >> M;
    map<int, int> m;
    for (int i = 0, color = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &color);
            m[color]++;
        }
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->second > min) {
            ans = it->first;
            min = it->second;
        }
    }
    cout << ans;
    return 0;
}