#include <iostream>
using namespace std;
int n, m;
double cache[1001][2010];

double solution(int distance, int days){
  if(days == m) return distance >= n ? 1 : 0;

  double& ret = cache[days][distance];
  if(ret != -1.0) return ret;

  ret = (solution(distance + 2, days + 1) * 0.75) + (solution(distance + 1, days + 1) * 0.25);
  return ret;
}

int main(){
  int c;
  cin >> c;

  while(c--){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m * 2 + 2; j++){
        cache[i][j] = -1.0;
      }
    }
    cout.precision(11);
    cout << solution(0, 0) << '\n';
  }
  return 0;
}