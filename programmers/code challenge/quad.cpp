#include <string>
#include <vector>

using namespace std;
vector<vector<int>> a;
vector<int> ans;

int check(int y, int x, int length){
    int stat = a[y][x];
    for(int i = y; i < y + length; i++){
        for(int j = x; j < x + length; j++){
            if(stat != a[y][x]) return -1;
        }
    }
    return stat;
}

void block(int y, int x, int length){
    int checker = check(y, x, length);
    if(checker == -1){
        block()
    }
    ans.push_back(checker);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    a = arr;
    return answer;
}