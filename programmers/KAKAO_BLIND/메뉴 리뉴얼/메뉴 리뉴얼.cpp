#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int cnt[27];
unordered_map<string, int> um;
vector<string> menu[27][21];

void comb(string s, int idx, string made){
    if(made.size() > 1){
        um[made]++;
        cnt[made.size()] = max(cnt[made.size()], um[made]);
        menu[made.size()][um[made]].push_back(made);
    }
    
    for(int i = idx + 1; i < s.size(); i++){
        made.push_back(s[i]);
        comb(s, i, made);
        made.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(string& s : orders){
        sort(s.begin(), s.end());
        comb(s, -1, "");
    }
    
    for(int i : course){
        if(cnt[i] > 1){
            for(string s : menu[i][cnt[i]])
                answer.push_back(s);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}