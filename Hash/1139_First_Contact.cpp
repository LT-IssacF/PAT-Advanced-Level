#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct node {
    int a, b;
};
unordered_map<int, vector<int>> sameSexFriends;
unordered_map<int, bool> friends;

int main() {
    int N, M, K;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        string tempA, tempB; // 有+0和-0，所以得用string
        cin >> tempA >> tempB;
        int a = abs(stoi(tempA)), b = abs(stoi(tempB));
        if (tempA.length() == tempB.length()) { // 同性好友字符串长度相等
            sameSexFriends[a].push_back(b);
            sameSexFriends[b].push_back(a);
        }
        friends[a * 10000 + b] = friends[b * 10000 + a] = true;
    }
    cin >> K;
    for (int i = 0, a = 0, b = 0; i < K; i++) {
        scanf("%d %d", &a, &b);
        a = abs(a), b = abs(b);
        vector<node> ans;
        for (int m = 0; m < sameSexFriends[a].size(); m++) {
            for (int n = 0; n < sameSexFriends[b].size(); n++) {
                if (sameSexFriends[a][m] == b || sameSexFriends[b][n] == a)
                    continue; // 同性恋的情况下二人就算是朋友也要通过另外俩朋友
                if (friends[sameSexFriends[a][m] * 10000 + sameSexFriends[b][n]] == true)
                    ans.push_back(node{sameSexFriends[a][m], sameSexFriends[b][n]});
            } // a的一个朋友与b的一个朋友是朋友
        }
        sort(ans.begin(), ans.end(), [](const node &a, const node &b) {
            if (a.a != b.a) {
                return a.a < b.a;
            } else {
                return a.b < b.b;
            }
        });
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            printf("%04d %04d\n", ans[i].a, ans[i].b);
    }
    return 0;
}