#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool find(char element, vector<string> board){
    for(string line : board){
        if(line.find(element) != string::npos){
            return true;
        }
    }
    return false;
    
}

void remover(char element){

}

void run(int m, int n, vector<string> *board, vector<char> *value){
    int size = value->size();
    while(value->size() > 0){
        if(value->size() == size){
            break;
        }
        size = value->size();
        for(int i = 0; i<value->size(); i++){
          remover(value[i]);
        }
    }
}


vector<char> setValue(int m, int n, vector<string> board){
    vector<char> value;
    for(string line : board){
        for(char element : line){
            if(element != '.' && element != '*'){
                value.push_back(element);
            }
        }
    }
    
    sort(value.begin(), value.end());
    value.erase(unique(value.begin(), value.end()), value.end());
    return value;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<char> value = setValue(m, n, board);
    
    run(m, n, &board, &value);
    return answer;
}

int main(){
  solution(3, 3, {"DBA", "C*A", "CDB"});
}