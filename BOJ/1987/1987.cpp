#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

char value[21][21];
int check[26]; // 대문자 A의 아스키 코드 65
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int r, c;
int answer = 0;

void dfs(int y, int x, int count){
    int target = value[y][x] - 65;
    if(y < 0 || x < 0 || y >= r || x >= c) return ;
    if(check[target] != 0) return ;

    answer = max(answer, count);
    for(int i = 0; i < 4; i++){
        check[target] += 1;
        dfs(y + dy[i], x + dx[i], count + 1);
        check[target] -= 1;
    }

    return ;
}

int main(){
    memset(check, 0, sizeof(check));
    cin >> r >> c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cin >> value[i][j];
    }

    dfs(0, 0, 1);

    cout << answer << '\n';
    return 0;
}