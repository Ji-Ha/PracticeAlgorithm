#include <iostream>
#include <memory.h>
using namespace std;
int value[100][100];
int cache[100][100];
int n;

int solution(int y, int x){
    if(y >= n || x >= n) return 0;
    if(y == n - 1 && x == n - 1) return 1;

    int& res = cache[y][x];

    if(res != -1) return res;
    int jumpsize = value[y][x];

    return res = solution(y + jumpsize, x) || solution(y, x + jumpsize);
}

int main(){
    int c;
    cin >> c;

    while(c--){
        memset(cache, -1, sizeof(cache));
        bool check = false;
        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cin >> value[i][j];
        }

        if(solution(0, 0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}