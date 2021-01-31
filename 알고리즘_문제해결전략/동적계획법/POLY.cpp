#include <iostream>
#include <memory.h>
using namespace std;
const int MOD = 10 * 1000 * 1000;
int cache[101][101];

// n과 0을 넣었을 때, 값이 모두 구해져 나와서, main문이 좀 더 깔끔해지지 않을까 생각해봤는데 그럴 수 없다.
// for문을 돌면서 cal이 0이 되는 지점이 있어서 값이 제대로 들어가지 않는다.
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