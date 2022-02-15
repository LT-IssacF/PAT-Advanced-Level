#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 0x7fffffff
using namespace std;
struct station {
    double price, distance;
} temp;

bool cmp( const station &a, const station &b ) {
    return a.distance < b.distance;
}

int main( ) {
    double capacity, distance, avg;
    int N;
    cin >> capacity >> distance >> avg >> N;
    vector<station> gas;
    for( int i = 0; i < N; i++ ) {
        cin >> temp.price >> temp.distance;
        gas.push_back( temp );
    }
    temp.price = 0, temp.distance = distance;
    gas.push_back( temp ); // 将最后一个站点设为价格为0的终点
    sort( gas.begin( ), gas.end( ), cmp ); // 对各站点依距离由小到大排序
    if( gas[0].distance != 0 ) // 特判
        cout << "The maximum travel distance = 0.00";
    else {
        double tank_remain = 0, cost = 0, tank_can_run = capacity * avg;
        int now = 0; // 标记此时所在的站点
        while( now < N ) {
            int key = -1;
            double min_price = MAX;
            for( int i = now + 1; i <= N && gas[i].distance - gas[now].distance <= tank_can_run; i++ ) {
                if( gas[i].price < min_price ) { // 更新最小价格
                    min_price = gas[i].price;
                    key = i; // 标记要去的下个站点
                }
                if( min_price < gas[now].price ) // 最小价格比当前所在站点的价格还便宜就不用继续比了
                    break;
            }
            if( key == -1 )
                break; // 太远了
            double need = ( gas[key].distance - gas[now].distance ) / avg; // 前往下个站点需要的油量
            if( min_price <= gas[now].price ) { // 下个站点油更便宜，所以只加到足够前往下个站点的油量即可
                if( tank_remain < need ) { // 所剩油量不够
                    cost += gas[now].price * ( need - tank_remain );
                    tank_remain = 0; // 到下个站点油量为0
                }
                else // 油量还够
                    tank_remain -= need;
            }
            else { // 下个站点的价格比当前所在站点的价格高，所以在当前站点加满
                cost += ( capacity - tank_remain ) * gas[now].price;
                tank_remain = capacity - need;
            }
            now = key; // 到了下个站点
        }
        if( now == N )
            printf( "%.2lf", cost );
        else
            printf( "The maximum travel distance = %.2lf", gas[now].distance + tank_can_run );
    }
    return 0;
}
