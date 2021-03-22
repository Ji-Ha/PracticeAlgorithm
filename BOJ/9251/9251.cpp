#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string first;
string second;
int dp[1001][1001];

int main(){
    cin >> first;
    cin >> second;

    for(int i = 0; i < first.length(); i++){
        for(int j = 0; j < second.length(); j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            if(first[i] == second[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[first.length() - 1][second.length() - 1] << '\n';
    return 0;
}