#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 501;
int n;
int value[501][501];
int memo[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int solution(int y, int x){
    int& place = memo[y][x];
    if(place != 0) return place;

    place = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < n){
            if(value[y][x] < value[ny][nx]) place = max(place, solution(ny, nx) + 1);
        }
    }
    return place;
}

int main(){
    memset(value, 0, sizeof(value));
    memset(memo, 0, sizeof(memo));
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> value[i][j];
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res = max(res, solution(i, j));
        }
    }
    cout << res << '\n';
    return 0;
}