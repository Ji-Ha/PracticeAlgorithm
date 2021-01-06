#include <algorithm>
#include <vector>
//입국심사!
using namespace std;

long long solution(int n, vector<int> times) {

    long long answer = 0;
    long long minTime = 1, maxTime = 0, avgTime = 0, count = 0;
    
    maxTime = *max_element(times.begin(), times.end()) * (long long)n;
    
    while(minTime<=maxTime){
        avgTime = (minTime + maxTime) /2;
        
        for(auto time : times) 
            count += avgTime/time;
        
        if(n <= count){
            answer = avgTime;
            maxTime = avgTime-1;
        }
        else
            minTime = avgTime+1;
        
        count = 0;
    }
    
    return answer;
}