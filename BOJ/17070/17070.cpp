#include <iostream>
using namespace std;
int board[17][17];
int n;
int ans = 0;

bool checkCross(pair<int, int> now){
    if(board[now.first][now.second + 1] == 1 || board[now.first + 1][now.second] == 1 || board[now.first + 1][now.second + 1] == 1)
        return false;
    return true;
}

void move(pair<int, int> h, pair<int, int> t){
    if(t.first < 1 || t.second < 1 || t.first > n || t.second > n || board[t.first][t.second] == 1)
        return ;

    if(t.first == n && t.second == n){
        ans++;
        return ;
    }

    int dx = abs(t.second - h.second);
    int dy = abs(t.first - h.first);
    int stat;
    if(dy == 1 && dx == 1) stat = 1; // 대각선
    else if(dy == 1) stat = 0; // 세로
    else if(dx == 1) stat = -1; // 가로
    
    if(stat == 1){
        move(t, {t.first, t.second + 1});
        move(t, {t.first + 1, t.second});
        if(checkCross(t)) move(t, {t.first + 1, t.second + 1});
    }
    if(stat == 0){
        move(t, {t.first + 1, t.second});
        if(checkCross(t)) move(t, {t.first + 1, t.second + 1});
    }
    if(stat == -1){
        move(t, {t.first, t.second + 1});
        if(checkCross(t)) move(t, {t.first + 1, t.second + 1});
    }
}

int main(){
    pair<int, int> head = {1, 1};
    pair<int, int> tail = {1, 2};

    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];

    move(head, tail);

    cout << ans << '\n';
    return 0;
}