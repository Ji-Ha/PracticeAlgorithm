#include <iostream>
using namespace std;
int check[15];
int n, res = 0;

bool checker(int p){
    for(int i = 0; i < p; i++)
        if(check[i] == check[p] || abs(check[p] - check[i]) == p - i) //check[i] == check[p]는 직선에 있는 것들이 겹치는지 판단, 
        //check[p] - check[i] == p - i 는 대각선 판단.
            return false;
    return true;
}

void nQueen(int i){
    if(i == n) res++;
    else{
        for(int j = 0; j < n; j++){
            check[i] = j;
            if(checker(i)) nQueen(i + 1);
        }
    }
}

int main(){
    
    cin >> n;

    nQueen(0);
    cout << res << '\n';
    
    return 0;
}