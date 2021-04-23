#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    vector<int> ans;
    int answer = 0;
    
    while(n > 0){
        ans.push_back(n % 3);
        n = n / 3;
    }
    
    int three = pow(3, ans.size() - 1);
    
    for(int i = 0; i < ans.size(); i++){
        answer += ans[i] * three;
        three /= 3;
    }
    return answer;
}