#include <iostream>
#include <memory.h>
using namespace std;
const int MOD = 1000000007;
int cache[101];

int solution(int n){
  if(n <= 1) return 1;
  int & ret = cache[n];

  if(ret != -1) return ret;
  return ret = (solution(n - 2) + solution(n - 1)) % MOD;
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