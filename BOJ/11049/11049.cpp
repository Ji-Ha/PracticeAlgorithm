#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const int MAX = 987654321;
int value[501][2];
int memo[501][501];

int solution(int start, int end){
    if(start == end) return 0;

    if(memo[start][end] != -1) return memo[start][end];
    int minimum = MAX;
    for(int i = start; i < end; i++){
        minimum = min(minimum, solution(start, i) + solution(i + 1, end) + value[start][0] * value[i][1] * value[end][1]);
    }
    memo[start][end] = minimum;
    return memo[start][end];
}

int main(){
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> value[i][0] >> value[i][1];
    
    solution(0, n - 1);
    cout << memo[0][n - 1] << '\n';
    return 0;
}