#include <iostream>
#include <queue>
using namespace std;

char wall[1001][1001];
int visit[1001][1001][2];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
queue <pair<pair<int, int>, int> > q;

int main(){
    int ans = -1;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> wall[i];

    q.push(make_pair(make_pair(0, 0), 1));
    visit[0][0][1] = 1;
    
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int b = q.front().second;
        q.pop();
        if(y == n - 1 && x == m - 1){
            ans = visit[y][x][b];
            break;
        } 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 0 && nx >= 0 && ny < n && nx < m){
                if(visit[ny][nx][b] == 0 && wall[ny][nx] == '0'){
                    q.push(make_pair(make_pair(ny, nx), b));
                    visit[ny][nx][b] = visit[y][x][b] + 1;
                } 
                if(wall[ny][nx] == '1' && b == 1){
                    q.push(make_pair(make_pair(ny, nx), b - 1));
                    visit[ny][nx][b - 1] = visit[y][x][b] + 1;
                }
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}