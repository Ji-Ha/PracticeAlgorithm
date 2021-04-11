#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(vector<string> lines){
    int answer = 0;
    vector<int> start, end;
    for(string str : lines){
        string hour = str.substr(11, 2);
        string min = str.substr(14, 2);
        string sec = str.substr(17, 2);
        string ms = str.substr(20, 3);

        int process = stof(str.substr(24, 5)) * 1000;

        int ih = stoi(hour) * 3600 * 1000;
        int im = stoi(min) * 60 * 1000;
        int is = stoi(sec) * 1000 + stoi(ms);
        start.push_back(ih + im + is - process + 1);
        end.push_back(ih + im + is);
    }

    for(int i = 0; i < lines.size(); i++){
        int limit = end[i] + 1000;
        int count = 0;

        for(int j = i; j < lines.size(); j++){
            if(start[j] < limit) count++;
        }
        if(answer < count) answer = count;
    }
    return answer;
}

int main(){

    return 0;
}