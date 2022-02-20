#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> d;
// 求第一个大于等于key的元素的位置
int Lower_Bound( const int &i, const int &j, const int &key ) {
    int left = i, right = j, mid;
    while( left < right ) { // 不需要判断key存在是否，就算不存在，也返回的是第一个大于key的位置
        mid = ( left + right ) / 2;
        if( d[mid] >= key ) { // 第一个大于等于key的元素在mid处及其左边
            right = mid;
        } else { // 一定在mid的右边
            left = mid + 1;
        }
    }
    return left;
}

int main( ) {
    int N, M, nearM = 0x3fffffff;
    cin >> N >> M;
    d.push_back( 0 ); // d[i]表示前i项之和
    for( int i = 1, s = 0; i <= N; i++ ) {
        scanf( "%d", &s );
        d.push_back( d[i - 1] + s );
    }
    for( int i = 1, j = 1, temp = 0; i <= N; i++ ) { // 确定nearM
        j = Lower_Bound( i, N, d[i - 1] + M ); // arr[i ~ j] = d[j] - d[i - 1]
        temp = d[j] - d[i - 1];
        if( temp == M ) { // 有序列的和等于M
            nearM = M;
            break;
        } else if( temp < nearM && temp >= M ) { // 最接近于M且大于其的值
            nearM = temp;
        }
    }
    for( int i = 1, j = 1; i <= N; i++ ) {
        j = Lower_Bound( i, N, d[i - 1] + nearM ); // d[j] = d[i - 1] + arr[i ~ j]
        if( d[j] - d[i - 1] == nearM )
            printf( "%d-%d\n", i, j );
    }
    return 0;
}
