#include <iostream>
using namespace std;
int n;
int value[2001];
int memo[2001][2001];

void init(){
    for(int i = 1; i <= n; i++) memo[i][i] = 1;
    for(int i = 1; i < n ; i++) if(value[i] == value[i + 1]) memo[i][i + 1] = 1;
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= n - j + 1; j++){
            int k = i + j - 1;
            if(value[k] == value[j] && memo[j + 1][k - 1]) memo[j][k] = 1;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> value[i];

    int m;
    cin >> m;

    for(int i = 1; i <= n; i++) memo[i][i] = 1;
    for(int i = 1; i < n ; i++){
        if(value[i] == value[i + 1]) memo[i][i + 1] = 1;
    } 
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            int k = i + j - 1;
            if(value[j] == value[k] && memo[j + 1][k - 1]) memo[j][k] = 1;
        }
    }

    while(m--){
        int s, e;
        cin >> s >> e;
        cout << memo[s][e] << "\n";
    }
    return 0;
}