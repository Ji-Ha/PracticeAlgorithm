#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int cnt[27];
unordered_map<string, int> check;
vector<string> menu[27][21];

void comb(string s, int idx, string made){
    if(made.size() > 1){
        check[made]++;
        cnt[made.size()]=max(cnt[made.size()], check[made]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(string& s : orders){
        sort(s.begin(), s.end());
    }
    return answer;
}

int main(){
    vector<string> s;
    vector<int> c;

    for(int i = 0; i < 6; i++){
        string temp;
        cin >> temp;
        s.push_back(temp);
    }

    for(int i = 0; i < 3; i++){
        int temp;
        cin >> temp;
        c.push_back(temp);
    }

    solution(s, c);
    return 0;
}