#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    int onboard = routes[0][1];
    for(int i = 1; i<routes.size();i++){
        if(onboard < routes[i][0]){
            answer++;
            onboard = routes[i][1];
        }
        if(onboard >= routes[i][1])
            onboard = routes[i][1];
        
    }
    return answer;
}