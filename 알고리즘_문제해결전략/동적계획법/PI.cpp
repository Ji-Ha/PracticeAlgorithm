#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
const int INF = 987654321;

string pi;
int cache[10000];

int difficulty(int start, int end){
  string target = pi.substr(start, end - start + 1);

  if(target == string(target.length(), target[0])) return 1;

  bool progressive = true;
  for(int i = 0; i < target.length()- 1; i++){
    if(target[i + 1] - target[i] != target[1] - target[0])
      progressive = false;
  }
  if(progressive && abs(target[1] - target[0]) == 1) return 2;

  bool alternating = true;
  for(int i = 0; i < target.length(); i++){
    if(target[i] != target[i%2])
      alternating = false;
  }
  if(alternating) return 4;
  if(progressive) return 5;
  return 10;
}

int solution(int start){
  //기저사례
  if(start == pi.length()) return 0;
  int& result = cache[start];
  //memoization
  if(result != 0) return result;

  result = INF;

  for(int l = 3; l <= 5; l++){
    if(start + l <= pi.length()){
      result = min(result, solution(start + l) + difficulty(start, start + l - 1));
    }
  }
return result;
}

int main(){
  int C;
  cin >> C;

  while(C--){
    memset(cache, 0, sizeof(cache));
    cin >> pi;
    cout << solution(0) << '\n';
  }
  return 0;
}