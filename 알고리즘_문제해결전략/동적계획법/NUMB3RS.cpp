#include <iostream>
#include <cstring>
using namespace std;
double cache[51][101];
int connected[51][51];
int deg[51];
int n, d, p, q;

double solution(int day, int vill){
  if(day == 0) return vill == p ? 1.0 : 0.0;

  double& res = cache[vill][day];
  if(res > -0.5) return res;
  res = 0.0;

  for(int there = 0; there < n; there++){
    if(connected[vill][there])
      res += solution(day - 1, there) / deg[there];
  }
  return res;
}

int main(){
  int c;
  cin >> c;

  while (c--){
    memset(cache, -1, sizeof(cache));
    memset(deg, 0, sizeof(deg));

    cin >> n >> d >> p;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        cin >> connected[i][j];
        deg[i] += connected[i][j];
      }
    }
    cin >> q;
    for (int i = 0; i < q; i++){
      int v;
      cin >> v;
      cout << solution(d, v) << ' ';
    }
    cout << '\n';
  }
  return 0;
}