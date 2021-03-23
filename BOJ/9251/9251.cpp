#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
char first[1001], second[1001];
int dp[1001][1001];

int main(){
    memset(dp, 0, sizeof(dp));
    cin >> first;
    cin >> second;
    int firstSize = strlen(first);
    int secondSize = strlen(second);

    for(int i = 1; i <= firstSize; i++){
        for(int j = 1; j <= secondSize; j++){
            if(first[i - 1] == second[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[firstSize][secondSize] << '\n';
    return 0;
}