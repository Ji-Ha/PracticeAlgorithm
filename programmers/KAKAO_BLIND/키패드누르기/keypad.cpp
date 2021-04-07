#include <string>
#include <vector>

using namespace std;
int keyboard[12][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}, {3, 0}, {3, 2}};

int distance(int location, int target){
    return abs(keyboard[location][0] - keyboard[target][0]) + abs(keyboard[location][1] - keyboard[target][1]);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10; // *
    int right = 11; // #
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            left = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            right = numbers[i];
        }
        else{
            int lefthand = distance(left, numbers[i]);
            int righthand = distance(right, numbers[i]);
            if(lefthand == righthand){
                if(!hand.compare("left")){
                    answer += "L";
                    left = numbers[i];
                }
                else{
                    answer += "R";
                    right = numbers[i];
                }
            }
            else if(lefthand < righthand){
                answer += "L";
                left = numbers[i];
            }
            else{
                answer += "R";
                right = numbers[i];
            }
        }
    }
    return answer;
}