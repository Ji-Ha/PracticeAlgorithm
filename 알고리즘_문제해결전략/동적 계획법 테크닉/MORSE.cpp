#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

int bino[201][201];
const int MAX_VALUE = 1000000000 + 100;

void calcBino(){
  memset(bino, 0, sizeof(bino));

  for(int i = 0; i <= 200; i++){
    for(int j = 0; j <= i; j++){
      if(j == 0 || j == i){
        bino[i][j] = 1;
        continue;
      }
      bino[i][j] = min(MAX_VALUE, bino[i - 1][j - 1] + bino[i - 1][j]);
    }
  }
}

string kth(int n, int m, int skip){
  if(n == 0) return string(m, 'o');
  if(skip < bino[n + m - 1][n - 1]) return "-" + kth(n - 1, m, skip);

  skip -= bino[n + m - 1][n - 1];
  return "o" + kth(n, m - 1, skip);
}

int main(){
  int skip;
  int c;
  cin >> c;

  while(c--){
    int n, m, k;
    cin >> n >> m >> k;
    
    calcBino();
    skip = k - 1;
    cout << kth(n, m, skip) << '\n';
  }
  return 0;
}