#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const long long NEGINF = numeric_limits<long long>::min();
int n, m, a[100], b[100];
int cache[101][101];

int jlis(int indexA, int indexB){
  int& ret = cache[indexA + 1][indexB + 1];
  if(ret != -1) return ret;

  long long aa = (indexA == -1 ? NEGINF : a[indexA]);
  long long bb = (indexB == -1 ? NEGINF : b[indexB]);
  long long maxElement = max(aa, bb);

  ret = 0;
  
  for(int nextA = indexA + 1; nextA < n; nextA++){
    if(maxElement < a[nextA])
      ret = max(ret, jlis(nextA, indexB) + 1);
  }

  for(int nextB = indexB + 1; nextB < m; nextB++){
    if(maxElement < b[nextB])
      ret = max(ret, jlis(indexA, nextB) + 1);
  }
  return ret;
}

int main(){
  int C;
  cin >> C;
  while(C--){
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;

    for(int i = 0; i < n; i++)
      cin >> a[i];
    
    for(int j = 0; j < m; j++)
      cin >> b[j];

    cout << jlis(-1, -1) << '\n';
  }
  return 0;
}