#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int data[32][32];

//지정된 위치 중 가장 큰 수.
int biggest(int a, int b, int c, int d){
    int bigOne = 0;
    for(int i = a; i < c; i++){
        for(int j = a; j < b; j++){
            bigOne = max(bigOne, data[i][j]);
        }
    }
    return bigOne;
}

int solution(int a, int b, int c, int d){
    // 기저사례.
    if(b - a <= 1 || c - a <= 1) return 0;
    // 작업방식 왼쪽
    int selectLeft = biggest(a, b/2, c, d/2) + solution(b/2, b, c/2, d);
    int selectRight = solution(a, b/2, c, d/2) + biggest(b/2, b, c/2, d);
    int selectUp = biggest(a, b, c/2, d/2) + solution(c/2, b, d/2, d);
    int selectDown = solution(a, b, c/2, d/2) + biggest(c/2, b, d/2, d);

    int res = 0;
    int temp = 0;
    res = max(selectLeft, selectRight);
    temp = max(selectUp, selectDown);

    return max(res, temp);
}

int main(){
    memset(data, 0, sizeof(data));

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> data[i][j];
    }

    cout << solution(0, 0, n, n) << '\n';

    return 0;
}