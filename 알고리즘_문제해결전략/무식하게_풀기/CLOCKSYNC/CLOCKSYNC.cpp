#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 9999;
const int SWITCH = 10;
const int CLOCKS = 16;

int linked[SWITCH][CLOCKS] = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

void click(vector<int> &clock, int swch){
  for(int i = 0; i < CLOCKS; i++){
    if(linked[swch][i] == 1)
      clock[i] += 3;
    
    if(clock[i] == 15)
      clock[i] = 3;
  }
}

bool areAligned(vector<int> &clock){
  for(int i = 0; i < CLOCKS; i++){
    if(clock[i] != 12)
      return false;
  }
  return true;
}

int solution(vector<int> &clock, int swch){
  if(swch == SWITCH) return areAligned(clock) ? 0 : INF;
  int result = INF;
  for(int i = 0; i < 4; i++){
    result = min(result, i + solution(clock, swch + 1));
    click(clock, swch);
  }
  return result;
}

int main(){
  int testCase = 0;
  cin >> testCase;

  for(int t = 0; t < testCase; t++){
    vector<int> clock(CLOCKS, 0);
    for(int i = 0; i<CLOCKS; i++){
      cin >> clock[i];
    }
    int answer = solution(clock, 0);
    if(answer == INF)
      cout << -1 << endl;
    if(answer != INF)
      cout << answer << endl;
  }
  return 0;
}