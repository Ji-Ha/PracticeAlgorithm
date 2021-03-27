#include <iostream>
#include <memory.h>
using namespace std;
int value[2001];
int memo[2001][2001];

int solution(int start, int end){
    int& res = memo[start][end];
    if(start >= end) return 1;

    if(res != -1) return res;

    res = 0;

    if(value[start] != value[end]) return res;
    else{
        return res = solution(start + 1, end - 1);
    }
}

int main(){
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));

    for(int i = 1; i <= n; i++) cin >> value[i];

    int m;
    cin >> m;

    while(m--){
        int s, e;
        cin >> s >> e;
        cout << solution(s, e) << "\n";
    }
    return 0;
}