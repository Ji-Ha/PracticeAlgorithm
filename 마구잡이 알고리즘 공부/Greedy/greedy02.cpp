#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int count = 0;
    vector <char> v;
    
    v.push_back(number.at(0));
    //치고 빠지기 할거임. 앞에서부터.
    for(int i = 1; i<number.length();i++){
        //지금 들어가는 게, 앞에 들어 갔던 거 보다 크니? 작으면 다 빼버려.
        char now = number.at(i);
        char before = v.back();
        while(before < now && v.size() > 0 && count < k){
            v.pop_back();
            before = v.back();
            count++;
        }
        v.push_back(now);
    }
    while(k > count){
        v.pop_back();
        count++;
    }
    
    for(int i = 0; i<v.size();i++)
        answer += v[i];
    return answer;
}