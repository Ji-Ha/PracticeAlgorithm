#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> ans;
    vector<int> dknow;
    int top, bot = 0;
    int zcount = 0;
    
    for(int i = 0; i < lottos.size(); i++)
        if(lottos[i] == 0) zcount++;
    
    for(int i = 0; i <win_nums.size(); i++){
        auto check = find(lottos.begin(), lottos.end(), win_nums[i]);
        if(check != lottos.end()) bot++;
        else{
            dknow.push_back(win_nums[i]);
        }
    }
    
    if(zcount < dknow.size()) top = bot + zcount;
    else top = bot + dknow.size();
    answer.push_back(top);
    answer.push_back(bot);
    for(int i = 0; i < answer.size(); i++){
        if(answer[i] == 6) ans.push_back(1);
        if(answer[i] == 5) ans.push_back(2);
        if(answer[i] == 4) ans.push_back(3);
        if(answer[i] == 3) ans.push_back(4);
        if(answer[i] == 2) ans.push_back(5);
        if(answer[i] <= 1) ans.push_back(6);    
    }
    
    
    return ans;
}