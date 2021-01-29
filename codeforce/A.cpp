#include <iostream>
#include <memory.h>
using namespace std;
int n;
int balls[100];
int cache[100];

bool check(){
  bool c = true;
  for(int i = 0; i < n; i++){
    if(cache[i] == 0) return c = false;
  }
  return c;
}

int solution(int color){
  int index;
  int ball;

  if(check()) return color - 1;
  
  for(int i = 0; i < n; i++){
    if(cache[i] == 0){
      cache[i] = color;
      index = i;
      ball = balls[i];
      break;
    } 
  }

  for(int i = index + 1; i < n; i++){
    if(balls[i] > ball) cache[i] = color;
  }
  return solution(color + 1);
}

int main(){
  int t;
  cin >> t;

  while(t--){
    memset(cache, 0, sizeof(cache));
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> balls[i];
    }
    cout << solution(1) << "\n";
  }
  return 0;
}