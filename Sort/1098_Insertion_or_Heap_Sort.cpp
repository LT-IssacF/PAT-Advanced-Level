// #include <iostream>
// #define MAX 0xff
// using namespace std;
// int initial[MAX], target[MAX], ans[MAX];

// bool IsSame(int N) {
//     for (int i = 1; i <= N; i++)
//         if (ans[i] != target[i])
//             return false;
//     return true;
// }

// void Print(int N) {
//     cout << ans[1];
//     for (int i = 2; i <= N; i++)
//         cout << " " << ans[i];
// }

// bool InsertSort(int N) {
//     bool flag = false;
//     for (int i = 2; i <= N; i++) {
//         if (i > 2 && IsSame(N))
//             flag = true;
//         int j = i, temp = ans[i];
//         while (j >= 1 && temp < ans[j - 1]) {
//             ans[j] = ans[j - 1];
//             j--;
//         }
//         ans[j] = temp;
//         if (flag)
//             break;
//     }
//     return flag;
// }

// void AdjustMaxHeap(int low, int high) {
//     ans[0] = ans[low];
//     for (int i = low * 2; i <= high; i *= 2) {
//         if (i < high && ans[i + 1] > ans[i])
//             i++; // 有右孩子且右孩子比左孩子更大
//         if (ans[0] > ans[i]) // 根结点比孩子大
//             break;
//         else {
//             ans[low] = ans[i]; // 大元素往上走
//             low = i;
//         }
//     }
//     ans[low] = ans[0];
// }

// void HeapSort(int N) {
//     for (int i = 1; i <= N; i++)
//         ans[i] = initial[i];
//     for (int i = N / 2; i >= 1; i--) {
//         AdjustMaxHeap(i, N);
//     } // 先建好堆
//     bool flag = false;
//     for (int i = 0; i < N; i++) {
//         if (i > 0 && IsSame(N))
//             flag = true;
//         swap(ans[1], ans[N - i]);
//         AdjustMaxHeap(1, N - i - 1);
//         if (flag) {
//             cout << "Heap Sort" << endl;
//             Print(N);
//             return;
//         }
//     }
// }

// int main() {
//     int N;
//     cin >> N;
//     for (int i = 1; i <= N; i++) {
//         cin >> initial[i];
//         ans[i] = initial[i];
//     }
//     for (int i = 1; i <= N; i++)
//         cin >> target[i];
//     if (InsertSort(N)) {
//         cout << "Insertion Sort" << endl;
//         Print(N);
//     } else
//         HeapSort(N);
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int initial[120] = {0}, outcome[120] = {0};
bool IsSame(const int &N) {
    for (int i = 1; i <= N; i++)
        if (initial[i] != outcome[i])
            return false;
    return true;
}

void AdjustMAxHeap(int low, const int &high) {
    outcome[0] = outcome[low];
    for (int i = low * 2; i <= high; i *= 2) {
        if (i < high && outcome[i + 1] > outcome[i])
            i++;
        if (outcome[0] > outcome[i]) {
            break;
        } else {
            outcome[low] = outcome[i];
            low = i;
        }
    }
    outcome[low] = outcome[0];
}

bool HeapSort(const int &N) {
    for (int i = N / 2; i >= 1; i--) // 先建好堆
        AdjustMAxHeap(i, N);
    bool flag = false;
    for (int i = 0; i < N && !flag; i++) {
        flag = i > 0 && IsSame(N); // 相同了再多排一次就是结果
        swap(outcome[1], outcome[N - i]);
        AdjustMAxHeap(1, N - i - 1);
    }
    return flag;
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        scanf("%d", &initial[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &outcome[i]);
    bool insertion = false;
    for (int i = 2, j = 2, MIN = 0; i <= N && insertion == false; i++) {
        insertion = i > 2 && IsSame(N);
        for (j = i, MIN = initial[i]; j > 0 && initial[j - 1] > MIN; j--)
            initial[j] = initial[j - 1];
        initial[j] = MIN;
    }
    if (insertion == true) {
        printf("Insertion Sort\n%d", initial[1]);
        for (int i = 2; i <= N; i++)
            printf(" %d", initial[i]);
    } else {
        printf("Heap Sort\n");
        for (int i = 1; i <= N; i++)
            initial[i] = outcome[i];
        if (HeapSort(N)) {
            printf("%d", outcome[1]);
            for (int i = 2; i <= N; i++)
                printf(" %d", outcome[i]);
        }
    }
    return 0;
}