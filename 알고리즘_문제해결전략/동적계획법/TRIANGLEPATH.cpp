#include <iostream>
#include <algorithm>
using namespace std;
int triangle[100][100];
int result[100][100];
int countCache[100][100];
int n;

void init(){
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      countCache[i][j] = -1;
      triangle[i][j] = 0;
      result[i][j] = 0;
    }
  }
}

int solution(int y, int x){
  if(y == n - 1) return triangle[y][x];
  int& res = result[y][x];

  if(res != 0) return res;

  return res = max(solution(y + 1, x), solution(y + 1, x + 1)) + triangle[y][x];
}

int count(int y, int x){
  if(y == n - 1) return 1;

  int& ret = countCache[y][x];
  if(ret != -1) return ret;
  
  ret = 0;
  if(solution(y + 1, x + 1) >= solution(y + 1, x)) ret += count(y + 1, x + 1);
  if(solution(y + 1, x + 1) <= solution(y + 1, x)) ret += count(y + 1, x);
  return ret;
}

int main(){
  int C;
  cin >> C;

  while(C--){
    cin >> n;

    init();
    for(int i = 0; i < n; i++){
      for(int j = 0; j <= i; j++)
        cin >> triangle[i][j];
    }

    cout << count(0, 0) << '\n';
  }
}