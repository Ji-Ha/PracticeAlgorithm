#include <iostream>
#include <memory.h>
using namespace std;
const int MOD = 10 * 1000 * 1000;
int cache[101][101];

int solution(int n, int first){
  if(n == first) return 1;
  
  int& val = cache[n][first];

  if(val != -1) return val;

  val = 0;
  for(int i = 1; i <= n - first; i++){
    int cal = i + first - 1;
    cal *= solution(n - first, i);
    cal %= MOD;
    val += cal;
    val %= MOD;
  }
  return val;
}

int main(){
  int c;
  cin >> c;

  while(c--){
    memset(cache, -1, sizeof(cache));
    int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			ans += solution(n, i);
			ans %= MOD;
		}
		cout << ans << "\n";
  }

  return 0;
}