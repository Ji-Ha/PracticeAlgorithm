#include <iostream>
#include <string>
using namespace std;

string a, b;
string dp[1001][1001];

int main(){
    cin >> a;
    cin >> b;

    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++){
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
            else{
                if(dp[i - 1][j].length() >= dp[i][j - 1].length())
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << dp[a.length()][b.length()].length() << '\n' << dp[a.length()][b.length()];

    return 0;
}