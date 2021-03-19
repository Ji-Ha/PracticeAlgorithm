#include <iostream>
#include <memory.h>
using namespace std;
int m, n;
int value[500][500];
int dp[500][500];

int solution(int y, int x){
    // 기저사례 1.
    if(y >= m || x >= n || y < 0 || x < 0) return 0;

    int& num = dp[y][x];
    if(num != -1) return num;

    // 기저사례 2. 마지막에 도착했을 때 1을 돌려준다.
    if(y == m - 1 && x == n - 1) return 1;

    num = 0;

    if(value[y + 1][x] < value[y][x]) num = num + solution(y + 1, x);
    if(value[y - 1][x] < value[y][x]) num = num + solution(y - 1, x);
    if(value[y][x - 1] < value[y][x]) num = num + solution(y, x - 1);
    if(value[y][x + 1] < value[y][x]) num = num + solution(y, x + 1);
    
    return num;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> m >> n;
    int answer = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> value[i][j];
        } 
    }

    answer = solution(0, 0);

    cout << answer << '\n';
    return 0;
}