#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//괜히 vector로 풀려다가 포기하고 이렇게...
//simple is best.
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int f = 0; int l = people.size()-1;
    
    while(f <= l){
        if(people[f] + people[l] <= limit){
            f++;
            l--;
            answer++;
        }
        else{
            l--;
            answer++;
        }
    }
    
    return answer;
}