#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string id, pwd;
    vector<string> ans;
    for (int i = 0; i < N; i++) {
        cin >> id >> pwd;
        bool flag = false;
        for (int j = 0; j < pwd.length(); j++) {
            switch (pwd[j]) {
            case '1':
                pwd[j] = '@';
                flag = true;
                break;
            case '0':
                pwd[j] = '%';
                flag = true;
                break;
            case 'l':
                pwd[j] = 'L';
                flag = true;
                break;
            case 'O':
                pwd[j] = 'o';
                flag = true;
            }
        }
        if (flag == true)
            ans.emplace_back(id), ans.emplace_back(pwd);
    }
    if (ans.size() == 0) {
        cout << "There " << (N == 1 ? "is " : "are ") << N << " account" << (N == 1 ? "" : "s") << " and no account is modified" << endl;
    } else {
        cout << ans.size() / 2 << endl;
        for (int i = 0; i < ans.size(); i += 2)
            cout << ans[i] << " " << ans[i + 1] << endl;
    }
    return 0;
}