#include <iostream>
#include <set>
using namespace std;

int main() {
    int M, N, S;
    cin >> M >> N >> S;
    bool print = false;
    if (M >= S) {
        M -= S - 1;
        string name;
        set<string> winners;
        for (int i = 1; i < S; i++)
            cin >> name;
        for (int i = 0, j = 0; i < M; i++, j++) {
            cin >> name;
            if (j % N == 0) {
                if (winners.find(name) == winners.end()) {
                    winners.insert(name);
                    cout << name << endl;
                    print = true;
                } else {
                    j--;
                }
            }
        }
    }
    if (print == false)
        cout << "Keep going...";
    return 0;
}