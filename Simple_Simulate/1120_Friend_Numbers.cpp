#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> ids;
    string num;
    for (int i = 0, sum = 0; i < N; i++, sum = 0) {
        cin >> num;
        for (const char &c : num)
            sum += c - '0';
        ids.insert(sum);
    }
    cout << ids.size() << endl;
    for (auto it = ids.begin(); it != ids.end(); it++)
        if (it == ids.begin()) {
            cout << *it;
        } else {
            cout << " " << *it;
        }
    return 0;
}