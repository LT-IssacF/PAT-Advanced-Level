#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
char alphabet[26][7][5];

int main() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 5; k++) {
                scanf("%c", &alphabet[i][j][k]);
            }
            char c = getchar();
        }
    }
    string sentence;
    vector<string> words;
    getline(cin, sentence);
    for (int i = 0, j = 0; i < sentence.length(); i = j + 1) {
        for (j = i; j < sentence.length() && (sentence[j] >= 65 && sentence[j] <= 90); j++)
            ;
        if (i != j) // 开头第一个字符可能是分隔符，非要搞这种正常人想不到的点来恶心人
            words.emplace_back(sentence.substr(i, j - i));
    }
    for (int i = 0; i < words.size(); i++) { // 输出每个单词
        if (i > 0)
            printf("\n\n");
        for (int j = 0; j < 7; j++) { // 每个单词输7行
            if (j > 0)
                printf("\n");
            for (int k = 0; k < words[i].length(); k++) { // 输出每个字母
                if (k > 0)
                    printf(" ");
                for (int m = 0; m < 5; m++) {
                    printf("%c", alphabet[words[i][k] - 65][j][m]);
                }
            }
        }
    }
    return 0;
}