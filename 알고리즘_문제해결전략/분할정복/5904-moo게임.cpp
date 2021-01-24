#include <iostream>
#include <string>
using namespace std;

long long mooLength[100];

char solution(long long n){
  if(n <= 3){
    if(n == 1) return 'm';
    return 'o';
  }

  long long count = 1;
  while(n > mooLength[count]){
    count++;
  }

  if(n <= mooLength[count] - mooLength[count - 1]){
    if(n - mooLength[count-1] == 1) return 'm';
    return 'o';
  }

  return solution(n - mooLength[count-1] - (count + 3));
}

int main(){
  long long n;
  cin >> n;
  mooLength[0] = 3;
  for(long long i = 1; i < 100; i++){
    mooLength[i] = (mooLength[i - 1] * 2) + (i + 3);
    if(mooLength[i] > 1e9) break;
  }
  cout << solution(n);
  return 0;
}