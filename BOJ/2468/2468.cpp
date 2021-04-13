#include <iostream>
#include <memory.h>

using namespace std;
int value[101][101];
bool check[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

bool dfs(int y, int x, int limit){
    if(value[y][x] <= limit) return false;
    if(check[y][x] != false) return false;
    check[y][x] = true;

    for(int i = 0; i < 4; i++){
        if(x + dx[i] >= 0 && y + dy[i] >= 0)
            dfs(y + dy[i], x+dx[i], limit);
    }
        
    
    return true;
}

int main(){
    int maxvalue = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> value[i][j];
            maxvalue = max(maxvalue, value[i][j]);
        }
    }

    int count = 0;
    for(int k = 0; k <= maxvalue; k++){
        int tempcount = 0;
        memset(check, false, sizeof(check));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i, j, k)) tempcount++;
            }
        }
        count = max(count, tempcount);
    }
    cout << count;

    return 0;
}