#include <iostream>
#include <memory.h>
using namespace std;
const int MOD = 1000000007;
int cache[101];

int tiling(int n){
  if(n <= 1) return 1;
  int & ret = cache[n];

  if(ret != -1) return ret;
  return ret = (tiling(n - 2) + tiling(n - 1)) % MOD;
}

int solution(int n){
  if(n % 2 == 1)
    return (tiling(n) - tiling(n / 2) + MOD) % MOD;

  int ret = tiling(n);
  ret = (ret - tiling(n / 2) + MOD) % MOD;
  ret = (ret - tiling(n / 2 - 1) + MOD) % MOD;

  return ret;
}

int main(){
  int c;
  cin >> c;

  while(c--){
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    cout << solution(n) << '\n';
  }
  return 0;
}