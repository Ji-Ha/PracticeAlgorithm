#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, s;
int sum[100], pSum[100];
int dp[100][10];
int value[100];

int score(int start, int end){
  int tmpSum = sum[end] - (start == 0 ? 0 : sum[start - 1]);
  int tmpPsum = pSum[end] - (start == 0 ? 0 : pSum[start - 1]);
  int m = int(0.5 + (double)tmpPsum / (end - start + 1));
  int res = tmpPsum - 2 * m * tmpPsum + m * m *(end - start + 1);
  return res;
}

void preInit(){
  memset(dp, -1, sizeof(dp));
  memset(sum, 0, sizeof(sum));
  memset(pSum, 0, sizeof(pSum));

  sort(value, value + n);
  sum[0] = value[0];
  pSum[0] = value[0] * value[0];

  for(int i = 1; i < n; i++){
    sum[i] = sum[i-1] + value[i];
    pSum[i] = pSum[i - 1] + (value[i] * value[i]);
  }
}

int solution(int start, int part){
  //정렬했을 때, 이미 value가 s개의 숫자로 표현이 가능할 때, == 기저사례
  if(start == n) return 0;
  if(part == 0) return 987654321;
  int& res = dp[start][part];
  if(res != -1) return res;
  res = 987654321;

  for(int i = 1; i + start <= n; i++){
    res = min(res, solution(start + i, part - 1) + score(start, start + i - 1));
  }

  return res;
}

int main(){
  int c;
  cin >> c;

  while(c--){
    cin >> n >> s;

    for(int i = 0; i < n; i++)
      cin >> value[i];
    
    preInit();
    cout <<solution(0, s) << '\n';
  }
  return 0;
}