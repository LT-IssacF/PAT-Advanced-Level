#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    string text, ans;
    getline(cin, text);
    map<string, int> words;
    for (int i = 0; i < text.length(); i++) {
        string word;
        while (i < text.length() && ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= '0' && text[i] <= '9'))) {
            word += ((text[i] >= 'A' && text[i] <= 'Z') ? (text[i] + 32) : text[i]); // 大写字母转小写
            i++;
        } // 保存一个单词
        if (word.length() > 0) {
            if (words.find(word) != words.end()) { // 此单词出现过
                words[word]++;
            } else { // 第一次出现
                words[word] = 1;
            }
        }
    }
    int cnt = 0;
    for (const auto &i : words) // 找出现次数最多的单词
        if (i.second > cnt) {
            ans = i.first;
            cnt = i.second;
        }
    cout << ans << " " << cnt;
}