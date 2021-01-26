#include <iostream>
#include <algorithm>
using namespace std;
int triangle[100][100];
int result[100][100];
int n;

void init(){
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
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

    cout << solution(0, 0) << '\n';
  }
}