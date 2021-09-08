#include <vector>
#include <algorithm>
#include <string>
//프로그래머스 DFS/BFS 단어 변환
using namespace std;

vector<int> res;

bool cmp(string a, string b){
    int check = 0;
    for(int i = 0 ; i<a.length();i++){
        if(a[i] != b[i])
            check++;
    }
    if(check == 1)
        return true;
    return false;
}

void dfs(string begin, string target, vector<string> words, vector<bool>& check, int count){
     
    if(begin == target){
        res.push_back(count);
        return;
    }

    for(int i = 0; i<words.size();i++){
        if(check[i] == false&&cmp(begin, words[i]) == true){
            check[i] = true;
            dfs(words[i], target, words, check, count+1);
            check[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> check(words.size(),false);
    
    bool checker = false;
    for(int i = 0; i<words.size();i++){
        if(words[i] == target){
            checker = true;
            break;
        }
    }
    if (checker == false)
        return 0;
    
    dfs(begin, target, words, check, 0);
    sort(res.begin(), res.end(), greater<int>());
    answer = res.back();
    return answer;
}