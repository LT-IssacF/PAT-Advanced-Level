#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int exponent;
    double coefficient;
};

int main() {
    int K, MAX;
    cin >> K;
    vector<node> arr;
    double coefficient, ans[2020] = {0};
    for (int i = 0, exponent = 0; i < K; i++) {
        scanf(" %d %lf", &exponent, &coefficient);
        arr.emplace_back(node{exponent, coefficient});
    }
    cin >> K;
    for (int i = 0, exponent = 0; i < K; i++) {
        scanf(" %d %lf", &exponent, &coefficient);
        for (int j = 0; j < arr.size(); j++) {
            ans[exponent + arr[j].exponent] += coefficient * arr[j].coefficient;
            if (i == 0 && j == 0)
                MAX = exponent + arr[j].exponent;
        }
    }
    arr.clear();
    for (int i = MAX; i >= 0; i--)
        if (ans[i] != 0)
            arr.emplace_back(node{i, ans[i]});
    cout << arr.size();
    for (int i = 0; i < arr.size(); i++)
        printf(" %d %.1lf", arr[i].exponent, arr[i].coefficient);
    return 0;
}