#include <iostream>
#include <string>
using namespace std;

int main() {
    string origin, outcome, ans;
    cin >> origin >> outcome;
    // for (char &i : origin)
    //     if (i >= 'a' && i <= 'z')
    //         i -= 32;
    // for (char &i : outcome)
    //     if (i >= 'a' && i <= 'z')
    //         i -= 32;
    // unordered_set<char> ans;
    // for (int i = 0, j = 0; i < origin.length() && j < outcome.length(); i++)
    //     if (origin[i] != outcome[j]) {
    //         ans.insert(origin[i]);
    //     } else {
    //         j++;
    //     }
    // for (const char &i : ans) // vs的编译就没问题，但是g++的输出顺序就有问题
    //     printf("%c", i);
    for (const char &i : origin) // 枚举origin每个字母
        if (outcome.find(i) == string::npos && ans.find(toupper(i)) == string::npos)
            ans += toupper(i); // outcome中找不到且大写字母在ans里也找不到
    cout << ans;
    return 0;
}