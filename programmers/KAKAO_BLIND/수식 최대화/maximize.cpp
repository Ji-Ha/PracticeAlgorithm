#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long caclulation(long long a, long long b, char oper){
    if(oper == '-') return a - b;
    else if(oper == '*') return a * b;
    else if(oper == '+') return a + b;
}

long long solution(string expression){
    long long answer = 0;
    vector<char> operators_list = {'*', '+', '-'};
    vector<long long> nums;
    vector<char> operators;
    string num = "";

    for(int i = 0; i < expression.length(); i++){
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
            nums.push_back(stoi(num));
            num = "";
            operators.push_back(expression[i]);
        }
        else{
            num += expression[i];
        }
    }
    nums.push_back(stoi(num));

    do{    
        vector <long long> tempnums = nums;
        vector <char> tempoper = operators;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < tempoper.size(); j++){
                if(tempoper[j] == operators_list[i]){
                    tempnums[j] = caclulation(tempnums[j], tempnums[j + 1], operators_list[i]);
                    tempnums.erase(tempnums.begin() + j + 1);
                    tempoper.erase(tempoper.begin() + j);
                    j--;
                }
            }
        }
        if(abs(tempnums.front()) > answer) answer = abs(tempnums.front());
    }while(next_permutation(operators_list.begin(), operators_list.end()));

    return answer;
}

int main(){

    return 0;
}