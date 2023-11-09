#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, ans, words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
        sum += (s[i] - '0');
    ans = to_string(sum);
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0)
            printf(" ");
        cout << words[ans[i] - '0'];
    }
    return 0;
}