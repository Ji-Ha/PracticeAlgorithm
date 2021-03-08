#include <iostream>
#include <memory.h>
using namespace std;
int n;
int dp[1001], data[1000];

int solution(int start){
    int &result = dp[start + 1];

    if(result != -1) return result;

    result = 0;

    for(int next = start + 1; next < n; next++){
        if(start == -1 || data[start] < data[next]){
            int value = solution(next) + 1;
            if(value > result) result = value;
        }
    }
    return result;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> data[i];
    memset(dp, -1, sizeof(dp));

    cout << solution(-1) << '\n';
    return 0;
}