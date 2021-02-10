#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int erection[1001];
int connected[1001][1001];
int dp[1001];
int n, k;
int w;

int solution(int now){
    int maximum = 0;

    if(dp[now] != -1) return erection[now];

    for(int i = 1; i <= n; i++){
        if(connected[i][now] == 1){
            if(dp[i] == -1) solution(i);
            
            if(dp[i] > maximum) maximum = dp[i];
        }
    }

    dp[now] = maximum + erection[now];

    return dp[now];
}

int main(){
    int t;
    cin >> t;

    while(t--){
        memset(connected, 0, sizeof(connected));
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;

        for(int i = 1; i <= n; i++)
            cin >> erection[i];

        for(int i = 1; i <= k; i++){
            int start, end;
            cin >> start >> end;
            connected[start][end] = 1;
        }

        cin >> w;
        solution(w);
        cout << dp[w] << '\n';
    }
    return 0;
}