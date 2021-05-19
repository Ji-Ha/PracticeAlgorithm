#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0; i < numbers.size(); i++){
        long long number = numbers[i];
        if(number % 2 == 0) answer.push_back(number + 1);
        else{
            unsigned long long last = ~number & (number + 1);
            answer.push_back((number | last) & ~(last >> 1));
        }
    }
    return answer;
}