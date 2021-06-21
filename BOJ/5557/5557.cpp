#include <iostream>
#include <memory.h>
using namespace std;

int n;
int val[100];
long long dp[100][21]; // p에 도착했을 때, 이전 값들이 cal인 상태에서의 올바른 등식의 수.

long long dy(int p, int cal){
    if(p > n || cal < 0 || cal > 20) return 0;
    if(p == n - 1 && cal == val[p]) return 1;
    if(p == n - 1) return 0;
    

    long long &res = dp[p][cal];
    if(res != -1) return res;

    res = 0;
    res += dy(p + 1, cal - val[p]);
    res += dy(p + 1, cal + val[p]);
    return res;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> val[i];

    cout << dy(1, val[0]) << '\n';
    return 0;
}