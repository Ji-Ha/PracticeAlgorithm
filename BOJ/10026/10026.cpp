#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
const int MAX = 100;
int n;
char board[MAX][MAX];
bool check[MAX][MAX];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int normalBFS(int y, int x){
    if(check[y][x]) return 0;
    char target = board[y][x];
    queue <pair<int, int>> q;
    q.push(make_pair(y, x));
    check[y][x] = true;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(board[ny][nx] == target && !check[ny][nx]){
                check[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
    return 1;
}

int weaknessBFS(int y, int x){
    if(check[y][x]) return 0;
    char target = board[y][x];
    queue <pair<int, int>> q;
    q.push(make_pair(y, x));
    check[y][x] = true;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(target == 'R' || target == 'G'){
                if((board[ny][nx] == 'R' || board[ny][nx] == 'G') && !check[ny][nx]){
                    check[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
            else{
                if(board[ny][nx] == target && !check[ny][nx]){
                   check[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    return 1;
}

int main(){
    vector<char> answer;
    cin >> n;
    memset(check, false, sizeof(check));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    int normal_count = 0;
    int weakness_count = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            normal_count += normalBFS(i, j);
    
    memset(check, false, sizeof(check));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            weakness_count += weaknessBFS(i, j);

    cout << normal_count << ' ' << weakness_count << '\n';
    return 0;
}