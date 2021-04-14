#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;
const int MAX = 8;
int map[MAX][MAX];
int copymap[MAX][MAX];
int n, m;
int answer = 0;
queue<pair<int, int>> virus;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void BFS(){
    queue <pair<int, int>> cpyvirus = virus;

    while(!cpyvirus.empty()){
        int y = cpyvirus.front().first;
        int x = cpyvirus.front().second;
        cpyvirus.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(copymap[ny][nx] == 0){
                copymap[ny][nx] = 2;
                cpyvirus.push(make_pair(ny, nx));
            }
        }
    }
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(copymap[i][j] == 0) count++;
        }
    }
    answer = max(answer, count);
}

void makewall(int cnt){
    if(cnt == 3){
       for(int i = 0; i < n; i++)
           for(int j = 0; j < m; j++)
               copymap[i][j] = map[i][j];
           
           BFS();
           return;
       
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                makewall(cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2)
                virus.push(make_pair(i, j));
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                makewall(1);
                map[i][j] = 0;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}