#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int pay[16][16];
int cache[16][(1 << 17) + 1][10];

int solution(int now, int visit, int price){
    int& res = cache[now][visit][price];

    if(res != 0) return res;

    if(visit == (1 << n) - 1) return res = 1;

    res = 1;

    for(int i = 0; i < n; i++){
        if(visit & (1 << i)) continue;
        if(i == now) continue;

        if(pay[now][i] >= price) res = max(res, solution(i, (visit | 1 << i), pay[now][i]) + 1);
    }

    return res;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
            pay[i][j] = s[j] - '0';
    }

    cout <<solution(0, 1, 0) << '\n';
    return 0;
}