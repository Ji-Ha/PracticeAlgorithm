#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(int num){
    if(num == 1) return true;
    for(int i = 2; i <= 32; i++)
        if(num / i == i && num % i == 0) return true;
    return false;
}

int solution(int left, int right) {
    int limit = 32;
    int answer x= 0;
    
    for(int i = left; i <= right; i++){
        if(check(i)) answer-= i;
        else answer += i;
    }
    return answer;
}