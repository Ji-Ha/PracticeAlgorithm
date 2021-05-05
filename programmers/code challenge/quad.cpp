#include <string>
#include <vector>

using namespace std;
vector<vector<int>> temp;
vector<int> answer;

bool check(int y, int x, int length){
    bool checker = true;
    int target = temp[y][x];
    for(int i = y; i < y + length; i++){
        for(int j = x; j < x + length; j++){
            if(temp[i][j] != target){
                return checker = false;
            }
        }
    }
    return checker;
}

void block(int y, int x, int length){
    if(check(y, x, length)) answer.push_back(temp[y][x]);
    else{
        int y_mid = y + (length / 2);
        int x_mid = x + (length / 2);
        block(y, x, length / 2);
        block(y, x_mid, length / 2);
        block(y_mid, x, length / 2);
        block(y_mid, x_mid, length/ 2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> ans;
    temp = arr;
    block(0, 0, arr.size());
    int one = 0;
    int zero = 0;
    
    for(int i = 0 ; i < answer.size(); i++){
        if(answer[i] == 1) one++;
        else zero++;
    }
    ans.push_back(zero);
    ans.push_back(one);
    
    return ans;
}