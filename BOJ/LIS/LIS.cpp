#include <iostream>
#include <algorithm>
using namespace std;
int data[1000001];
int lis[1000001];
int trace[1000001];

int binarySearch(int start, int end){
    
}

int solution(int n, int count){
    for(int i = 0; i < n; i++){
        //마지막에 붙이는 방식
        if(count == 0 || data[i] > lis[count - 1]){
            trace[data[i]] = count;
            lis[count++] = data[i];
        } else{
            //이진 탐색
            int start = 0, end = count;
            int index = count;
            while(start < end){
                int mid = (start + end) / 2;
                if(lis[mid] >= data[i]){
                    
                }
            }
        }
    }

    return trace[n];
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> data[i];

    solution(n, 0);
    return 0;
}