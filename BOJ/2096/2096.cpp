#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int n;
int value[100000][3];
int memoMax[100000][3];
int memoMin[100000][3];

int solutionMax(int y, int x){
    //끝에 도착하면 돌아가야지.
    if(y == n - 1) return value[y][x];

    int& ans = memoMax[y][x];

    if(ans != -1) return ans;

    ans = value[y][x];

    if(x == 0) ans += max(solutionMax(y + 1, x), solutionMax(y + 1, x + 1));
    if(x == 1) ans += max(solutionMax(y + 1, x - 1), max(solutionMax(y + 1, x), solutionMax(y + 1, x + 1)));
    if(x == 2) ans += max(solutionMax(y + 1, x - 1), solutionMax(y + 1, x));

    return ans;
}

int solutionMin(int y, int x){
    if(y == n - 1) return value[y][x];

    int& ans = memoMin[y][x];

    if(ans != -1) return ans;

    ans = value[y][x];

    if(x == 0) ans += min(solutionMin(y + 1, x), solutionMin(y + 1, x + 1));
    if(x == 1) ans += min(solutionMin(y + 1, x - 1), min(solutionMin(y + 1, x), solutionMin(y + 1, x + 1)));
    if(x == 2) ans += min(solutionMin(y + 1, x - 1), solutionMin(y + 1, x));

    return ans;
}

int main(){
    memset(memoMax, -1, sizeof(memoMax));
    memset(memoMin, -1, sizeof(memoMin));
    cin >> n;
    int maxValue = 0;
    int minValue = 1000000;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cin >> value[i][j];
    }
    
    for(int i = 0; i < 3; i++){
        maxValue = max(maxValue, solutionMax(0, i));
        minValue = min(minValue, solutionMin(0, i));
    }

    cout << maxValue << ' ' << minValue << '\n';
    return 0;
}