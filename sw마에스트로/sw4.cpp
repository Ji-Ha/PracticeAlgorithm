#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int block[100];
int check[100];
int write;

void checker(int now, int count){
    if(check[now] != 0)
        write = count;

    if(check[now] == 0) {
        check[now] = 1;
        checker(now + block[now], count + 1);
    }
}

int main(){
    int N;
    int answer = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> block[i];

    for(int i = 0; i < 3; i++){
        memset(check, 0, sizeof(int));
        write = 0;
        checker(i, 1);
        answer = max(answer, write);
    }
    cout << answer << '\n';
    return 0;
}