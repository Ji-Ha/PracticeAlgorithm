#include <iostream>
#include <memory.h>
using namespace std;
//반갈 해서 왼쪽과 오른쪽의 총합과 최댓값 찾아서 선택하고 더하기.
int data[1024];

int solution(int start, int end){
    
}

int main(){
    memset(data, 0, sizeof(int));
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> data[i];
    
    solution(0, n/2);
    solution(n/2, n - 1);
    return 0;
}