#include <vector>

using namespace std;

int solution(vector<int> a) {
    vector<int> left(a.size());
    vector<int> right(a.size());
    int answer = 0;
    
    int Min = a[0];
    
    for(int i = 0; i < a.size(); i++){
        if(Min > a[i]) Min = a[i];
        left[i] = Min;
    }
    
    Min = a[a.size() - 1];
    for(int i = a.size() - 1; i >= 0 ; i--){
        if(Min > a[i]) Min = a[i];
        right[i] = Min;
    }
    
    for(int i = 0; i < a.size(); i++){
        if(a[i] <= left[i] || a[i] <= right[i]) answer++;
    }
    return answer;
}