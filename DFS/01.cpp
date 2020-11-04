#include <vector>

using namespace std;

//모든 경우를 확인해야하기 때문에, dfs활용.

void DFS(vector<int>& numbers, int& answer, int target, int count, int sum){
    if(count == numbers.size()){
        if(sum == target) answer++;
        return;
    }
    DFS(numbers, answer, target, count+1, sum + numbers[count]);
    DFS(numbers, answer, target, count+1, sum - numbers[count]);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, answer, target, 0, 0);
    return answer;
}