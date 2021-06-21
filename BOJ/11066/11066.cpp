#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int value[501];
int summary[501];
int memo[501][501]; // i부터 j까지의 최소 합

int main(){
    int t;
    cin >> t;

    while(t--){
        int k;
        cin >> k;
        
        for(int i = 1; i <= k; i++){
            cin >> value[i];
            summary[i] = summary[i - 1] + value[i];
        }

        for(int i = 1; i <= k; i++){
            for(int tx = 1; tx + i <= k; tx++){
                int ty = tx + i;
                memo[tx][ty] = INT_MAX;

                for(int mid = tx; mid < ty; mid++)
                    memo[tx][ty] = min(memo[tx][ty], memo[tx][mid] + memo[mid + 1][ty] + summary[ty] - summary[tx - 1]);
            }
        }
        cout << memo[1][k] << '\n';
    }
    return 0;
}
