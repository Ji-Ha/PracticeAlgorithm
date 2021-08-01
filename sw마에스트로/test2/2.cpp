#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int data[100001];
int countt[100001];
int repeat = 0;
int n;


//now에서 시작했을 때, 무한회로가 몇인지 출력해주는 친구.
void solution(int now){
    if(now < 0 || now > n) return ;
    if(countt[now] > 2){
        int res = 0;
        for(int i = 0; i < n; i++){
            if(countt[i] == 2) res += 1;
        }
        repeat = max(repeat, res);
    }
    else{
        countt[now] += 1;
        solution(now + data[now]);
    }
}

int main(){
    memset(data, 0, sizeof(data));

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> data[i];

    int result = 0;
    for(int i = 0; i < n; i++){
        memset(countt, 0, sizeof(countt));
        solution(i);
    }

    cout << repeat << '\n';
    return 0;
}