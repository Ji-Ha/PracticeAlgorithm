#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;


vector<int> solution(vector<string> gems){
    vector<int> answer = {0, 0};
    queue<string> q;
    map<string, int> m;
    int gem_size = 0, start = 0, end = 100001, point = 0;
    
    for(auto i : gems)
        m[i] = 1;
    
    gem_size = m.size();
    m.clear();

    for(int i = 0; i < gems.size(); i++){
        if(m[gems[i]] == 0)
            m[gems[i]] = 1;
        else
            m[gems[i]]++;
        q.push(gems[i]);

        while(1){
            if(m[q.front()] > 1){
                m[q.front()] -= 1;
                q.pop();
                point++;
            }
            else
                break;
        }

        if(m.size() == gem_size && end > q.size()){
            end = q.size();
            start = point;
        }
    }

    answer[0] = start + 1;
    answer[1] = start + end;
    return answer;
}

int main(){
    vector<string> a = {"AA", "AB", "AC", "AA", "AC"};

    for(int a : solution(a)){
        cout << a << ' ';
    }
    return 0;
}