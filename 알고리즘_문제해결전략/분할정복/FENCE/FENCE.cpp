#include <iostream>
#include <algorithm>
using namespace std;

int fence[20001];

int solution(int left, int right){
  if(left == right) return fence[left];

  int mid = (left + right) / 2;
  int result = max(solution(left, mid), solution(mid + 1, right));
  
  int low = mid;
  int high = mid + 1;
  int height = min(fence[low], fence[high]);

  result = max(result, height * 2);

  while(left < low || high < right){
    if(high < right && (low == left || fence[low - 1] < fence[high + 1])){
      ++high;
      height = min(height, fence[high]);
    }
    else {
      --low;
      height = min(height, fence[low]);
    }

    result = max(result, height * (high - low + 1));
  }
  return result;
}

int main(){
  int testCase;
  cin >> testCase;

  for(int t = 0; t < testCase; t++){
    int fenceNumber;
    cin >> fenceNumber;

    for(int i = 0; i < fenceNumber; i++){
      int height;
      cin >> height;
      fence[i] = height;
    }

    cout << solution(0, fenceNumber-1) << '\n';
    
  }

  return 0;
}